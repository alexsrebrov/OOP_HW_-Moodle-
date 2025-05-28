#include "User.h"
#include <iostream>
//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

size_t User::idMaker = 100;
User::User(const String& name, const String& password)
{
	this->name = name;
	this->password = password;
	userId = idMaker++;
}

User::User(const String& name, const String& password, size_t id)
{
	this->name = name;
	this->password = password;
	userId = id;
	if(id) idMaker = id+1;
}


void User::changePassword(const String& newPass)
{
	password = newPass;
	std::cout << "Password changed succesfully\n";
}

size_t User::getID() const
{
	return userId;
}

const String& User::getName() const
{
	return name;
}

const String& User::getPass() const
{
	return password;
}


