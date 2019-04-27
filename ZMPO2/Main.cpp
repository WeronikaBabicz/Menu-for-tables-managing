#pragma once
#include "Menu.h"
#include "MenuCommand.h"
#include "Command.h"
#include "MenuItem.h"
#include "Table.h"
#include "TableCommands.h"
#include <iostream>
int main()
{
	Menu * mainMenu = new Menu(MAINMENU, MAINMENU_ID);
	mainMenu->setPath(MAINMENU);

	Menu * subMenu = new Menu(SUBMENU, SUBMENU_ID);
	mainMenu->addItem(subMenu);

	Menu *subSubMenu = new Menu(SUBSUBMENU, SUBSUBMENU_ID);
	subMenu->addItem(subSubMenu);

	vector<Table*> tables;
	vector<Command*> *allCommands = new vector<Command*>;

	AddTables *addTableCommand = new AddTables(&tables);
	addTableCommand->setDescription(ADD_TABLE);
	allCommands->push_back(addTableCommand);

	DeleteTables *deleteTableCommand = new DeleteTables(&tables);
	deleteTableCommand->setDescription(DELETE_TABLE);
	(*allCommands).push_back(deleteTableCommand);

	DeleteAllTables *deleteAllTablesCommand = new DeleteAllTables(&tables);
	deleteAllTablesCommand->setDescription(DELETE_ALL_TABLES);
	(*allCommands).push_back(deleteAllTablesCommand);

	SetTableLength *setTableLengthCommand = new SetTableLength(&tables);
	setTableLengthCommand->setDescription(SET_LENGTH);
	(*allCommands).push_back(setTableLengthCommand);

	SetTableName *setTableNameCommand = new SetTableName(&tables);
	setTableNameCommand->setDescription(SET_NAME);
	(*allCommands).push_back(setTableNameCommand);

	SetValueOfCell *setValueOfCellCommand = new SetValueOfCell(&tables);
	setValueOfCellCommand->setDescription(SET_VALUE);
	(*allCommands).push_back(setValueOfCellCommand);

	RedefineTable *redefineTableBasedOnOtherTableCommand = new RedefineTable(&tables);
	redefineTableBasedOnOtherTableCommand->setDescription(REDEFINE);
	(*allCommands).push_back(redefineTableBasedOnOtherTableCommand);

	ShowInfoOfTable *showInfoOfTableCommand = new ShowInfoOfTable(&tables);
	showInfoOfTableCommand->setDescription(SHOW_INFO);
	(*allCommands).push_back(showInfoOfTableCommand);

	mainMenu->setAllCommands(allCommands);
	subMenu->setAllCommands(allCommands);
	subSubMenu->setAllCommands(allCommands);

	mainMenu->runMenu();
	
	for (int i = 0; i < allCommands->size(); i++)
	{
		delete allCommands->at(i);
	}
	
	for (int i = 0; i < tables.size(); i++)
	{
		delete tables.at(i);
	}

	delete allCommands;
	delete mainMenu;
	return 0;
}