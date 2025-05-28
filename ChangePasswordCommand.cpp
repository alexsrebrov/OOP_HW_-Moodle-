#include "ChangePasswordCommand.h"
#include <iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void ChangePasswordCommand::execute(const String& input, UserDB& users, MailDB& mail, 
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String oldPass, newPass;
	input.split(oldPass, newPass,' ');
	try
	{
		users.changePassword(oldPass, newPass, currUser->getID());
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return;
	}
}
