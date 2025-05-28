#include "GradeAssignmentCommand.h"
#include <iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


void GradeAssignmentCommand::execute(const String& input, UserDB& users, MailDB& mail, 
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String courseName, assignmentName, answerIdAsStr, gradeAsStr, note;
	String helper;
	input.split(courseName, helper,' ');
	helper.split(assignmentName, helper,' ');
	helper.split(answerIdAsStr, helper,' ');
	if (!answerIdAsStr.isNum()) 
	{
		std::cout << "AnswerId is not valid!";
		return;
	}
	size_t answerId = atoi(answerIdAsStr.c_string());
	helper.split(gradeAsStr, note,' ');
	String wholeNum, decNum;
	gradeAsStr.split(wholeNum, decNum, '.');
	if (!wholeNum.isNum() || !decNum.isNum())
	{
		std::cout << "invalid grade";
	}
	size_t userID = courses.getUserIdByAnswerId(courseName, assignmentName, answerId);
	double grade = atoi(wholeNum.c_string());
	grade += ((atoi(decNum.c_string())) / decNum.getLen()+1);
	grades.addGrade(Grade(courseName, assignmentName, grade, note), userID);
}
