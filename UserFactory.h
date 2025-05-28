#pragma once
#include "User.h"
#include "Teacher.h"
#include "Student.h"
#include "Admin.h"


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class UserFactory
{
public:
	User* createUser(UserType userType,const String& name,const String& pass);
	User* createUser(UserType userType,const String& name,const String& pass,size_t id);
	UserType getUserType(std::istream& is);
};

