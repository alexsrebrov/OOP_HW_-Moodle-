#include "GradesCommand.h"
#include <iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void GradesCommand::execute(const String& input, UserDB& users, MailDB& mail,
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	grades.printGrades(currUser->getID());
	std::cout << std::endl;
}
