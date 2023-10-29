#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Your Grade Is Too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Your Grade Is Too Low");
}

const char* AForm::NotSigned::what() const throw()
{
	return ("Not signed");
}

void AForm::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() <= this->gradeToSign)
		this->signature = SIGNED;
	else
		throw (GradeTooLowException());
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->signature != SIGNED)
		throw (NotSigned());
	if (executor.getGrade() > this->gradeToExec)
		throw (GradeTooLowException());
	///TODO: hmi execute gri?? miat kjoges
	//eeee
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSignature() const
{
	return (this->signature);
}

int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (this->gradeToExec);
}

// 

AForm::AForm() : name("Frisk"), gradeToSign(0), gradeToExec(0)
{
	this->signature = UNSIGNED;
}

AForm::AForm(const int gToSign, const int gToExec) : name("Frisk"), gradeToSign(gToSign), gradeToExec(gToExec)
{
	this->signature = UNSIGNED;
}

AForm::AForm(const AForm& obj) : name(obj.name), gradeToSign(obj.gradeToSign), gradeToExec(obj.gradeToExec)
{
	this->signature = obj.signature;
}

AForm&	AForm::operator=(const AForm& obj)
{
	if (this == &obj)
		return (*this);
	this->signature = obj.signature;
	return (*this);
}

AForm::~AForm()
{

}

//

std::ostream& operator<<(std::ostream& stream, const AForm& obj)
{
	std::cout << obj.getName() << ", form grade to sign is " << obj.getGradeToSign() << "form grade to exec is " << obj.getGradeToExec() << ".\n";
	return (stream);
}
