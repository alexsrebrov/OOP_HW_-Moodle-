#pragma once
#include "UserDB.h"
#include "MailDB.h"
#include "GradeDB.h"
#include "CourseDB.h"
#include "Command.h"
#include "CommandFactory.h"


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

class SystemDB
{
public:
	void execute(const String& cmd,const String& input,const User* user);
	const User* getUser(const String& userIDAsStr,const String& pass) const;

private:
	Command* cmd = nullptr;
	UserDB users;
	MailDB mails;
	GradeDB grades;
	CourseDB courses;
};

