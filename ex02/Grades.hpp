#ifndef GRADES_HPP
# define GRADES_HPP

#include <iostream>

class GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw(); // virtual?? // staticic gjvuma -_-
};

class GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw(); // virtual?? // staticic gjvuma -_-
};

#endif