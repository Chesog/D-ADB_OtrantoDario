#include "globals.h"

void gotoXY(int X, int Y) // Funcion para Mover el cursor a distintas cordenadas del tablero
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)X,(short)Y });
}
void hidecursor()	//Funcion para esconder el cursor
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
int pointer(int maxOption, int minOption, int& pointerCursor) // cursor para el menu
{
	COORD consolecursorposition = { 0,0 };

	int defaultOption = 0;
	int max = maxOption;
	int min = minOption;
	char cursor;
	cursor = _getch();
	switch (cursor)
	{
	case ARRIBA:
		pointerCursor--;
		if (pointerCursor < min)
		{
			pointerCursor = max;
		}
		return defaultOption;
		break;
	case ABAJO:
		pointerCursor++;
		if (pointerCursor > max)
		{
			pointerCursor = min;
		}
		return defaultOption;
		break;
	case SPACE:
		return pointerCursor;
		break;
	default:
		return defaultOption;
		break;
	}

}
void showKeys(int xValue, int yValue)  // Funcion para mostrar los controles en el menu
{
	gotoXY(xValue, yValue++);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(xValue, yValue++);
	cout << verticalColumn << " ^ " << verticalColumn << " Para Subir" << endl;
	gotoXY(xValue, yValue++);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	gotoXY(xValue, yValue++);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(xValue, yValue++);
	cout << verticalColumn << " v " << verticalColumn << " Para Bajar" << endl;
	gotoXY(xValue, yValue++);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
	gotoXY(xValue - 2, yValue++);
	cout << uperLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << uperRightCorner << endl;
	gotoXY(xValue - 2, yValue++);
	cout << verticalColumn << " Space " << verticalColumn << " Para Seleccionar" << endl;
	gotoXY(xValue - 2, yValue++);
	cout << lowerLeftCorner << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << horizontalRow << lowerRightCorner << endl;
}

int getScreenWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	return (!GetConsoleScreenBufferInfo(outputHandle, &screenBufferInfo)) ? 80 : screenBufferInfo.srWindow.Right + 1;
}

int getScreenHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	return (!GetConsoleScreenBufferInfo(outputHandle, &screenBufferInfo)) ? 80 : screenBufferInfo.srWindow.Bottom + 1;
}
void setBackgroundColor(Color color)
{
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wAttrib = 0;
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;

	GetConsoleScreenBufferInfo(outputHandle, &screenBufferInfo);
	wAttrib = screenBufferInfo.wAttributes;

	wAttrib &= ~(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);

	int c = (int)color;

	if (c & 1)
		wAttrib |= BACKGROUND_BLUE;
	if (c & 2)
		wAttrib |= BACKGROUND_GREEN;
	if (c & 4)
		wAttrib |= BACKGROUND_RED;
	if (c & 8)
		wAttrib |= BACKGROUND_INTENSITY;

	SetConsoleTextAttribute(outputHandle, wAttrib);
}

void setForegroundColor(Color color)
{
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wAttrib = 0;
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;

	GetConsoleScreenBufferInfo(outputHandle, &screenBufferInfo);
	wAttrib = screenBufferInfo.wAttributes;

	wAttrib &= ~(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	int c = (int)color;

	if (c & 1)
		wAttrib |= FOREGROUND_BLUE;
	if (c & 2)
		wAttrib |= FOREGROUND_GREEN;
	if (c & 4)
		wAttrib |= FOREGROUND_RED;
	if (c & 8)
		wAttrib |= FOREGROUND_INTENSITY;

	SetConsoleTextAttribute(outputHandle, wAttrib);
}