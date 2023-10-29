#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Your Grade Is Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Your Grade Is Too Low");
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cerr << "Bureaucrat " << name << " couldn't sign form because " << ex.what() << "\n";
	}
}

std::string	Bureaucrat::getName()	const
{
	return(this->name);
}

int	Bureaucrat::getGrade()	const
{
	return(this->grade);
}

void Bureaucrat::gradeDecrement()
{
	if (this->grade >= 150)
		throw (GradeTooLowException());
	this->grade++;
}

void Bureaucrat::gradeIncrement()
{
	if (this->grade <= 1)
		throw (GradeTooHighException());
	this->grade--;
}


//----


Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string& str, int n) : name(str)
{
	std::cout << "Bureaucrat parametric constructor called\n";
	if (n < 1)
		throw (GradeTooHighException());
	if (n > 150)
		throw (GradeTooLowException());
	grade = n;
}


Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.getName())
{
	std::cout << "Bureaucrat copy constructor called\n";
	this->grade = obj.getGrade();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj) // : name(obj.getName()) // i can't change name coz it's already initalized, right?
{
	if (this == &obj)
		return (*this);	
	std::cout << "Bureaucrat copy assigment(\"=\") operator called\n";
	this->grade = obj.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}


//----

std::ostream& operator<<(std::ostream& strm, const Bureaucrat& obj)
{
	// std::cout << this->name << ", bureaucrat grade" << this->grade ".\n";
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (strm);
}

void	Bureaucrat::signForm(AForm& obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << this->name << " signed " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn’t sign " << obj.getName() << " because " << e.what() << std::endl;
	}
}