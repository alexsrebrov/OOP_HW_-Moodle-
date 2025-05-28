#include "SubmiitAssignmentCommand.h"
#include <iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void SubmitAssignmentCommand::execute(const String& input, UserDB& users, MailDB& mail,
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String courseName, assignmentName,helper,answer;
	input.split(courseName, helper,' ');
	helper.split(assignmentName, answer,' ');
	courses.addAnswer(courseName, assignmentName, currUser->getID(), currUser->getName(), answer);
}
