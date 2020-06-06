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


using namespace std;


typedef struct coordinates {
	float x;
	float y;
}coordinates;


typedef struct colorRGB {
	int r;
	int g;
	int b;
}colorRGB;


typedef struct pixel {
	coordinates pixelCoord;
	colorRGB pixelColor;
}pixel;
