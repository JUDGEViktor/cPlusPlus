#pragma once
#include "Libraries.h"
#include "MenuEntity.h"


enum BUTTON_TYPE {
	ERASER,
	PENCIL,
	LINE,
	RECTANGLE,
	CIRCLE,
	WIDTH,
};


enum COLORS {
	RED,
	BLUE,
	YELLOW
};


enum WIDTH_TYPE {
	THIN,
	MEDIUM,
	THICK
};


class Button : public MenuEntity {

public:

	Button(const FRAME& setFrame, const colorRGB& setColor, const string& setName) : MenuEntity(setFrame, setColor, setName) {}

	bool operator == (const Button& c) {
		return (c.name == name);
	}

	BUTTON_TYPE getCurInstrument();

	COLORS getCurColor();

	WIDTH_TYPE getCurWidth();

};