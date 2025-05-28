#pragma once
#include "GradesCollection.h"
#include "MyVector.hpp"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

class GradeDB
{
public:
	GradeDB();
	void addUser(size_t userId);
	void addGrade(const Grade& add, size_t userId);
	void printGrades(size_t userId) const;
	~GradeDB();

private:
	static constexpr char gradesFileName[] = "1HWGradesDB.dat";
	MyVector<GradesCollection> grades;
	void load();
	void save() const;
};

