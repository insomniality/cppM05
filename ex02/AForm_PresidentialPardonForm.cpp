#include "AForm.hpp"
#include <fstream>

std::string PresidentialPardonForm::getName() const
{
	return (this->name);
}

//

PresidentialPardonForm::PresidentialPardonForm() : name("default"), signature(UNSIGNED), gradeToSign(25), gradeToExec(5)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : name("default"), signature(UNSIGNED), gradeToSign(25), gradeToExec(5)
{
	std::cout << target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) \
: name(obj.getName()), signature(getSignature()), gradeToSign(getGradeToSign()), gradeToExec(getGradeToExec())
{

}



PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this == &obj)
		return (*this);
	this->signature = obj.getSignature();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}