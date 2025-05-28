#pragma once
#include "Command.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class ViewSubmissiosCommand: public Command
{
public:
	void execute(const String& input, UserDB& users, MailDB& mail,
		CourseDB& courses, GradeDB& grades,const User* currUser) const override;
};


