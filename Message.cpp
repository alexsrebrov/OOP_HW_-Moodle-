#include "Message.h"
#pragma warning(disable:4996)

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

Message::Message(const String& sender, const String& content)
{
	this->sender = sender;
	this->content = content;
	mailTime = time(nullptr);
}


void Message::printTime(std::ostream& os,tm* time) const
{
	(time->tm_hour < 10) ? os<<'0' << time->tm_hour : os<<time->tm_hour;
	os << ":";
	(time->tm_min < 10) ? os<<'0' << time->tm_min : os<<time->tm_min;
	os << " ";
}

void Message::printDate(std::ostream& os, tm* time) const
{
	(time->tm_mday < 10) ? os << '0' << time->tm_mday : os << time->tm_mday;
	os << '.';
	(time->tm_mon < 9) ? os << '0' << time->tm_mon + 1 : os << time->tm_mon + 1;
	os << '.';
	os << time->tm_year + 1900<<", ";
}

void Message::serialize(std::ofstream& os) const
{
	content.serialize(os);
	sender.serialize(os);
	os.write((const char*)&mailTime, sizeof(time_t));
}

void Message::deserialize(std::ifstream& ifs)
{
	content.deserialize(ifs);
	sender.deserialize(ifs);
	time_t time;
	ifs.read((char*)&time, sizeof(time_t));
	mailTime = time;
}

std::ostream& operator<<(std::ostream& os, const Message& other)
{
	tm* t = localtime(&other.mailTime);
	other.printTime(os,t);
	other.printDate(os,t);
	os << "sent by " << other.sender << ": " << other.content <<std::endl;
	return os;
}
