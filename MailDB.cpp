#include "MailDB.h"
#include<fstream>

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

void MailDB::save() const
{
	std::ofstream ofs(mailsFileName, std::ios::out | std::ios::binary);
	if (!ofs.is_open()) throw std::runtime_error("Couldn't open file!");
	size_t accountsCnt = mails.getSize();
	ofs.write((const char*)&accountsCnt, sizeof(size_t));
	for (size_t i = 0; i < accountsCnt; i++)
	{
		mails[i].serialize(ofs);
	}
	ofs.close();
}

void MailDB::load()
{
	std::ifstream ifs(mailsFileName, std::ios::in | std::ios::binary);
	if (!ifs.is_open()) throw std::runtime_error("Couldn't open file!");
	size_t size=0;
	ifs.read((char*)&size, sizeof(size_t));
	if (mails.getCapacity() <= size) mails.setCapacity(size);
	for (size_t i = 0; i < size; i++)
	{
		Mail m;
		m.deserialize(ifs);
		mails.add(m);
	}
	ifs.close();
}

MailDB::MailDB()
{
	load();
	printAllMailInfo();
}

void MailDB::addMail(size_t userId)
{
	mails.add(Mail(userId));
}

void MailDB::mailbox(size_t userId) const
{
	for (size_t i = 0; i < mails.getSize(); i++)
	{
		if (mails[i].getUserId() == userId) mails[i].mailbox();
	}
	return;
}

void MailDB::message(const String& sender, size_t reciever, const String& content)
{
	for (size_t i = 0; i < mails.getSize(); i++)
	{
		if (mails[i].getUserId() == reciever)
		{
			mails[i].addMessage(Message(sender, content));
		}
	}
	return;
}

void MailDB::clearMailbox(size_t userId)
{
	for (size_t i = 0; i < mails.getSize(); i++)
	{
		if (mails[i].getUserId() == userId) mails[i].clearMailbox();
	}
	return;
}

void MailDB::messageAll(const String& sender, const String& content)
{
	for (size_t i = 0; i < mails.getSize(); i++)
	{
		mails[i].addMessage(Message(sender, content));
	}
}

MailDB::~MailDB()
{
	printAllMailInfo();
	save();
}

