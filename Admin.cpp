#include "Admin.h"


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

Admin::Admin()
 : User("admin","0000",0) { }

Admin::Admin(const String& name, const String& pass, size_t id)
 : User(name,pass,id){}

User* Admin::clone() const
{
	return nullptr;
}

void Admin::serialize(std::ofstream& ofs) const
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

User* Admin::deserialize(std::ifstream& ifs) const
{
	UserType type;
	String name, pass;
	size_t id;
	ifs.read((char*)&type, sizeof(UserType));
	ifs.read((char*)&name, sizeof(String));
	ifs.read((char*)&pass, sizeof(String));
	ifs.read((char*)&id, sizeof(size_t));
	return new Admin();
}

UserType Admin::getUserType() const
{
	return UserType::Admin;
}