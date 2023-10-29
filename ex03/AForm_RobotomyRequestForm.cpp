#include "AForm.hpp"
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <fstream>

#include <ctime>

// #include <random>

//

RobotomyRequestForm::RobotomyRequestForm() : target ("default"), name("default"), signature(UNSIGNED), gradeToSign(72), gradeToExec(45)
{

}

void RobotomyRequestForm::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() <= this->gradeToSign)
		this->signature = SIGNED;
	else
		throw (GradeTooLowException());
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const 
{
	if (this->signature != SIGNED)
		throw (NotSigned());
	if (executor.getGrade() > this->gradeToExec)
		throw (GradeTooLowException());

	srand(time(NULL));
	int a = rand();

	std::cout << "*Drilling noises*" << std::endl;
	usleep(500 * 1000);
	if (a % 2 == 0)
		std::cout << target + " has been robotomized successfully" << std::endl;
	else
		std::cout << target + "s robotomy failed" << std::endl;
} 

RobotomyRequestForm::RobotomyRequestForm(std::string target) : target (target), name("default"), signature(UNSIGNED), gradeToSign(72), gradeToExec(45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: name(obj.getName()), signature(obj.getSignature()), gradeToSign(obj.getGradeToSign()), gradeToExec(obj.getGradeToExec())
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