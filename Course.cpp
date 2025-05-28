#include "Course.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

Course::Course(const String& name, const String& pass)
: name(name),pass(pass),studentsIds(),assignments(){}

void Course::addUser(size_t userID)
{
	studentsIds.add(userID);
}

void Course::addUser(size_t userID,const String& pass)
{
	if (this->pass == pass)  studentsIds.add(userID);
}

void Course::addAssignment(const String& assignmentName)
{
	assignments.add(Assignment(assignmentName));
}

MyVector<size_t> Course::getUsersIDs() const
{
	return studentsIds;
}

const String& Course::gerCourseName() const
{
	return name;
}

bool Course::canJoin(const String& courseName, const String& pass) const
{
	return (this->name == courseName && this->pass == pass);
}

void Course::addAnswer(const String& assignmentName, size_t userID, const String& userName, const String& content)
{
	for (size_t i = 0; i < assignments.getSize(); i++)
	{
		if (assignments[i].getAssignmentName() == assignmentName)
			assignments[i].addAnswer(Answer(userID,userName,content));
	}
	return;
}

void Course::printAssignmentAnswers(const String& assignmentName)
{
	for (size_t i = 0; i < assignments.getSize(); i++)
	{
		if (assignments[i].getAssignmentName() == assignmentName) assignments[i].printAllAnsewrs();
	}
	return;
}

size_t Course::getUserIdByAnswerID(const String& assignmentName, size_t answerId) const
{
	for (size_t i = 0; i < assignments.getSize(); i++)
	{
		if (assignments[i].getAssignmentName() == assignmentName) return assignments[i].getUserId(answerId);
	}
	throw std::runtime_error("Invalid answerId");
}

void Course::serialize(std::ofstream& ofs) const
{
	name.serialize(ofs);
	pass.serialize(ofs);
	size_t usersCnt = studentsIds.getSize();
	ofs.write((const char*)&usersCnt, sizeof(size_t));
	for (size_t i = 0; i < usersCnt; i++)
	{
		size_t currId = studentsIds[i];
		ofs.write((const char*)&currId, sizeof(size_t));
	}
	size_t assignmentsCnt= assignments.getSize();
	ofs.write((const char*)&assignmentsCnt, sizeof(size_t));
	for (size_t i = 0; i < assignmentsCnt; i++)
	{
		assignments[i].serialize(ofs);
	}
}

void Course::deserialize(std::ifstream& ifs)
{
	name.deserialize(ifs);
	pass.deserialize(ifs);
	size_t UsersCnt = 0, assignmentsCnt = 0;
	ifs.read((char*)&UsersCnt, sizeof(size_t));
	if (studentsIds.getCapacity() <= UsersCnt) studentsIds.setCapacity(UsersCnt);
	for (size_t i = 0; i < UsersCnt; i++)
	{
		size_t currId = 0;
		ifs.read((char*)&currId, sizeof(size_t));
		studentsIds.add(currId);
	}
	ifs.read((char*)&assignmentsCnt, sizeof(size_t));
	if (assignments.getCapacity() <= assignmentsCnt) assignments.setCapacity(assignmentsCnt);
	for (size_t i = 0; i < assignmentsCnt; i++)
	{
		Assignment assignment;
		assignment.deserialize(ifs);
		assignments.add(assignment);
	}
}
