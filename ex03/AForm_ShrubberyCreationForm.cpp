#include "AForm.hpp"
#include <fstream>

//

ShrubberyCreationForm::ShrubberyCreationForm() :target ("default"),  name("default"), signature(UNSIGNED), gradeToSign(145), gradeToExec(137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :target (target),  name("default"), signature(UNSIGNED), gradeToSign(145), gradeToExec(137)
{

}

void ShrubberyCreationForm::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() <= this->gradeToSign)
		this->signature = SIGNED;
	else
		throw (GradeTooLowException());
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const 
{
	if (this->signature != SIGNED)
		throw (NotSigned());
	if (executor.getGrade() > this->gradeToExec)
		throw (GradeTooLowException());

	int height = target.length() + 1;

	std::ofstream nya(target + ".txt");
	for (int i = 1; i < height; i++)
	{
		for (int j = 0; j < height - i; j++)
			nya << " ";
		for (int j = 0; j < i; j++)
			nya << "* ";
		for (int j = 0; j < height - i; j++)
			nya << " ";
		nya << "\n";
	}
	nya.close();
} 

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) \
: name(obj.getName()), signature(obj.getSignature()), gradeToSign(obj.getGradeToSign()), gradeToExec(obj.getGradeToExec())
{

}



ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this == &obj)
		return (*this);
	this->signature = obj.getSignature();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}