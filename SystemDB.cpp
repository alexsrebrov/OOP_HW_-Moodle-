#include "SystemDB.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void SystemDB::execute(const String& command,const String& input,const User* user)
{
	CommandFactory factory;
	cmd = factory.getCommand(command,user);
	cmd->execute(input, users, mails, courses, grades, user);
}

const User* SystemDB::getUser(const String& userIDAsStr, const String& pass) const
{
	if (!userIDAsStr.isNum()) throw std::runtime_error("Ivalid id");
	size_t userId = atoi(userIDAsStr.c_string());
	return users.validateLogin(userId, pass);
}
