#pragma once
#include <string>
#include <iostream>
using namespace std;

const string DEFAULT_NAME = "default";
const string DEFAULT_CONSTRUCTOR_TEXT = "no arg: ";
const string PARAMETER_CONSTRUCTOR_TEXT = "arg: ";
const string COPY_CONSTRUCTOR_TEXT = "copy: ";
const string DESTRUCTOR_TEXT = "delete: ";
const string OPENING_BRACKET_TABLE = "<";
const string CLOSING_BRACKET_TABLE = ">";
const string COPY_STATEMENT = "_copy";
const string LEN_STATEMENT = " len: ";
const string VALUES_STATEMENT = " values: ";
const string COMMA = ", ";
const int DEFAULT_LENGTH = 10;

const string WRONG_SIZE_ERROR = "Wrong size!";
const string NO_SUCH_CELL_ERROR = "No such cell in a table!";

class Table
{
public:
	Table();
	Table(string name, int length);
	Table(Table & otherTable);
	~Table();

	void setSize(int newSize);
	void setValueOfCell(int indexOfCell, int newValueOfCell);
	int getValueOfCell(int indexOfCell);
	void redefineTableValuesBasedOnOtherTable(Table & baseTable);
	string getInfoOfTable();
	void setName(string newName);
	int getMaxValueInTable();

private:
	string name;
	int * values;
	int length;
	int maxValue;
};