#include <iostream>
#include <string>
#include "mysql.h"
#include "Globals.h"

using namespace std;

MYSQL* conectionStatus;
MYSQL_RES* res;
MYSQL_ROW row;
int msqlPointer;

int status;

bool programOn = true;

const char* query;

string tableName;

int answ;
int answ1;
bool selection;

enum TableNames
{
	USERS = 1,
	WEAPONS,
	SKILLS,
	CHARACTERS,
	PLAYERS,
};

void CheckServerConection();
void ReadTableData(string tableName);
void InsertTableData(string tableName);
void UpdateTableData(string tableName);
void DeleteTableData(string tableName);

void main()
{
	tableName = "Users";
	CheckServerConection();

	do
	{
		selection = false;
		do
		{
			system("cls");

			cout << "Select Table To Use" << endl;
			cout << "1 - Users" << endl;
			cout << "2 - Weapons" << endl;
			cout << "3 - Skills" << endl;
			cout << "4 - Characters" << endl;
			cout << "5 - Players" << endl;
			cout << "0 - Users" << endl;
			cout << "User ---> ";
			cin >> answ1;

			switch (answ1)
			{
			case 1: tableName = "Users"; selection = true; break;
			case 2: tableName = "Weapons"; selection = true; break;
			case 3: tableName = "Skills"; selection = true; break;
			case 4: tableName = "Characters"; selection = true; break;
			case 5: tableName = "Players"; selection = true; break;
			case 0: return;
			default:
				cout << "Error" << endl;
				selection = false;
				system("pause");
				break;
			}

		} while (!selection);

		system("cls");
		cout << "1 _ Ingresar Data" << endl;
		cout << "2 _ Updatear Data" << endl;
		cout << "3 _ Leer Data" << endl;
		cout << "4 _ Borrar Data" << endl;
		cout << "0 _ Salir" << endl;
		cout << "User ---> ";
		cin >> answ;

		switch (answ)
		{
		case 1: InsertTableData(tableName); break;
		case 2: UpdateTableData(tableName); break;
		case 3: ReadTableData(tableName);   break;
		case 4: DeleteTableData(tableName); break;

		case 0: programOn = false; break;
		default:
			cout << "Error" << endl;
			system("pause");
			break;
		}

	} while (programOn);
	system("cls");
	system("pause");
}
void CheckServerConection()
{
	system("cls");

	const char dataBaseHost[] = "localhost";
	const char dataBaseUser[] = "root";
	const char dataBasePasword[] = "153624";
	const char dataBaseName[] = "DIM_DataBaseEdition";
	const int port = 3306;

	conectionStatus = mysql_init(0);
	conectionStatus = mysql_real_connect(conectionStatus, dataBaseHost, dataBaseUser, dataBasePasword, dataBaseName, port, 0, 0);

	if (conectionStatus)
		cout << "Established Connection" << endl;
	else
	{
		cout << "Connection not Established" << endl;
		throw ERROR_CALL_NOT_IMPLEMENTED;
	}
}
void ReadTableData(string tableName)
{
	system("cls");
	string comand = "select * from " + tableName;
	query = comand.c_str();

	status = mysql_query(conectionStatus, query);

	if (!status)
	{
		res = mysql_store_result(conectionStatus);
		cout << "Returned Data" << endl;
		
		switch (answ1)
		{
		case (int)TableNames::USERS:
			while (row = mysql_fetch_row(res))
			{
				cout << endl;
				cout << "UserId: " << row[0] << endl;
				cout << "UserName: " << row[1] << endl;
				cout << "UserPasword: " << row[2] << endl;
			}
			break;
		case (int)TableNames::WEAPONS:
			while (row = mysql_fetch_row(res))
			{
				cout << endl;
				cout << "IdWeapon: " << row[0] << endl;
				cout << "nameWeapon: " << row[1] << endl;
			}
			break;
		case (int)TableNames::SKILLS:
			while (row = mysql_fetch_row(res))
			{
				cout << endl;
				cout << "IdSkill: " << row[0] << endl;
				cout << "nameSkill: " << row[1] << endl;
			}
			break;
		case (int)TableNames::CHARACTERS:
			while (row = mysql_fetch_row(res))
			{
				cout << endl;
				cout << "IdCharacter: " << row[0] << endl;
				cout << "nameCharacter: " << row[1] << endl;
				cout << "descriptionCharacter: " << row[2] << endl;
				cout << "historyCharacter: " << row[3] << endl;
				cout << "IdSkill: " << row[4] << endl;
				cout << "IdWeapon: " << row[5] << endl;
			}
			break;
		case (int)TableNames::PLAYERS:
			while (row = mysql_fetch_row(res))
			{
				cout << endl;
				cout << "IdPlayer: " << row[0] << endl;
				cout << "IdUser: " << row[1] << endl;
				cout << "characterSelected: " << row[2] << endl;
			}
			break;
		}
	}
	else
	{
		throw ERROR_CALL_NOT_IMPLEMENTED;
	}
	system("pause");
}
void InsertTableData(string tableName)
{
	system("cls");
	string userName;
	int userPasword;
	cout << "Ingrese el Nombre" << endl;
	cout << "User ---> ";
	cin >> userName;
	cout << "Ingrese la contrasenia" << endl;
	cout << "User ---> ";
	cin >> userPasword;

	string comand = "insert into " + tableName + " (UserName,UserPasword) values ('" + userName + "'," + to_string(userPasword) + ")";
	query = comand.c_str();
	status = mysql_query(conectionStatus, query);

	if (!status)
		cout << "Data Saved" << endl;
	else
		throw ERROR_CALL_NOT_IMPLEMENTED;

	system("pause");
	system("cls");
}
void UpdateTableData(string tableName)
{
	system("cls");
	string columToChange;
	string valueToChange;
	string columName;
	int columId;

	ReadTableData(tableName);

	cout << "Select the Comlum Name To Change" << endl;
	cout << "User ---> ";
	cin >> columToChange;
	cout << "Enter the Value" << endl;
	cout << "User ---> ";
	cin >> valueToChange;
	cout << "Enter the ID" << endl;
	cout << "User ---> ";
	cin >> columId;

	string comand = "update " + tableName + " set " + columToChange + " = '" + valueToChange + "' where UserId = " + to_string(columId);
	query = comand.c_str();
	status = mysql_query(conectionStatus, query);

	if (!status)
		cout << "Data Updated" << endl;
	else
		throw ERROR_CALL_NOT_IMPLEMENTED;

	system("pause");
	system("cls");
}
void DeleteTableData(string tableName)
{
	ReadTableData(tableName);
	int columId;

	cout << "Enter the ID to DELETE" << endl;
	cout << "User ---> ";
	cin >> columId;

	string comand = "delete from " + tableName + " where UserId = " + to_string(columId);
	query = comand.c_str();
	status = mysql_query(conectionStatus, query);

	if (!status)
		cout << "User Deleted" << endl;
	else
		throw ERROR_CALL_NOT_IMPLEMENTED;

	system("pause");
	system("cls");
}