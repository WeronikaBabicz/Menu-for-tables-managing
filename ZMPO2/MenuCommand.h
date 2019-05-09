#pragma once
#include "MenuItem.h"

class MenuCommand : public MenuItem
{
public:
	MenuCommand(string name, string id);
	~MenuCommand();
	virtual string getCommandName();
	virtual string getCommandId();
	virtual void runMenu();
	void setCommand(Command * command);
private:
	const string EMPTY_COMMAND = "pusta komenda ";

	Command * command = 0;
};

