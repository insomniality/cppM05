#include "AForm.hpp"
#include <fstream>


void treeMaster(std::string target, int height)
{
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
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}