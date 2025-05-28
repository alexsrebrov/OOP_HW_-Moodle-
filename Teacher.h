#pragma once
#include "User.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa



class Teacher : public User
{
public:
	Teacher(const String& name,const String& password);
	Teacher(const String& name,const String& password,size_t id);
	~Teacher() override = default;

	User* clone()const override;
	void serialize(std::ofstream& ofs) const override;
	User* deserialize(std::ifstream& ifs) const override;
	UserType getUserType() const override;
};

