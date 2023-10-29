#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"

///TODO: READ Proffesional C++ from [250 - 282] Chapter 8 (Then chapter 5)
///TODO: Read chapter 14 for exceptions, and page 69, 129

class AForm;

class Bureaucrat
{
	public:
		void	executeForm(AForm const &form); /** TODO: oka? vor AForm em sarqel Form-i tegh@? **/
		std::string	getName()	const;
		int			getGrade()	const;
		void		gradeIncrement(); // tars en ashxatelu
		void		gradeDecrement();
		void		signForm(AForm& obj);
	public:
			Bureaucrat();
			Bureaucrat(const std::string&, int);
			Bureaucrat(const Bureaucrat&);
Bureaucrat&	operator=(const Bureaucrat&);
// a = b <=> a.operator=(b)
			~Bureaucrat();
	private:
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
		const std::string		name;
		int						grade;
};

std::ostream& operator<<(std::ostream& strm, const Bureaucrat&);
// ostream << b <=> ostream.operator<<(b) // mikana entadrum
#endif