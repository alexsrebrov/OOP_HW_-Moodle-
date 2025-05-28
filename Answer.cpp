#include "Answer.h"
#include "User.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

size_t Answer::idCreator = 100;

Answer::Answer()
 : userID(),sender(), content(), answerId(0) { }

Answer::Answer(size_t userID,const String& sender, const String& content)
{
	this->userID = userID;
	this->sender = sender;
	this->content = content;
	answerId = idCreator++;
}

size_t Answer::getAnswerID() const
{
	return answerId;
}

size_t Answer::getStudentID() const
{
	return userID;
}


void Answer::serialize(std::ofstream& ofs) const
{
	ofs.write((const char*)&userID, sizeof(size_t));
	sender.serialize(ofs);
	ofs.write((const char*)&answerId, sizeof(size_t));
	content.serialize(ofs);
}

void Answer::deserialize(std::ifstream& ifs)
{
	size_t Uid, Aid;
	ifs.read((char*)&Uid, sizeof(size_t));
	userID = Uid;
	sender.deserialize(ifs);
	ifs.read((char*)&Aid, sizeof(size_t));
	answerId = Aid;
	content.deserialize(ifs);
}

std::ostream& operator<<(std::ostream& os, const Answer& ans)
{
	os << ans.sender << ",  " << ans.answerId << ": " << ans.content;
	return os;
}
