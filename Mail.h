#pragma once
#include "Message.h"
#include "MyVector.hpp"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

class Mail
{
public:
	Mail() = default;
	Mail(size_t userID);
	size_t getUserId() const;
	void mailbox() const;
	void clearMailbox();
	void addMessage(const Message& add);

	void serialize(std::ofstream& os) const;
	void deserialize(std::ifstream& ifs);
private:
	size_t userId;
	MyVector<Message> messages;
};


