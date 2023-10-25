#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	// Bureaucrat a("Mika", 151);
	// Bureaucrat z("Aper", 150);
	// std::cout << z;
	// z.gradeDecrement();
	// std::cout << z; // karam exeption-i mej exit-i pes ban avelacnem vor prtsni tsragir@

	ShrubberyCreationForm a("akshgdasgdjhagskdhgaskdjgaksjdgkajsgdkajsgdkjasggdkjasgdkjagskdjgaksd");
	
	RobotomyRequestForm x("jaaa");

	RobotomyRequestForm v("vii");

	PresidentialPardonForm g("PREZ");

	Bureaucrat zz;
	Intern gago;
	gago.makeForm("PresidentialPardonForm");
	try
	{
		a.execute(zz);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}