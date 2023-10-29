#include "AForm.hpp"
#include <fstream>
//

PresidentialPardonForm::PresidentialPardonForm() :target ("default"), name("default"), signature(UNSIGNED), gradeToSign(25), gradeToExec(5)
{

}
void PresidentialPardonForm::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() <= this->gradeToSign)
		this->signature = SIGNED;
	else
		throw (GradeTooLowException());
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) :target (target), name("default"), signature(UNSIGNED), gradeToSign(25), gradeToExec(5)
{
	
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const 
{
	if (this->signature != SIGNED)
		throw (NotSigned());
	if (executor.getGrade() > this->gradeToExec)
		throw (GradeTooLowException());

	std::cout << target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
	// int height = target.length() + 1;

	// std::ofstream nya(target + ".txt");
	// for (int i = 1; i < height; i++)
	// {
	// 	for (int j = 0; j < height - i; j++)
	// 		nya << " ";
	// 	for (int j = 0; j < i; j++)
	// 		nya << "* ";
	// 	for (int j = 0; j < height - i; j++)
	// 		nya << " ";
	// 	nya << "\n";
	// }
	// nya.close();
} 

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) \
: name(obj.getName()), signature(obj.getSignature()), gradeToSign(obj.getGradeToSign()), gradeToExec(obj.getGradeToExec())
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