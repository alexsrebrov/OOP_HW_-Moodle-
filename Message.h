#pragma once
#include "String.h"
#include <ctime>
#include <fstream>
#include <iostream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

class Message
{
public:
	Message() = default;
	Message(const String& sender, const String& content);
	friend std::ostream& operator<<(std::ostream& os, const Message& other);
	void serialize(std::ofstream& os) const;
	void deserialize(std::ifstream& ifs);

private:
	String content;
	time_t mailTime;
	String sender;
	void printTime(std::ostream& os,tm* time) const;
	void printDate(std::ostream& os,tm* time) const;
};



