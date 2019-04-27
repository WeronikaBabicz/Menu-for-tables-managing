#pragma once
#include "Command.h"
#include "Table.h"
#include <vector>
const string ADD_TABLES = "[1] Default\n[2] Custom\n[3] Copy";

const string ENTER_INTEGER = "Enter integer! ";
const string ENTER_TABLE_NAME = "Enter table name: ";
const string ENTER_TABLE_LENGTH = "Enter table length: ";
const string ENTER_INDEX_OF_TABLE = "Enter index of table: ";
const string ENTER_INDEX_OF_CELL = "Enter index of cell: ";
const string ENTER_CELL_VALUE = "Enter cell value: ";
const string ENTER_INDEX_OF_TABLE_TO_COPY = "Enter index of table to copy: ";
const string ENTER_INDEX_OF_TABLE_TO_REDEFINE = "Enter index of table to redefine: ";

const string ADDED_TABLE = "Table added!";
const string DELETED_TABLE = "Table deleted!";
const string DELETED_ALL_TABLES = "All tables deleted!";
const string REDEFINED_TABLE = "Table redefined!";
const string SET_TABLE_LENGTH = "Table's length changed!";
const string SET_TABLE_NAME = "Table's name changed!";
const string CHANGED_CELL_VALUE = "Cell's value changed!";

const string OPERATION_NOT_FOUND_ERROR = "Operation not found!!! ";
const string TABLE_NOT_FOUND_ERROR = "Table not found!!! ";
const string NOT_ADDED_TABLE_ERROR = "Table not added!!! ";
const string NOT_DELETED_TABLE_ERROR = "Table not deleted!!! ";
const string REDEFINING_ERROR = "Table not redefined!!! ";
const string TABLE_LENGTH_NOT_CHANGED_ERROR = "Table's length not changed!!! ";
const string TABLE_NAME_NOT_CHANGED = "Table's name not changed!!! ";
const string VALUE_NOT_CHANGED_ERROR = "Cell's value not changed!!! ";
const string EXIT = "back";

const int OPERATIONS_COUNT = 10;

static int getInt()
{
	int integer;
	cin >> integer;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << ENTER_INTEGER <<endl;
		cin >> integer;
	}

	return integer;
}

class AddTables : public Command
{
	
public:
	AddTables(vector<Table*> *cTable);
	virtual void runCommand();
	vector<Table*> *tables;
};

class DeleteTables : public Command
{
public:
	DeleteTables(vector<Table*> *cTable);
	virtual void runCommand();
	vector<Table*> *tables;
};

class DeleteAllTables : public Command
{
public:
	DeleteAllTables(vector<Table*> *cTable);
	virtual void runCommand();
	vector<Table*> *tables;
};

class SetTableLength : public Command
{
public:
	SetTableLength(vector<Table*> *cTable);
	virtual void runCommand();
	vector<Table*> *tables;
};

class SetTableName : public Command
{
public:
	SetTableName(vector<Table*> *cTable);
	virtual void runCommand();
	vector<Table*> *tables;
};

class SetValueOfCell : public Command
{
public:
	SetValueOfCell(vector<Table*> *cTable);
	virtual void runCommand();
	vector<Table*> *tables;
};

class RedefineTable : public Command
{
public:
	RedefineTable(vector<Table*> *cTable);
	virtual void runCommand();
	vector<Table*> *tables;
};

class ShowInfoOfTable : public Command
{
public:
	ShowInfoOfTable(vector<Table*> *cTable);
	virtual void runCommand();
	vector<Table*> *tables;

};