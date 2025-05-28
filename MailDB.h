#pragma once
#include "Mail.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

class MailDB
{
public:
	MailDB();
	void addMail(size_t userId);
	void mailbox(size_t userId) const;
	void message(const String& sender, size_t reciever, const String& content);
	void clearMailbox(size_t userId);
	void messageAll(const String& sender, const String& content);
	~MailDB();

private:
	static constexpr char mailsFileName[] = "1HWMailDB.dat";
	MyVector<Mail> mails;
	void load();
	void save() const;
};

