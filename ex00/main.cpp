#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Mika", 151);
	Bureaucrat z("Aper", 150);
	z << z;
	z.gradeDecrement();
	z << z; // karam exeption-i mej exit-i pes ban avelacnem vor prtsni tsragir@
}