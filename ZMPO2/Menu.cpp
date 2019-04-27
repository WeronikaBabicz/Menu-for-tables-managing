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
	string s_user_command;
	bool b_command_exists = false;
	while (s_user_command != EXIT_NAME)
	{
		cout << EQUALS << endl;
		cout << YOUR_PATH << path << endl;
		cout << EQUALS << endl;
		cout <<  name << SPACE << "\t" << OPENING_BRACKET << id << CLOSING_BRACKET << endl;
		for (int i = 0; i < menuItems.size(); i++)
		{
			cout << menuItems.at(i)->getName() << SPACE <<"\t" << OPENING_BRACKET << menuItems.at(i)->getCommand() << CLOSING_BRACKET << endl;
		}
		cout << EQUALS <<endl << HOW_TO_EXIT_INFO << EXIT_NAME << endl;
		cout << endl << ENTER_COMMAND_ID << endl;
		cin >> s_user_command;
		cout << endl;
		for (int i = 0; i < menuItems.size(); i++)
		{
			if (s_user_command == menuItems.at(i)->getCommand())
			{
				b_command_exists = true;
				menuItems.at(i)->runMenu();
			}
		}

		if (b_command_exists == false && s_user_command != EXIT_NAME)
		{
			cout << ERROR_COMMAND_NAME << endl;
		}
	}

}

string Menu::getName()
{
	return name;
}

string Menu::getCommand()
{
	return id;
}

void Menu::addItem(MenuItem * cItem)
{
	cItem->setPath(path + ARROW + cItem->getName());
	for (int i = 0; i < menuItems.size(); i++)
	{
		if (menuItems.at(i)->getName() == cItem->getName() || menuItems.at(i)->getCommand() == cItem->getCommand())
		{
			cout << ADDING_ERROR << endl;
			return;
		}
	}
	menuItems.push_back(cItem);
}

void Menu::deleteItem(string s_user_command)
{
	bool b_exists = false;
	for (int i = 0; i < menuItems.size(); i++)
	{
		if (s_user_command == menuItems.at(i)->getCommand())
		{
			b_exists = true;
			menuItems.erase(menuItems.begin() + i);
			cout << ITEM_REMOVED << endl;
		}
	}
	if (b_exists == false)
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
	int i_command_number = getInteger();
	while (i_command_number < 0 || i_command_number > parentMenu.getAllCommands().size())
	{
		cout << ENTER_PROPER << endl;
		i_command_number = getInteger();
	}


	MenuCommand * c_new_menu_command = new MenuCommand(commandName, commandID);
	c_new_menu_command->setCommand(parentMenu.getAllCommands().at(i_command_number));
	parentMenu.addItem(c_new_menu_command);
}

void DeleteItem::runCommand()
{
	string s_user_command;
	cout << ENTER_COMMAND_ID << endl;
	cin >> s_user_command;
	parentMenu.deleteItem(s_user_command);
}
