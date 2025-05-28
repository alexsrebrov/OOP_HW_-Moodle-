#include "MessageCommand.h"
#include <iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


void MessageCommand::execute(const String& input, UserDB& users, MailDB& mail,
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String recieverIdAsStr, content;
	input.split(recieverIdAsStr, content,' ');
	if (!recieverIdAsStr.isNum())
	{
		std::cout << "Invalid Id";
		return;
	}
	size_t recieverId = atoi(recieverIdAsStr.c_string());
	mail.message(currUser->getName(),recieverId,content);
}
