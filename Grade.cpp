#include "Grade.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

Grade::Grade(const String& course, const String& assignment, double grade,const String& note)
{
	courseName = course;
	assignmentname = assignment;
	this->grade = grade;
	this->note = note;
}

void Grade::serialize(std::ofstream& ofs) const
{
	courseName.serialize(ofs);
	assignmentname.serialize(ofs);
	note.serialize(ofs);
	ofs.write((const char*)&grade, sizeof(double));
}

void Grade::deserialize(std::ifstream& ifs)
{
	courseName.deserialize(ifs);
	assignmentname.deserialize(ifs);
	note.deserialize(ifs);
	double g;
	ifs.read((char*)&g, sizeof(double));
	grade = g;
}

std::ostream& operator<<(std::ostream& os, const Grade& grade)
{
	os << grade.courseName << " | " << grade.assignmentname << " | " << grade.grade << " | " << grade.note;
	return os;
}
