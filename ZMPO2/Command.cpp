#include "Command.h"


void Command::runCommand()
{
	cout << DEFAULT_COMMAND << endl;
}

string Command::getDescription()
{
	return description;
}

void Command::setDescription(string description)
{
	this->description = description;
}
