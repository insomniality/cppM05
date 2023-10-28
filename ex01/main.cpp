#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat z("Aper", 150);
		Form form("dzuk", 145, 123);

		z.signForm(form);

		std::cout << z << "\n";
		z.gradeDecrement();
		std::cout << z << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}