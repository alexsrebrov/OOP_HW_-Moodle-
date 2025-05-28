#include "AssignHWCommand.h"
#include<iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void AssignHWCommand::execute(const String& input, UserDB& users, MailDB& mail, 
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String courseName, assignmentName;
	input.split(courseName, assignmentName,' ');
	try
	{
		courses.addAssignment(courseName, assignmentName);
		std::cout << "Succesfully created a new assignment!\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return;
	}
}
