#pragma once
#include "Course.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class CourseDB
{
public:
	CourseDB();
	void addCourse(const Course& add);
	MyVector<size_t> getUsersIds(const String& courseName) const;
	void addUser(const String& courseName, size_t userId);
	void addAssignment(const String& courseName, const String& assignmentName);
	size_t getUserIdByAnswerId(const String& courseName, const String& assignmentName,size_t answerId) const;
	void addAnswer(const String& courseName, const String& assignmentName, size_t userId,
	const String& userName, const String& content);
	void printAssignmentAnswers(const String& courseName, const String& assignmentName);
	bool validateCourseInfo(const String& courseName, const String& pass) const;
	~CourseDB();

private:
	static constexpr char coursesFileName[] = "1HWCoursesDB.dat";
	MyVector<Course> courses;
	void load();
	void save() const;
};

