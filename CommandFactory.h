#pragma once
#include "String.h"
#include "Command.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa


class CommandFactory
{
public:
	Command* getCommand(const String& command,const User* currUser) const;
};

