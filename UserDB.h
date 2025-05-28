#pragma once
#include "UserCollection.h"
#include "UserFactory.h"
#include "UsersSerializer.h"
#include <iostream>


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class UserDB
{
public:
	UserDB();
	void addUser(UserType userType, const String& name, const String& pass);
	void addUser(UserType userType, const String& name, const String& pass,size_t id);
	void changePassword(const String& oldPass, const String& newPass, size_t id);
	void removeUser(size_t id);
	const User* validateLogin(size_t id, const String& password) const;
	size_t getCurrAddedId()const;
	~UserDB();

	bool validateId(size_t userId) const;

private:
	UserCollection users;
	UserFactory* factory;
	UsersSerializer* serializer;
	void load();
	void save() const;
};

