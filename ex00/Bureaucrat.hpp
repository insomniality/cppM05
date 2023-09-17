#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	public:
		std::string& getName()	const;
		int& getGrade()	const;
		void gradeIncrement(); // tars en ashxatelu
		void gradeDecrement();

	Bureaucrat();
	Bureaucrat(Bureaucrat& const);
Bureaucrat	operator=(Bureaucrat& const);
	~Bureaucrat();
	private:
		const std::string	name;
		int					grade;

};

#endif 