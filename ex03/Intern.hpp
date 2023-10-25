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
		AForm* makeForm(std::string nameOfForm);
};
