#include "ViewSubmissionsCommand.h"
#include <iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void ViewSubmissiosCommand::execute(const String& input, UserDB& users, MailDB& mail,
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String courseName, assignmentName;
	input.split(courseName, assignmentName,' ');
	courses.printAssignmentAnswers(courseName, assignmentName);
}
