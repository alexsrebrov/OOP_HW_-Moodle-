#include "AddToCourseCommand.h"
#include <iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void AddToCourseCommand::execute(const String& input, UserDB& users, MailDB& mail, 
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String courseName, userIDAsStr;
	input.split(courseName, userIDAsStr,' ');
	if (!userIDAsStr.isNum())
	{
		std::cout << "Invalid user id!\n";
		return;
	}
	size_t userId = atoi(userIDAsStr.c_string());
	if (!users.validateId(userId))
	{
		std::cout << "User id isn't valid'\n";
		return;
	}
	try
	{
		courses.addUser(courseName, userId);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what()<<std::endl;
		return;
	}
}
