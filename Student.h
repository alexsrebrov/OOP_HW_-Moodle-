#pragma once
#include "User.h"


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class Student : public User
{
public:
	Student(const String& name, const String& password);
	Student(const String& name, const String& password, size_t id);
	~Student() override = default;

	User* clone()const override;
	void serialize(std::ofstream& ofs) const override;
	User* deserialize(std::ifstream& ifs) const override;
	UserType getUserType() const override;
};

