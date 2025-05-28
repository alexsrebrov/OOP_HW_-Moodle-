#include "UserDB.h"
#include <iostream>


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void UserDB::load()
{
	serializer->readFromFile(users);
}

void UserDB::save() const
{
	serializer->writeToFile(users);
}

UserDB::UserDB() :
   factory(new UserFactory),
   serializer(new UsersSerializer) 
{
	load();
	printAllUsersInfo();
}


void UserDB::addUser(UserType userType,const String& name,const String& pass)
{
	users.addUser(factory->createUser(userType,name,pass));

	switch (userType)
	{
	case UserType::Student:
		std::cout<<"Added student ";
		break;
	case UserType::Teacher:
		std::cout<<"Added teacher ";
		break;
	}
	User* currUser = users[users.getUsersSize() - 1];
	std::cout << currUser->getName() << " with ID " << currUser->getID() << "!\n";
}

void UserDB::addUser(UserType userType, const String& name, const String& pass, size_t id)
{
	try
	{
		users.addUser(factory->createUser(userType, name, pass,id));
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return;
	}
}

void UserDB::changePassword(const String& oldPass, const String& newPass, size_t id)
{
	for (size_t i = 0; i < users.getUsersSize(); i++)
	{
		if (users[i]->getID() == id && users[i]->getPass() == oldPass)
		{
			users[i]->changePassword(newPass);
		}
	}
}

void UserDB::removeUser(size_t id)
{
	users.removeUser(id);
}


const User* UserDB::validateLogin(size_t id, const String& password) const
{
	return users.validLogin(id, password);
}

size_t UserDB::getCurrAddedId() const
{
	return users[users.getUsersSize() - 1]->getID();;
}

UserDB::~UserDB()
{
	printAllUsersInfo();
	save();
	delete factory;
	delete serializer;
}

bool UserDB::validateId(size_t userId) const
{
	for (size_t i = 0; i < users.getUsersSize(); i++)
	{
		if (users[i]->getID() == userId) return true;
	}
	return false;
}
