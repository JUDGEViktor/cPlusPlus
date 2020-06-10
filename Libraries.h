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
#include<list>

using namespace std;

struct coordinates {
	int x;
	int y;
};

struct colorRGB {
	int r;
	int g;
	int b;
};

struct FRAME {
	coordinates BEGINING_POINT;
	coordinates OPPOSIT_POINT;
};
