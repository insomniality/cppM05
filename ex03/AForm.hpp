#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define UNSIGNED false
# define SIGNED true

class Bureaucrat;

class AForm
{
	public:
		std::string getName() const; // now class is abstract
		virtual void	execute(Bureaucrat const &executor) const = 0;
		bool	getSignature() const;
		int		getGradeToSign() const;
		int		getGradeToExec() const;
		virtual void	beSigned(const Bureaucrat&) = 0;
	
	protected:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw(); // virtual?? // staticic gjvuma -_-
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw(); // virtual?? // staticic gjvuma -_-
		};

		class NotSigned : public std::exception
		{
			public:
				const char* what() const throw(); // virtual?? // staticic gjvuma -_-
		};
	public:
		AForm();
		AForm(const AForm& obj);
		AForm(const int gToSign, const int gToExec);
		AForm& operator=(const AForm& obj);
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
		void	execute(Bureaucrat const &executor) const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		// ShrubberyCreationForm(const int gToSign, const int gToExec);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();
		void	beSigned(const Bureaucrat&);
	private:
		std::string target;
		const std::string name;
		bool signature; // = unsigned
		const int gradeToSign; // 145
		const int gradeToExec; // 137
};

class RobotomyRequestForm : public AForm
{
	public:
		void	execute(Bureaucrat const &executor) const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		// RobotomyRequestForm(const int gToSign, const int gToExec);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();
		void	beSigned(const Bureaucrat&);
	private:
		std::string target;
		const std::string name;
		bool signature; // = unsigned
		const int gradeToSign;
		const int gradeToExec;
};

class PresidentialPardonForm : public AForm
{
	public:
		void	execute(Bureaucrat const &executor) const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		// PresidentialPardonForm(const int gToSign, const int gToExec);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& obj);
		~PresidentialPardonForm();
		void	beSigned(const Bureaucrat&);
	private:
		std::string target;
		const std::string name;
		bool signature; // = unsigned
		const int gradeToSign;
		const int gradeToExec;
};


#endif