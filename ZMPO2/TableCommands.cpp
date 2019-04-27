#include "TableCommands.h"

AddTables::AddTables(vector<Table*>* tables)
{
	this->tables = tables;
}

DeleteTables::DeleteTables(vector<Table*>* tables)
{
	this->tables = tables;
}

DeleteAllTables::DeleteAllTables(vector<Table*>* tables)
{
	this->tables = tables;
}

SetTableLength::SetTableLength(vector<Table*>* tables)
{
	this->tables = tables;
}

SetTableName::SetTableName(vector<Table*>* tables)
{
	this->tables = tables;
}

SetValueOfCell::SetValueOfCell(vector<Table*>* tables)
{
	this->tables = tables;
}

RedefineTable::RedefineTable(vector<Table*>* tables)
{
	this->tables = tables;
}

ShowInfoOfTable::ShowInfoOfTable(vector<Table*>* tables)
{
	this->tables = tables;
}

void AddTables::runCommand()
{
		int operationNumber;
		cout << ADD_TABLES << endl;
		operationNumber = getInt();
		if (operationNumber == 1)
		{
			Table *table = new Table();
			(*tables).push_back(table);
			cout << ADDED_TABLE << endl;
		}
		if (operationNumber == 2)
		{
			int newTableLength;
			string newTableName;

			cout << ENTER_TABLE_NAME << endl;
			cin >> newTableName;

			cout << ENTER_TABLE_LENGTH << endl;
			newTableLength = getInt();

			Table * table = new Table(newTableName, newTableLength);
			(*tables).push_back(table);
			cout << ADDED_TABLE << endl;
		}
		if (operationNumber == 3)
		{
			int tableIndex;
			cout << ENTER_INDEX_OF_TABLE << endl;
			tableIndex = getInt();
			if ((tableIndex > 0) && (tableIndex < (*tables).size()))
			{
				Table *cTable = new Table(*(*tables).at(tableIndex));
				(*tables).push_back(cTable);
				cout << ADDED_TABLE << endl;
			}
			else
			{
				cout << NOT_ADDED_TABLE_ERROR << endl;
			}
		}
	
}


void DeleteTables::runCommand()
{
	int tableIndex;
	cout << ENTER_INDEX_OF_TABLE << endl;
	tableIndex = getInt();

	if ((tableIndex >= 0) && (tableIndex < (*tables).size()))
	{
		delete tables->at(tableIndex);
		(*tables).erase((*tables).begin() + tableIndex);
		cout << DELETED_TABLE << endl;
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << NOT_DELETED_TABLE_ERROR << endl;
	}
}

void DeleteAllTables::runCommand()
{
	for (int i = 0; i < (*tables).size(); i++)
	{
		delete tables->at(i);
	}
	(*tables).clear();
	cout << DELETED_ALL_TABLES << endl;
}

void SetTableLength::runCommand()
{
	int tableIndex;
	int tableLength;
	cout << ENTER_INDEX_OF_TABLE << endl;
	tableIndex = getInt();

	cout << ENTER_TABLE_LENGTH << endl;
	tableLength = getInt();

	if ((tableIndex >= 0) && (tableIndex < (*tables).size()))
	{
		Table *table = (*tables).at(tableIndex);
		(*table).setSize(tableLength);
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << TABLE_LENGTH_NOT_CHANGED_ERROR << endl;
	}
}

void SetTableName::runCommand()
{
	int tableIndex;
	string tableName;

	cout << ENTER_INDEX_OF_TABLE << endl;
	tableIndex = getInt();

	cout << ENTER_TABLE_NAME << endl;
	cin >> tableName;

	if ((tableIndex >= 0) && (tableIndex < (*tables).size()))
	{
		Table *cTable = (*tables).at(tableIndex);
		(*cTable).setName(tableName);
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << TABLE_LENGTH_NOT_CHANGED_ERROR << endl;
	}
}

void SetValueOfCell::runCommand()
{
	int tableIndex;
	int cellIndex;
	int newCellValue;

	cout << ENTER_INDEX_OF_TABLE << endl;
	tableIndex = getInt();

	cout << ENTER_INDEX_OF_CELL << endl;
	cellIndex = getInt();

	cout << ENTER_CELL_VALUE << endl;
	newCellValue = getInt();

	if ((tableIndex >= 0) && (tableIndex < (*tables).size()))
	{
		Table *table = (*tables).at(tableIndex);
		(*table).setValueOfCell(cellIndex, newCellValue);
		cout << CHANGED_CELL_VALUE << endl;
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << VALUE_NOT_CHANGED_ERROR << endl;
	}
}

void RedefineTable::runCommand()
{
	int copyFromTableIndex;
	int copyToTableIndex;

	cout << ENTER_INDEX_OF_TABLE_TO_COPY << endl;
	copyFromTableIndex = getInt();

	cout << ENTER_INDEX_OF_TABLE_TO_REDEFINE << endl;
	copyToTableIndex = getInt();

	if ((copyFromTableIndex >= 0) && (copyFromTableIndex < (*tables).size()) && (copyToTableIndex > 0) && (copyToTableIndex < (*tables).size()))
	{
		Table *copyFromTable = (*tables).at(copyFromTableIndex);
		Table *copyToTable = (*tables).at(copyToTableIndex);
		(*copyToTable).redefineTableValuesBasedOnOtherTable(*copyFromTable);

	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << REDEFINING_ERROR << endl;
	}
}

void ShowInfoOfTable::runCommand()
{
	int tableIndex;

	cout << ENTER_INDEX_OF_TABLE << endl;
	tableIndex = getInt();

	if ((tableIndex >= 0) && (tableIndex < (*tables).size()))
	{
		Table *table = (*tables).at(tableIndex);
		cout << (*table).getInfoOfTable() << endl;
	}
	else
	{
		cout << TABLE_NOT_FOUND_ERROR << endl;
	}
}
