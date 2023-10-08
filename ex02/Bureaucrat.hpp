#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Grades.hpp"
#include "Form.hpp"

///TODO: READ Proffesional C++ from [250 - 282] Chapter 8 (Then chapter 5)
///TODO: Read chapter 14 for exceptions, and page 69, 129

class Bureaucrat
{
	public:
		std::string	getName()	const;
		int			getGrade()	const;
		void		gradeIncrement(); // tars en ashxatelu
		void		gradeDecrement();
		void		signForm(const Form& obj);
	public:
			Bureaucrat();
			Bureaucrat(const std::string&, int);
			Bureaucrat(const Bureaucrat&);
Bureaucrat&	operator=(const Bureaucrat&);
// a = b <=> a.operator=(b)
			~Bureaucrat();
	public:
		GradeTooLowException	low;
		GradeTooHighException	high;
	private:
		const std::string		name;
		int						grade;
};

std::ostream& operator<<(std::ostream& strm, const Bureaucrat&);
// ostream << b <=> ostream.operator<<(b) // mikana entadrum
#endif