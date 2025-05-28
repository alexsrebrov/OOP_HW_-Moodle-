#pragma once
#include "User.h"


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

class Admin : public User
{
public:
	Admin();
	Admin(const String& name,const String& pass,size_t id);
	~Admin() override = default;

	User* clone()const override;
	void serialize(std::ofstream& ofs) const override;
	User* deserialize(std::ifstream& ifs) const override;
	UserType getUserType() const override;
};

