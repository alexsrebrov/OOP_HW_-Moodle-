#include "CreateCourseCommand.h"
#include <iostream>


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void CreateCourseCommand::execute(const String& input, UserDB& users, MailDB& mail, 
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String courseName, pass;
	input.split(courseName, pass,' ');
	
	courses.addCourse(Course(courseName, pass));
}
