#include "Mail.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

Mail::Mail(size_t userID): messages()
{
	this->userId = userID;
}

size_t Mail::getUserId() const
{
	return userId;
}

void Mail::mailbox() const
{
	if (messages.getSize() == 0)
	{
		std::cout << "No messges to show!\n";
		return;
	}
	messages.printAll();
}

void Mail::clearMailbox()
{
	messages.clear();
}

void Mail::addMessage(const Message& add)
{
	messages.add(add);

}

void Mail::serialize(std::ofstream& os) const
{
	os.write((const char*)&userId, sizeof(size_t));
	size_t messCnt = messages.getSize();
	os.write((const char*)&messCnt, sizeof(size_t));
	for (size_t i = 0; i < messCnt; i++)
	{
		messages[i].serialize(os);
	}
}

void Mail::deserialize(std::ifstream& ifs)
{
	size_t id = 0;
	ifs.read((char*)&id, sizeof(size_t));
	userId = id;
	size_t size = 0;
	ifs.read((char*)&size, sizeof(size_t));
	if (messages.getCapacity() <= size) messages.setCapacity(size);
	for (size_t i = 0; i < size; i++)
	{
		Message m;
		m.deserialize(ifs);
		messages.add(m);
	}

}
