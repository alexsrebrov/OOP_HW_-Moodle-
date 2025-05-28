#include "UserFactory.h"
#include <iostream>


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


User* UserFactory::createUser(UserType userType,const String& name,const String& pass)  
{  
	if (userType == UserType::Admin)
	{
		return new Admin();
	}
	if (userType == UserType::Teacher) return new Teacher(name, pass);
	return new Student(name, pass);
}

User* UserFactory::createUser(UserType userType, const String& name, const String& pass, size_t id)
{
	if (userType == UserType::Admin)
	{
		if (id) throw std::runtime_error("Invalid ID for admin!");
		return new Admin(name,pass,id);
	}
	if (userType == UserType::Teacher) return new Teacher(name, pass,id);
	return new Student(name, pass,id);
}

UserType UserFactory::getUserType(std::istream& is)
{
	UserType res;
	is.read((char*)&res, sizeof(UserType));
	return res;
}
