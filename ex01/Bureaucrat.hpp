#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Form;

///TODO: READ Proffesional C++ from [250 - 282] Chapter 8 (Then chapter 5)
///TODO: Read chapter 14 for exceptions, and page 69, 420

class Bureaucrat
{
	public:
		std::string	getName()	const;
		int			getGrade()	const;
		void		gradeIncrement(); // tars en ashxatelu
		void		gradeDecrement();
		void		signForm(Form& obj);
	public:
			Bureaucrat();
			Bureaucrat(const std::string&, int);
			Bureaucrat(const Bureaucrat&);
			Bureaucrat&	operator=(const Bureaucrat&);
			~Bureaucrat();
	private:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
	private:
		const std::string		name;
		int						grade;
};

std::ostream& operator<<(std::ostream& strm, const Bureaucrat&);

#endif
