#include "MessageStudentsCommand.h"
#include <iostream>


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


void MessageStudentsCommand::execute(const String& input, UserDB& users, MailDB& mail,
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String courseName, message;
	input.split(courseName, message,' ');
	MyVector<size_t> recievers = courses.getUsersIds(courseName);
	for (size_t i = 0; i < recievers.getSize(); i++)
	{
		mail.message(currUser->getName(), recievers[i], message);
	}
}
