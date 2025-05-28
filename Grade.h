#pragma once
#include "String.h"
#include <iostream>
//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

class Grade
{
public:
	Grade() = default;
	Grade(const String& course,const String& assignment,double grade,const String& note);
	friend std::ostream& operator<<(std::ostream& os, const Grade& grade);

	void serialize(std::ofstream& ofs) const;
	void deserialize(std::ifstream& ifs);

private:
	String courseName;
	String assignmentname;
	double grade = 0;
	String note;
};

