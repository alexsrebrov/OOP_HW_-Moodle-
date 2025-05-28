#include "CourseDB.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void CourseDB::load()
{
	std::ifstream ifs(coursesFileName, std::ios::in | std::ios::binary);
	if (!ifs.is_open()) throw std::runtime_error("Couldn't open file!");
	size_t size = 0;
	ifs.read((char*)&size, sizeof(size_t));
	if (courses.getCapacity() <= size) courses.setCapacity(size);
	for (size_t i = 0; i < size; i++)
	{
		Course c;
		c.deserialize(ifs);
		courses.add(c);
	}
	ifs.close();
}

void CourseDB::save() const
{
	std::ofstream ofs(coursesFileName, std::ios::out | std::ios::binary);
	if (!ofs.is_open()) throw std::runtime_error("Couldn't open file!");
	size_t size = courses.getSize();
	ofs.write((const char*)&size, sizeof(size_t));
	for (size_t i = 0; i < size; i++)
	{
		courses[i].serialize(ofs);
	}
	ofs.close();
}

CourseDB::CourseDB()
{
	load();
	printAllCourses();
}

void CourseDB::addCourse(const Course& add)
{
	courses.add(add);
}

MyVector<size_t> CourseDB::getUsersIds(const String& courseName) const
{
	for (size_t i = 0; i < courses.getSize(); i++)
	{
		if (courses[i].gerCourseName() == courseName) return courses[i].getUsersIDs();
	}
	throw std::runtime_error("Invalid course name!");
}

void CourseDB::addUser(const String& courseName, size_t userId)
{
	for (size_t i = 0; i < courses.getSize(); i++)
	{
		if (courses[i].gerCourseName() == courseName) courses[i].addUser(userId);
	}
}

void CourseDB::addAssignment(const String& courseName, const String& assignmentName)
{
	for (size_t i = 0; i < courses.getSize(); i++)
	{
		if (courses[i].gerCourseName() == courseName)	courses[i].addAssignment(assignmentName);
	}
}

size_t CourseDB::getUserIdByAnswerId(const String& courseName, const String& assignmentName, size_t answerId) const
{
	
	for (size_t i = 0; i < courses.getSize(); i++)
	{
		if(courses[i].gerCourseName() == courseName)
			return courses[i].getUserIdByAnswerID(assignmentName, answerId);
	}
}

void CourseDB::addAnswer(const String& courseName, const String& assignmentName, size_t userId,
				const String& userName, const String& content)
{
	for (size_t i = 0; i < courses.getSize(); i++)
	{
		if (courses[i].gerCourseName() == courseName)
			courses[i].addAnswer(assignmentName, userId, userName, content);
	}
}

void CourseDB::printAssignmentAnswers(const String& courseName, const String& assignmentName)
{
	for (size_t i = 0; i < courses.getSize(); i++)
	{
		if (courses[i].gerCourseName() == courseName)
			courses[i].printAssignmentAnswers(assignmentName);
	}
}

bool CourseDB::validateCourseInfo(const String& courseName, const String& pass) const
{
	for (size_t i = 0; i < courses.getSize(); i++)
	{
		if (courses[i].canJoin(courseName, pass)) return true;
	}
	return false;
}

CourseDB::~CourseDB()
{
	printAllCourses();
	save();
}
