#include "Bureaucrat.hpp"

// std::exception a;

class myExeption : public std::exception
{
	public:
		const char* what() const throw(); // virtual?? // staticic gjvuma -_-
};

const char* myExeption::what() const throw()
{
	return ("You are wrong");
}


Bureaucrat::Bureaucrat(const std::string& str, int n)
{
	try
	{
		str.size();
		// this->name = str;
		this->grade = n;
		myExeption a;

		if (this->grade > 150)
			throw (a);
		if (this->grade < 1)
			throw (a);
	}
	catch (std::exception& a)
	{
		std::cerr << a.what();
	}	
}

Bureaucrat::~Bureaucrat()
{
	
}