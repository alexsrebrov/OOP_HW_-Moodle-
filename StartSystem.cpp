#include "StartSystem.h"
#include <iostream>
#include <fstream>


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


static constexpr size_t bufferLen = 1024;

void clearDB()
{
	std::ofstream ofs1("1HWMailDb.dat", std::ios::binary | std::ios::out);
	size_t size = 0;
	ofs1.write((const char*)&size, sizeof(size_t));
	ofs1.close();

	std::ofstream ofs2("1HWCoursesDb.dat", std::ios::binary | std::ios::out);
	size = 0;
	ofs2.write((const char*)&size, sizeof(size_t));
	ofs2.close();

	std::ofstream ofs3("1HWGradesDb.dat", std::ios::binary | std::ios::out);
	size = 0;
	ofs3.write((const char*)&size, sizeof(size_t));
	ofs3.close();

	std::ofstream ofs("1HWUsersDb.dat", std::ios::binary | std::ios::out);
	size = 1;
	ofs.write((const char*)&size, sizeof(size_t));
	UserType a = UserType::Admin;
	String name = "admin";
	String pass = "0000";
	size_t id = 0;
	ofs.write((const char*)&a, sizeof(UserType));
	name.serialize(ofs);
	pass.serialize(ofs);
	ofs.write((const char*)&id, sizeof(size_t));
}


void start()
{
	char buff[bufferLen + 1];
	SystemDB system;
	std::cout << "> ";
	std::cin.getline(buff, bufferLen + 1, '\n');
	String line, cmd, input;
	bool isLogged = false;
	const User* user = nullptr;
	while (strcmp(buff, "logout"))
	{
		line = buff;
		line.split(cmd, input, ' ');
		if (cmd == "login" && !isLogged)
		{
			try
			{
				String userId, pass;
				input.split(userId, pass, ' ');
				user = system.getUser(userId, pass);
				isLogged = true;
				std::cout << "Login succesfull!\n";
				if (user->getUserType() != UserType::Admin)
				{
					String userType;
					if (user->getUserType() == UserType::Teacher) userType = "Teacher";
					else userType = "Strudent";
					std::cout << user->getName() << " | " << userType << " | " << user->getID() << '\n';
				}
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else if (isLogged)
		{
			if (!user) continue;
			try
			{
				system.execute(cmd, input, user);
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		std::cin.clear();
		std::cout << "> ";
		std::cin.getline(buff, bufferLen + 1, '\n');
	}
}