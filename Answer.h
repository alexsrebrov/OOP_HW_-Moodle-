#pragma once
#include "String.h"
class User;


//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class Answer
{
public:
	Answer();
	Answer(size_t userId,const String& sender, const String& content);
	friend std::ostream& operator<<(std::ostream& os,const Answer& ans);
	size_t getAnswerID() const;
	size_t getStudentID() const;

	void serialize(std::ofstream& ofs) const;
	void deserialize(std::ifstream& ifs);

private:
	size_t userID;
	String sender;
	size_t answerId;
	static size_t idCreator;
	String content;
};

