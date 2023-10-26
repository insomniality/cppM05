#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		~Intern();
	public:
		class NameNotReal : public std::exception
		{
			public:
				const char* what() const throw(); // virtual?? // staticic gjvuma -_-
		};
	public:
		AForm* makeForm(std::string nameOfForm, std::string targetOfForm);
};
