#pragma once
#include "User.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class UserCollection
{
public:
	UserCollection();
	UserCollection(const UserCollection& other);
	UserCollection& operator=(const UserCollection& other);
	UserCollection(UserCollection&& other) noexcept;
	UserCollection& operator=(UserCollection&& other) noexcept;
	~UserCollection();

	const size_t getUsersSize() const;
	void addUser(User* add);
	void removeUser(size_t userId);
	void changePassword(size_t userId,const String& oldPass, const String& newPassword);
	const User* validLogin(size_t id, const String& pass) const;

	const User* operator[](size_t index) const;
	User* operator[](size_t index);

private:
	User** users;
	size_t capacity;
	size_t size;

	void free();
	void copyFrom(const UserCollection& other);
	void moveFrom(UserCollection&& other);
	void resize(size_t newCap);
	size_t findIndexById(size_t id) const;
	bool empty() const;
};

