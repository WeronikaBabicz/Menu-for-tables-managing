#include "MenuCommand.h"



MenuCommand::MenuCommand(string name, string id)
{
	this->name = name;
	this->id = id;
	command = nullptr;//NULL
}


MenuCommand::~MenuCommand()
{
}

string MenuCommand::getCommandName()
{
	return name;
}

string MenuCommand::getCommandId()
{
	return id;
}

void MenuCommand::runMenu()
{
	if (command == nullptr) //nullptr
	{
		cout << EMPTY_COMMAND << endl;
	}
	else
	{
		command->runCommand();
	}
}

void MenuCommand::setCommand(Command * command)
{
	this->command = command;
}
