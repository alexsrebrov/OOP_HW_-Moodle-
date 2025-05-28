#pragma once
#include "Grade.h"
#include "MyVector.hpp"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

class GradesCollection
{
public:
	GradesCollection() = default;
	GradesCollection(size_t userId);
	void addGrade(const Grade& add);
	void printGrades() const;
	size_t getId() const;

	void serialize(std::ofstream& ofs) const;
	void deserialize(std::ifstream& ifs);

private:
	size_t userId;
	MyVector<Grade> grades;
};


