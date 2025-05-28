#include "EnrollCommand.h"
#include<iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


void EnrollCommand::execute(const String& input, UserDB& users, MailDB& mail,
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String courseName, pass;
	input.split(courseName, pass,' ');
	if (!courses.validateCourseInfo(courseName, pass))
	{
		std::cout << "Invalid password!";
		return;
	}
	courses.addUser(courseName, currUser->getID());
}
