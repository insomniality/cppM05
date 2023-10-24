#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Grades.hpp"
#include "Bureaucrat.hpp"

#define UNSIGNED false
#define SIGNED true

class Form
{
	public:
		std::string getName() const;
		bool getSignature() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(const Bureaucrat&);
	public:
		Form();
		Form(const Form& obj);
		Form(const int gToSign, const int gToExec);
Form&	operator=(const Form& obj);
		~Form();
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
	private:
		const std::string name;
		bool signature; // = unsigned
		const int gradeToSign;
		const int gradeToExec;	
};

std::ostream& operator<<(std::ostream& stream, const Form& obj);

#endif