#include "UserCollection.h"
#include <iostream>


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void UserCollection::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete users[i];
	}
	delete users;
}

void UserCollection::copyFrom(const UserCollection& other)
{
	capacity = other.capacity;
	size = other.size;
	if (size >= capacity) capacity = size;
	users = new User * [capacity];
	for (size_t i = 0; i < size; i++)
	{
		users[i] = other.users[i]->clone();
	}
}

void UserCollection::moveFrom(UserCollection&& other)
{
	capacity = other.capacity;
	size = other.size;
	users = other.users;
	other.users = nullptr;
}

void UserCollection::resize(size_t newCap)
{
	if (newCap <= capacity) newCap = capacity * 2;
	User** res = new User * [newCap];
	for (size_t i = 0; i < capacity; i++)
	{
		res[i] = users[i]->clone();
		delete users[i];
	}
	delete[]users;
	users = res;
	capacity = newCap;
}

size_t UserCollection::findIndexById(size_t id) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (users[i]->getID() == id) return i;
	}
	throw std::runtime_error("Invalid ID\n");
}

UserCollection::UserCollection()
{
	size = 0;
	capacity = 10;
	users = new User * [capacity];
}

UserCollection::UserCollection(const UserCollection& other)
{
	copyFrom(other);
}

UserCollection& UserCollection::operator=(const UserCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

UserCollection::UserCollection(UserCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

UserCollection& UserCollection::operator=(UserCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

UserCollection::~UserCollection()
{
	free();
}

const size_t UserCollection::getUsersSize() const
{
	return size;
}

void UserCollection::addUser(User* add)
{
	if (size >= capacity) resize(capacity * 2);
	users[size++] = add;
}

void UserCollection::removeUser(size_t userId)
{
	if (empty()) return;
	try
	{
		size_t idx = findIndexById(userId);
		std::swap(users[idx], users[size]);
		delete users[--size];
		std::cout << "Remove user with ID " << userId;
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what();
		return;
	}
}

void UserCollection::changePassword(size_t userId,const String& oldPass, const String& newPassword)
{
	try
	{
		if (!validLogin(userId, oldPass))
		{
			std::cout << "Wrong password!";
			return;
		}
		users[findIndexById(userId)]->changePassword(newPassword);
		std::cout << "Password changed successfuly!";
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what();
		return;
	}
}

bool UserCollection::empty() const
{
	return size;
}

const User* UserCollection::validLogin(size_t id, const String& pass) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (users[i]->getID() == id && users[i]->getPass() == pass) return users[i];
	}
	throw std::runtime_error("User not found!");
}

const User* UserCollection::operator[](size_t index) const
{
	return users[index];
}

User* UserCollection::operator[](size_t index)
{
	return users[index];
}


