#include "AForm.hpp"

void AForm::beSigned(const Bureaucrat& obj)
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

bool	AForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->signature == SIGNED && executor.getGrade() <= this->gradeToSign)
			throw (this->low);
		return (true);
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what();
		return (false);
	}
}


//

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
