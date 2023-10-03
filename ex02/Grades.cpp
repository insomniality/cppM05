#include "Grades.hpp"

const char* GradeTooHighException::GradeTooHighException::what() const throw()
{
	return ("Your Grade Is Too High Exception\n");
}

const char* GradeTooLowException::GradeTooLowException::what() const throw()
{
	return ("Your Grade Is Too Low Exception\n");
}
