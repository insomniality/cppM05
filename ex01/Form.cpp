#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Your Grade Is Too High Exception\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Your Grade Is Too Low Exception\n");
}

void Form::beSigned(const Bureaucrat& obj)
{
	try
	{
		if (obj.getGrade() <= this->gradeToSign)
			this->signature = SIGNED;
		else
			throw (this->low);
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what();
	}

}

//

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

Form::Form() : name("Frisk"), gradeToSign(0), gradeToExec(0)
{
	this->signature = UNSIGNED;
}

Form::Form(const int gToSign, const int gToExec) : name("Frisk"), gradeToSign(gToSign), gradeToExec(gToExec)
{
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
