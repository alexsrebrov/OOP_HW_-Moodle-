#pragma once
#include "String.h"
#include "Assignment.h"
#include "MyVector.hpp"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class Course
{
public:
	Course()=default;
	Course(const String& name, const String& pass);

	void addUser(size_t userID);
	void addUser(size_t userID, const String& pass);
	void addAssignment(const String& assignmentName);
	MyVector<size_t> getUsersIDs() const;
	const String& gerCourseName() const;
	bool canJoin(const String& courseName,const String& pass) const;
	void addAnswer(const String& assignmentName, size_t userID, const String& userName, const String& content);
	void printAssignmentAnswers(const String& assignmentName);
	size_t getUserIdByAnswerID(const String& assignmentName, size_t answerId) const;

	void serialize(std::ofstream& ofs) const;
	void deserialize(std::ifstream& ifs);

private:
	String name;
	String pass;
	MyVector<size_t> studentsIds;
	MyVector<Assignment> assignments;
};

