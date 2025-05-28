#include "AddStudentCommand.h"
#include <iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


void AddStudentCommand::execute(const String& input, UserDB& users,MailDB& mail,
	 CourseDB& courses, GradeDB& grades,const User* currUser)const
{
	String firstname, surname, pass,surnameAndPass;
	input.split(firstname, surnameAndPass,' ');
	surnameAndPass.split(surname, pass,' ');
	try
	{
		users.addUser(UserType::Student, firstname + " " + surname, pass);
		grades.addUser(users.getCurrAddedId());
		mail.addMail(users.getCurrAddedId());
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return;
	}
}
