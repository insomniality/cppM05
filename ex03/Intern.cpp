#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& obj)
{
	(void) obj;
}

// Intern& Intern::operator=(const Intern& obj)
// {
// 	(void) obj;
// 	return this;
// }

Intern::~Intern()
{

}


const char* Intern::NameNotReal::what() const throw()
{
	return ("Name doesn't exist\n");
}


AForm* Intern::makeForm(std::string nameOfForm, std::string targetOfForm)
{
	///TODO: petqa New-ov sargem?
	AForm* retr = NULL;
	if (nameOfForm == "PresidentialPardonForm")
	{
		retr = new PresidentialPardonForm(targetOfForm);
	}
	if (nameOfForm == "RobotomyRequestForm")
	{
		retr = new RobotomyRequestForm(targetOfForm);
	}
	if (nameOfForm == "ShrubberyCreationForm")
	{
		retr = new ShrubberyCreationForm(targetOfForm);
	}
	else
		throw (NameNotReal());
	///TODO:: catch stegh grem te urish tegh?
	std::cout << "Intern creates " << nameOfForm << std::endl;
	return (retr);
}