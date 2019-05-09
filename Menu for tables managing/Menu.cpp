#include "Menu.h"
#include <sstream>


Menu::Menu(string name, string id)
{
	this->name = name;
	this->id = id;
	path = name;

	AddItem *addCommand = new AddItem(*this);
	MenuCommand * addCommandMenuItem = new MenuCommand(ADD_COMMAND, ADD_COMMAND_ID);
	addCommandMenuItem->setCommand(addCommand);
	addItem(addCommandMenuItem);

	DeleteItem *deleteCommand = new DeleteItem(*this);
	MenuCommand *deleteCommandMenuItem = new MenuCommand(DELETE_COMMAND, DELETE_COMMAND_ID);
	deleteCommandMenuItem->setCommand(deleteCommand);
	addItem(deleteCommandMenuItem);
}

Menu::~Menu()
{
	for (int i = 0; i < menuItems.size(); i++)
	{
		delete menuItems.at(i);
	}

}


void Menu::runMenu()
{
	string userCommand;
	bool exists = false;
	while (userCommand != EXIT_NAME)
	{
		cout << EQUALS << endl;
		cout << YOUR_PATH << path << endl;
		cout << EQUALS << endl;
		cout <<  name << SPACE << "\t" << OPENING_BRACKET << id << CLOSING_BRACKET << endl;
		for (int i = 0; i < menuItems.size(); i++)
		{
			cout << menuItems.at(i)->getCommandName() << SPACE <<"\t" << OPENING_BRACKET << menuItems.at(i)->getCommandId() << CLOSING_BRACKET << endl;
		}
		cout << EQUALS <<endl << HOW_TO_EXIT_INFO << EXIT_NAME << endl;
		cout << endl << ENTER_COMMAND_ID << endl;
		cin >> userCommand;
		cout << endl;
		for (int i = 0; i < menuItems.size(); i++)
		{
			if (userCommand == menuItems.at(i)->getCommandId())
			{
				exists = true;
				menuItems.at(i)->runMenu();
			}
		}

		if (exists == false && userCommand != EXIT_NAME)
		{
			cout << ERROR_COMMAND_NAME << endl;
		}
	}

}

string Menu::getCommandName()
{
	return name;
}

string Menu::getCommandId()
{
	return id;
}

void Menu::addItem(MenuItem * menuItem)
{
	menuItem->setPath(path + ARROW + menuItem->getCommandName());
	for (int i = 0; i < menuItems.size(); i++)
	{
		if (menuItems.at(i)->getCommandName() == menuItem->getCommandName() || menuItems.at(i)->getCommandId() == menuItem->getCommandId())
		{
			cout << ADDING_ERROR << endl;
			return;
		}
	}
	menuItems.push_back(menuItem);
}

void Menu::deleteItem(string userCommand)
{
	bool exists = false;
	for (int i = 0; i < menuItems.size(); i++)
	{
		if (userCommand == menuItems.at(i)->getCommandId())
		{
			exists = true;
			menuItems.erase(menuItems.begin() + i);
			cout << ITEM_REMOVED << endl;
		}
	}
	if (exists == false)
	{
		cout << DELETING_ERROR << endl;
	}
}

void Menu::setAllCommands(vector<Command*>* allCommands)
{
	this->allCommands = allCommands;
}

vector<Command*> Menu::getAllCommands()
{
	return *allCommands;
}


void AddItem::runCommand()
{
	string commandName;
	cout << ENTER_COMMAND_NAME << endl;
	cin >> commandName;
	string commandID;
	cout << ENTER_COMMAND_ID << endl;
	cin >> commandID;
	for (int i = 0; i < parentMenu.getAllCommands().size(); i++)
	{
		cout << OPENING_BRACKET << i << CLOSING_BRACKET << SPACE << parentMenu.getAllCommands().at(i)->getDescription() << endl;
	}
	cout << WHICH_COMMAND << endl;
	int commandNumber = getInteger();
	while (commandNumber < 0 || commandNumber > parentMenu.getAllCommands().size())
	{
		cout << ENTER_PROPER << endl;
		commandNumber = getInteger();
	}


	MenuCommand * newMenuCommand = new MenuCommand(commandName, commandID);
	newMenuCommand->setCommand(parentMenu.getAllCommands().at(commandNumber));
	parentMenu.addItem(newMenuCommand);
}

void DeleteItem::runCommand()
{
	string userCommand;
	cout << ENTER_COMMAND_ID << endl;
	cin >> userCommand;
	parentMenu.deleteItem(userCommand);
}
