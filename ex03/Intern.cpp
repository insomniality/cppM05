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

AForm* Intern::makeForm(std::string nameOfForm)
{
	///TODO: petqa New-ov sargem?
	AForm* retr = NULL;
	if (nameOfForm == "PresidentialPardonForm")
	{
		retr = new PresidentialPardonForm("Ban");
	}
	// if (nameOfForm == "RobotomyRequestForm")
	// {
	// 	retr = &(RobotomyRequestForm x(targetOfForm));
	// }
	// if (nameOfForm == "ShrubberyCreationForm")
	// {
	// 	retr = &(ShrubberyCreationForm x(targetOfForm));
	// }
	// else
	// 	throw ();
	std::cout << "Intern creates " << nameOfForm << std::endl;
	return (retr);
}