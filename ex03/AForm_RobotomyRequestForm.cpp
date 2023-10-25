#include "AForm.hpp"
#include <cstdlib>
#include <time.h>
#include <fstream>

#include <ctime>

// #include <random>

std::string RobotomyRequestForm::getName() const
{
	return (this->name);
}

//

RobotomyRequestForm::RobotomyRequestForm() : name("default"), signature(UNSIGNED), gradeToSign(72), gradeToExec(45)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : name("default"), signature(UNSIGNED), gradeToSign(72), gradeToExec(45)
{
	int a = rand();
	srand(time(NULL));
	a = a + rand();
	std::cout << "*Drilling noises*" << std::endl;
	if (a % 2 == 0)
		std::cout << target + " has been robotomized successfully" << std::endl;
	else
		std::cout << target + "s robotomy failed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) \
: name(obj.getName()), signature(getSignature()), gradeToSign(getGradeToSign()), gradeToExec(getGradeToExec())
{

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this == &obj)
		return (*this);
	this->signature = obj.getSignature();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}