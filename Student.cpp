#include "Student.h"
#include <iostream>
//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


Student::Student(const String& name, const String& password)
	: User(name, password) {
}

Student::Student(const String& name, const String& password, size_t id)
	:User(name, password, id) {
}

User* Student::clone() const
{
	return new Student(*this);
}

void Student::serialize(std::ofstream& ofs) const
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

User* Student::deserialize(std::ifstream& ifs) const
{
	UserType type;
	String name, pass;
	size_t id;
	ifs.read((char*)&type, sizeof(UserType));
	ifs.read((char*)&name, sizeof(String));
	ifs.read((char*)&pass, sizeof(String));
	ifs.read((char*)&id, sizeof(size_t));
	return new Student(name, pass);
}

UserType Student::getUserType() const
{
	return UserType::Student;
}

