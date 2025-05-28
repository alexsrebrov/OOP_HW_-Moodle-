#pragma once
#include "String.h"
#include "MyVector.hpp"
#include "Answer.h"


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class Assignment
{
public:
	Assignment() = default;
	Assignment(const String& name);

	void addAnswer(const Answer& add);
	void printAllAnsewrs() const;
	size_t getUserId(size_t answeId) const;
	const String& getAssignmentName() const;

	void serialize(std::ofstream& ofs) const;
	void deserialize(std::ifstream& ifs);


private:
	String asssignmentName;
	MyVector<Answer> answers;
};


