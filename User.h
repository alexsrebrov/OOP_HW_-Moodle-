#pragma once
#include "String.h"


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


enum class UserType
{
	Admin,Teacher,Student
};

class User
{
public:
	User(const String& name,const String& password);
	User(const String& name,const String& password,size_t id);
	virtual ~User() = default;

	void changePassword(const String& newPass);

	size_t getID() const;
	const String& getName() const;
	const String& getPass() const;

	virtual User* clone() const = 0;
	virtual void serialize(std::ofstream& os) const = 0;
	virtual User* deserialize(std::ifstream& ifs) const = 0;
	virtual UserType getUserType() const = 0;

private:
	String name;
	String password;
	size_t userId;
	static size_t idMaker;
};

