#pragma once
#include "UserCollection.h"
#include"UserFactory.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class UsersSerializer
{
public:
	void writeToFile(const UserCollection& users) const;
	void readFromFile(UserCollection& users) const;

private:
	static constexpr char usersFileName[] = "1HWUsersDB.dat";
	UserFactory* factory;
};

