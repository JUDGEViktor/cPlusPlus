#pragma once
#include <GL\glut.h>
#include<windows.h>
#include<iostream>
#include<vector>
#include<iterator>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<memory>
using namespace std;



enum status {
	NON,
	FRIGHTENED,
	//....//
};


struct coordinates {
	int x;
	int y;
};


enum directions {
	NORTH, 
	SOUTH, 
	WEST, 
	EAST
};


enum bonuses {
	REGULAR_POINT = 10,    //Обычная точка
	ENERGIZER = 50, 
	FRUIT[] = {},
	GHOST[] = {200, 400, 800, 1600},

};

