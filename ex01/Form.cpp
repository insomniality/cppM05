#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Your Grade Is Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Your Grade Is Too Low");
}

void Form::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() <= this->gradeToSign)
		this->signature = SIGNED;
	else
		throw (GradeTooLowException());
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSignature() const
{
	return (this->signature);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->gradeToExec);
}

// 

Form::Form() : name("Frisk"), gradeToSign(1), gradeToExec(1)
{
	this->signature = UNSIGNED;
}

Form::Form(const std::string & name, const int gToSign, const int gToExec) : name(name), gradeToSign(gToSign), gradeToExec(gToExec)
{
	if (gToSign < 1 || gToExec < 1)
		throw (GradeTooHighException());
	if (gToSign > 150 || gToExec > 150)
		throw (GradeTooLowException());

	this->signature = UNSIGNED;
}

Form::Form(const int gToSign, const int gToExec) : name("Frisk"), gradeToSign(gToSign), gradeToExec(gToExec)
{
	if (gToSign < 1 || gToExec < 1)
		throw (GradeTooHighException());
	if (gToSign > 150 || gToExec > 150)
		throw (GradeTooLowException());

	this->signature = UNSIGNED;
}

Form::Form(const Form& obj) : name(obj.name), gradeToSign(obj.gradeToSign), gradeToExec(obj.gradeToExec)
{
	this->signature = obj.signature;
}

Form&	Form::operator=(const Form& obj)
{
	if (this == &obj)
		return (*this);
	this->signature = obj.signature;
	return (*this);
}

Form::~Form()
{

}

//

std::ostream& operator<<(std::ostream& stream, const Form& obj)
{
	std::cout << obj.getName() << ", form grade to sign is " << obj.getGradeToSign() << "form grade to exec is " << obj.getGradeToExec() << ".\n";
	return (stream);
}
