#include "AddTeacherCommand.h"
#include <iostream>


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


void AddTeacherCommand::execute(const String& input, UserDB& users, MailDB& mail, 
	CourseDB& courses, GradeDB& grades,const User* currUser) const
{
	String firstname, surname, pass, surnameAndPass;
	input.split(firstname, surnameAndPass,' ');
	surnameAndPass.split(surname, pass,' ');
	try
	{
		users.addUser(UserType::Teacher, firstname + " " + surname, pass);
		mail.addMail(users.getCurrAddedId());
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return;
	}
}
