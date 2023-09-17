#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

///TODO: READ Proffesional C++ from [250 - 282] Chapter 8 (Then chapter 5)
///TODO: Read chapter 14 for exceptions, and page 69, 129

class Bureaucrat
{
	public:
		std::string getName()	const;
		int getGrade()	const;
		void gradeIncrement(); // tars en ashxatelu
		void gradeDecrement();
	
	public:
			Bureaucrat();
			Bureaucrat(const std::string&, int);
			Bureaucrat(const Bureaucrat&);
Bureaucrat&	operator=(const Bureaucrat&);
// a = b <=> a.operator=(b)
			~Bureaucrat();
	
	private:
		const std::string	name;
		int					grade;

};

#endif 