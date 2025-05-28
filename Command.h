#pragma once
#include "String.h"
#include "UserDB.h"
#include "MailDB.h"
#include "CourseDB.h"
#include "GradeDB.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

class Command
{
public:
	virtual void execute(const String& input, UserDB& users, MailDB& mail,
		CourseDB& courses, GradeDB& grades,const User* currUser) const = 0;
	virtual ~Command() = default;
};

