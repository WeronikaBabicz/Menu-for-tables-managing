#pragma once
#include <iostream>
#include <string>
using namespace std;
const string DEFAULT_COMMAND = "Komenda domy�lna";
class Command
{
public:
	virtual void runCommand() = 0;
	string getDescription();
	void setDescription(string description);

protected:
	string description;
};

