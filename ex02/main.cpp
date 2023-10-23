#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	try
	{
		a.execute(zz);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}