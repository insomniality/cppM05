#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Mika", 1);

	try
	{
		a.gradeIncrement();

		std::cout << a << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << a << "\n";
}
