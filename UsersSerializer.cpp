#include "UsersSerializer.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void UsersSerializer::writeToFile(const UserCollection& users) const
{
	std::ofstream os(usersFileName, std::ios::out | std::ios::binary);
	if (!os.is_open()) throw std::runtime_error("Couldn't open file!");
	size_t size = users.getUsersSize();
	size_t ids;
	UserType types;
	os.write((const char*)&size, sizeof(size_t));
	for (size_t i = 0; i < size; i++)
	{
		types = users[i]->getUserType();
		os.write((const char*)&types, sizeof(UserType));
		users[i]->getName().serialize(os);
		users[i]->getPass().serialize(os);
		ids = users[i]->getID();
		os.write((const char*)&ids, sizeof(size_t));
	}
	os.close();
}

void UsersSerializer::readFromFile(UserCollection& users) const
{
	std::ifstream ifs(usersFileName, std::ios::in | std::ios::binary);
	if (!ifs.is_open()) throw std::runtime_error("Couldn't open file!");
	size_t size=0;
	ifs.read((char*)&size, sizeof(size_t));
	UserType userType;
	String name, pass;
	size_t id = 0;
	for (size_t i = 0; i < size; i++)
	{
		ifs.read((char*)&userType, sizeof(UserType));
		name.deserialize(ifs);
		pass.deserialize(ifs);
		ifs.read((char*)&id, sizeof(size_t));
		users.addUser(factory->createUser(userType,name,pass,id));
	}
	ifs.close();
}
