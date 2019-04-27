#pragma once
#include "MenuItem.h"
#include "MenuCommand.h"

const string ARROW = " -> ";
const string YOUR_PATH = "Current path: ";
const string SPACE = " ";
const string BAR = "-------------------------------------------------";
const string OPENING_BRACKET = "(";
const string CLOSING_BRACKET = ")";
const string ENTER_COMMAND_ID = "Enter command ID: ";
const string ERROR_COMMAND_NAME = "Wrong command! ";
const string EXIT_NAME = "back";
const string ITEM_REMOVED = "Deleted ";
const string ADDING_ERROR = "Can not add!";
const string DELETING_ERROR = "Can not delete!";
const string ENTER_COMMAND_NAME = "Enter new command name: ";
const string WHICH_COMMAND = "Choose command operation: ";
const string ADD_TABLE = "Create table";
const string DELETE_TABLE = "Delete table";
const string DELETE_ALL_TABLES = "Delete all tables";
const string SET_LENGTH = "Set length of a table";
const string SET_NAME = "Set name of a table";
const string SET_VALUE = "Set value of a cell";
const string REDEFINE = "Copy values and length of a table to a different table";
const string SHOW_INFO = "Show info of table";
const string MAINMENU = "Main menu";
const string MAINMENU_ID = "main";
const string ENTER_INT = "Enter integer! ";
const string ADD_COMMAND = "Add command";
const string ADD_COMMAND_ID = "add";
const string DELETE_COMMAND = "Delete command";
const string DELETE_COMMAND_ID = "delete";
const string ENTER_PROPER = "Enter proper value";
const string SUBMENU = "SubMenu";
const string SUBMENU_ID = "menu1";
const string SUBSUBMENU = "SubSubMenu";
const string SUBSUBMENU_ID = "menu2";
const string HOW_TO_EXIT_INFO = "To exit current menu type ";
const string EQUALS = "=================================================";

static int getInteger()
{
	int integer;
	cin >> integer;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << ENTER_INT << endl;
		cin >> integer;
	}

	return integer;
}

class Menu : public MenuItem
{

public:
	Menu(string name, string id);
	~Menu();
	virtual void runMenu();
	virtual string getName();
	virtual string getCommand();
	void addItem(MenuItem * menuItem);
	void deleteItem(string commandID);
	void setAllCommands(vector<Command*> *allCommands);
	vector<Command*> getAllCommands();
	

private:
	vector<MenuItem*> menuItems; 
	vector<Command*> *allCommands;
};

class AddItem : public Command
{
public:
	virtual void runCommand();
	Menu & parentMenu;
	AddItem(Menu &parent) : parentMenu(parent) {};
};

class DeleteItem : public Command
{
public:
	virtual void runCommand();
	Menu & parentMenu;
	DeleteItem(Menu &parent) : parentMenu(parent) {};
};
