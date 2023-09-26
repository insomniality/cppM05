#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Grades.hpp"
#include "Bureaucrat.hpp"

#define unsigned false
#define signed true

class Form
{
	public:
		std::string getName() const;
		bool getSignature() const;
		int getgGradeToSign() const;
		int getgGradeToExec() const;
		void beSigned(const Bureaucrat&);
	public:
		GradeTooLowException	low;
		GradeTooHighException	high;
	public:
		Form();
		Form(const Form& obj);
Form&	operator+(const Form& obj);
		~Form();
	private:
		const std::string name;
		bool signature; // = unsigned
		const int gradeToSign;
		const int gradeToExec;	
};

std::ostream& operator<<(std::ostream& stream, const Form& obj);

#endif