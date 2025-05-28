#include "GradeDB.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void GradeDB::load()
{
	std::ifstream ifs(gradesFileName, std::ios::in | std::ios::binary);
	if (!ifs.is_open()) throw std::runtime_error("Couldn't open file!");
	size_t size=0;
	ifs.read((char*)&size, sizeof(size_t));
	GradesCollection gc;
	if (grades.getCapacity() <= size) grades.setCapacity(size);
	for (size_t i = 0; i < size; i++)
	{
		gc.deserialize(ifs);
		grades.add(gc);
	}
	ifs.close();
}

void GradeDB::save() const
{
	std::ofstream ofs(gradesFileName, std::ios::out | std::ios::binary);
	if (!ofs.is_open()) throw std::runtime_error("Couldn't open file!");
	size_t size = grades.getSize();
	ofs.write((const char*)&size, sizeof(size_t));
	for (size_t i = 0; i < size; i++)
	{
		grades[i].serialize(ofs);
	}
	ofs.close();
}

GradeDB::GradeDB()
{
	load();
	printAllGrades();
}

void GradeDB::addUser(size_t userId)
{
	grades.add(GradesCollection(userId));
}

void GradeDB::addGrade(const Grade& add, size_t userId)
{
	for (size_t i = 0; i < grades.getSize(); i++)
	{
		if (grades[i].getId() == userId) grades[i].addGrade(add);
	}
}

void GradeDB::printGrades(size_t userId) const
{
	for (size_t i = 0; i < grades.getSize(); i++)
	{
		if (grades[i].getId() == userId) grades[i].printGrades();
	}
}

GradeDB::~GradeDB()
{
	printAllGrades();
	save();
}
