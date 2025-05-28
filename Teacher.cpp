#include "Teacher.h"
#include <iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

Teacher::Teacher(const String& name,const String& password)
 : User(name, password) { }

Teacher::Teacher(const String& name, const String& password, size_t id)
 :User(name,password,id) {}

User* Teacher::clone() const
{
	return new Teacher(*this);
}

void Teacher::serialize(std::ofstream& ofs) const
{
	UserType type = getUserType();
	String name = this->getName();
	String pass = this->getPass();
	size_t id = this->getID();
	ofs.write((const char*)&type, sizeof(UserType));
	ofs.write((const char*)&name, sizeof(String));
	ofs.write((const char*)&pass, sizeof(String));
	ofs.write((const char*)&id, sizeof(size_t));
}

User* Teacher::deserialize(std::ifstream& ifs) const
{
	UserType type;
	String name, pass;
	size_t id;
	ifs.read((char*)&type, sizeof(UserType));
	ifs.read((char*)&name, sizeof(String));
	ifs.read((char*)&pass, sizeof(String));
	ifs.read((char*)&id, sizeof(size_t));
	return new Teacher(name, pass);
}

UserType Teacher::getUserType() const
{
	return UserType::Teacher;
}

