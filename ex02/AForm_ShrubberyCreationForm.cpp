#include "AForm.hpp"

void treeMaster(std::string target)
{

}

//

ShrubberyCreationForm::ShrubberyCreationForm() : name("default"), signature(UNSIGNED), gradeToSign(145), gradeToExec(137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) \
: name(obj.getName()), signature(getSignature()), gradeToSign(getGradeToSign()), gradeToExec(getGradeToExec())
{

}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this == &obj)
		return (*this);
	this->signature = obj.getSignature();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}