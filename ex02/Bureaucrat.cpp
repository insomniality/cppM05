#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Your Grade Is Too High Exception\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Your Grade Is Too Low Exception\n");
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
		std::cerr << ex.what();
		// std::cout << "Error" << std::endl;
		// return ;
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
	try
	{
		this->grade++;
		if (this->grade > 150)
			throw (GradeTooLowException());
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what();
	}
}

void Bureaucrat::gradeIncrement()
{
	try
	{
		this->grade--;
		if (this->grade < 1)
			throw (GradeTooHighException());
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what();
	}
}


//----


Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string& str, int n) : name(str), grade(n)
{
	try
	{
		std::cout << "Bureaucrat parametric constructor called\n";
		if (this->grade < 1)
			throw (GradeTooHighException());
		if (this->grade > 150)
			throw (GradeTooLowException());
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what();
	}	
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
	std::cout << "Bureaucrat insertion assigment(\"<<\") operator called\n";
	// std::cout << this->name << ", bureaucrat grade" << this->grade ".\n";
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
	return (strm);
}

void	Bureaucrat::signForm(const AForm& obj)
{
	if (obj.getSignature() == SIGNED)
		std::cout << this->name << " signed " << obj.getName() << std::endl;
	else
		std::cout << this->name << " couldn’t sign " << obj.getName() << " because grade is to low" << std::endl;
}
