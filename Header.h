#pragma once
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
#include <GL\glut.h>


using namespace std;



struct coordinates {
	float x;
	float y;
};


enum OBJECT_NAME {
	OBJ_NONE = -2,
	OBJ_MENU = 1,
	OBJ_WINDOW = 2,
	OBJ_BUTTON = 3,
};


enum OPERATION_NAME {
	OP_NONE = 0,
	OP_BEGIN = 1,
	OP_END = 11,
	OP_COLOR = 101,
	OP_NAME = 10001,
	OP_FRAME = 100001
};


enum STATUS {
	ACTIVE = 0,
	NOT_ACTIVE = 1
};


struct COLOR {
	int R;
	int G;
	int B;
};

struct FRAME {
	coordinates BEGINING_POINT;
	coordinates OPPOSIT_POINT;
};

