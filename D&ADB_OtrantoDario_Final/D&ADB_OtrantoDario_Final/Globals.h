#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

const char uperLeftCorner = 201; // esquina superior izquierda ╔ 
const char uperRightCorner = 187; // esquina superior derecha ╗ 
const char lowerLeftCorner = 200; // esquina inferior izquierda ╚ 
const char lowerRightCorner = 188; // esquina inferior Derecha ╝ 
const char horizontalRow = 205;	// linea horizontal ═ 
const char verticalColumn = 186; // linea vertical ║ 
const char uperConection = 203; // conector superior ╦ 
const char lowerConection = 202; // conector inferior ╩ 
const char horizontalConection = 185; // conector derecho ╣ 
const char verticalConection = 204; // conector izquierdo ╠ 
const char crosConection = 206; // interseccion ╬ 
const char emptySpace = 32;	// valor vacio en el tablero 

enum class Color {BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,WHITE,GRAY,LBLUE,LGREEN,LCYAN,LRED,LMAGENTA,YELLOW,BWHITE};
enum class GameStates {MAINMENU,GAMEPLAY,OPTIONS,RULES,CREDITS,EXIT};

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27
#define SPACE 32

void gotoXY(int X, int Y);
void hidecursor();
int pointer(int maxOption, int minOption, int& pointerCursor);
void showKeys(int xValue, int yValue);
int getScreenWidth();
int getScreenHeight();
void setBackgroundColor(Color color);
void setForegroundColor(Color color);