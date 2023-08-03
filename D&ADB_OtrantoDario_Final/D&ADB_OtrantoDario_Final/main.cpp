#include "mysql.h"
#include <iostream>

using namespace std;

MYSQL* conectionStatus;
int pointer;

bool programOn = true;

void CheckServerConection();

void main()
{
	int answ;
	do
	{
		CheckServerConection();

		system("cls");
		cout << "1 _ Ingresar Data" << endl;
		cout << "2 _ Updatear Data" << endl;
		cout << "3 _ Leer Data" << endl;
		cout << "4 _ Borrar Data" << endl;
		cout << "User ---> ";
		cin >> answ;

		switch (answ)
		{
		case 1:
			cout << "Ingresar Data" << endl;
			system("pause");
			break;
		case 2:
			cout << "Updatear Data" << endl;
			system("pause");
			break;
		case 3:
			cout << "Leer Data" << endl;
			system("pause");
			break;
		case 4:
			cout << "Borrar Data" << endl;
			system("pause");
			break;
		default:
			cout << "Error" << endl;
			system("pause");
			break;
		}
	} while (programOn);
}
void CheckServerConection()
{
	system("cls");

	const char dataBaseHost[] = "127.0.0.1";
	const char dataBaseUser[] = "root";
	const char dataBasePasword[] = "153624";
	const char dataBaseName[] = "DIM_DataBaseEdition";
	const int port = 3306;

	conectionStatus = mysql_init(NULL);
	conectionStatus = mysql_real_connect(conectionStatus, dataBaseHost,dataBaseUser,dataBasePasword,dataBaseName, port,NULL, NULL);

	if (conectionStatus) 
	{
		cout << "Established Connection" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "Connection not Established" << endl;
		system("pause");
		system("cls");
	}
}