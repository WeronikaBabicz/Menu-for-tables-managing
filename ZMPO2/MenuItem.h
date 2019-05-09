#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Command.h"
using namespace std;
class MenuItem
{
public:
	virtual void runMenu() = 0;
	virtual string getCommandName() = 0;
	virtual string getCommandId() = 0;
	string getPath();
	void setPath(string path);

protected:
	string id;
	string name;
	string path;
};

