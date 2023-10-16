#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Grades.hpp"
#include "Bureaucrat.hpp"

#define UNSIGNED false
#define SIGNED true

class Bureaucrat;


class AForm
{
	public:
		virtual std::string getName() const = 0; // now class is abstract
		bool getSignature() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(const Bureaucrat&);

	public:
		GradeTooLowException	low;
		GradeTooHighException	high;
	public:
		AForm();
		AForm(const AForm& obj);
		AForm(const int gToSign, const int gToExec);
AForm&	operator=(const AForm& obj);
		~AForm();

	private:
		const std::string name;
		bool signature; // = unsigned
		const int gradeToSign;
		const int gradeToExec;
};

std::ostream& operator<<(std::ostream& stream, const AForm& obj);

class ShrubberyCreationForm : public AForm
{
	public:
		void treeMaster(std::string target);
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		// ShrubberyCreationForm(const int gToSign, const int gToExec);
ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();
	
	private:
		const std::string name;
		bool signature; // = unsigned
		const int gradeToSign; // 145
		const int gradeToExec; // 137
};

#endif