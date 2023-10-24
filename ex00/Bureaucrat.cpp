#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Your Grade Is Too High Exception\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Your Grade Is Too Low Exception\n");
}


const char* Bureaucrat::what() const throw()
{
	return ("Your Grade Is Too High Exception\n");
}

const char* Bureaucrat::what() const throw()
{
	return ("Your Grade Is Too Low Exception\n");
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
			throw (this->low);
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
			throw (this->high);
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
			throw (this->high);
		if (this->grade > 150)
			throw (this->low);
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what();
	}	
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.getName())
{
	std::cout << "Bureaucrat copy constructor called\n";
	// bayc ha vor? arji es taki 2 hat@?
	this->low = obj.low;
	this->high = obj.high;
	this->grade = obj.getGrade();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj) // : name(obj.getName()) // i can't change name coz it's already initalized, right?
{
	if (this == &obj)
		return (*this);	
	std::cout << "Bureaucrat copy assigment(\"=\") operator called\n";
	this->low = obj.low;
	this->high = obj.high;
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