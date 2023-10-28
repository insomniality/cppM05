#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Your Grade Is Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Your Grade Is Too Low");
}

std::string	Bureaucrat::getName() const
{
	return(this->name);
}

int	Bureaucrat::getGrade() const
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
	// bayc ha vor? arji es taki 2 hat@?
	this->grade = obj.getGrade();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj)
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
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (strm);
}
