#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Grades.hpp"
#include "Bureaucrat.hpp"

#define UNSIGNED false
#define SIGNED true

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

#endif