#include "GradesCollection.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

GradesCollection::GradesCollection(size_t userId) : grades()
{
	this->userId = userId;
}

void GradesCollection::addGrade(const Grade& add)
{
	grades.add(add);
}

void GradesCollection::printGrades() const
{
	for (size_t i = 0; i < grades.getSize(); i++)
	{
		std::cout << grades[i];
	}
}

size_t GradesCollection::getId() const
{
	return userId;
}

void GradesCollection::serialize(std::ofstream& ofs) const
{
	ofs.write((const char*)&userId, sizeof(size_t));
	size_t size = grades.getSize();
	ofs.write((const char*)&size, sizeof(size_t));
	for (size_t i = 0; i < size; i++)
	{
		grades[i].serialize(ofs);
	}
}

void GradesCollection::deserialize(std::ifstream& ifs)
{
	size_t id, size;
	ifs.read((char*)&id, sizeof(size_t));
	userId = id;
	ifs.read((char*)&size, sizeof(size_t));
	if (grades.getCapacity() <= size) grades.setCapacity(size);
	for (size_t i = 0; i < size; i++)
	{
		Grade  g;
		g.deserialize(ifs);
		grades.add(g);
	}
}
