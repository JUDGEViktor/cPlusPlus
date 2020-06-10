#pragma once
#include "Libraries.h"


class MenuEntity {


protected:

	string name;

	FRAME frame;

	colorRGB color;


public:

	MenuEntity() {}

	MenuEntity(const FRAME& newFrame, const colorRGB& newColor, const string& newName) {
		name = newName;
		frame = newFrame;
		color = newColor;
	}

};