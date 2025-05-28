#include "Assignment.h"


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


Assignment::Assignment(const String& name) : answers()
{
	asssignmentName = name;
}

void Assignment::addAnswer(const Answer& add)
{
	answers.add(add);
}

size_t Assignment::getUserId(size_t answeId) const
{
	for (size_t i = 0; i < answers.getSize(); i++)
	{
		if (answeId == answers[i].getAnswerID()) return answers[i].getStudentID();
	}
	throw std::runtime_error("Cannot get user ID!");
}

const String& Assignment::getAssignmentName() const
{
	return asssignmentName;
}

void Assignment::serialize(std::ofstream& ofs) const
{
	asssignmentName.serialize(ofs);
	size_t size = answers.getSize();
	ofs.write((const char*)&size, sizeof(size_t));
	for (size_t i = 0; i < size; i++)
	{
		answers[i].serialize(ofs);
	}
}

void Assignment::deserialize(std::ifstream& ifs)
{
	asssignmentName.deserialize(ifs);
	size_t size = 0;
	ifs.read((char*)&size, sizeof(size_t));
	if (answers.getCapacity() <= size) answers.setCapacity(size);
	for (size_t i = 0; i < size; i++)
	{
		Answer answer;
		answer.deserialize(ifs);
		answers.add(answer);
	}
}

void Assignment::printAllAnsewrs() const
{
	answers.printAll();
	std::cout << std::endl;
}
