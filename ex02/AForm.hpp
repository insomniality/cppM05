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
		void	executeForm(Form const &form);
		void	execute(Bureaucrat const &executor) const;
		bool	getSignature() const;
		int		getGradeToSign() const;
		int		getGradeToExec() const;
		void	beSigned(const Bureaucrat&);
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
		std::string getName() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
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

class RobotomyRequestForm : public AForm
{
	public:
		std::string getName() const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		// RobotomyRequestForm(const int gToSign, const int gToExec);
RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();
	
	private:
		const std::string name;
		bool signature; // = unsigned
		const int gradeToSign;
		const int gradeToExec;
};

class PresidentialPardonForm : public AForm
{
	public:
		std::string getName() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		// PresidentialPardonForm(const int gToSign, const int gToExec);
PresidentialPardonForm&	operator=(const PresidentialPardonForm& obj);
		~PresidentialPardonForm();
	
	private:
		const std::string name;
		bool signature; // = unsigned
		const int gradeToSign;
		const int gradeToExec;
};


#endif