#include "stdafx.h"
#include "Button.h"


BUTTON_TYPE Button::getCurInstrument() {
	if (name == "eraser")
		return ERASER;
	if (name == "pencil")
		return PENCIL;
	if (name == "line")
		return LINE;
	if (name == "rectangle")
		return RECTANGLE;
	if (name == "circle")
		return CIRCLE;
	if (name == "width")
		return WIDTH;
}


COLORS Button::getCurColor() {
	if (name == "red")
		return RED;
	if (name == "yellow")
		return YELLOW;
	if (name == "blue")
		return BLUE;
}

WIDTH_TYPE Button::getCurWidth() {
	if (name == "thin")
		return THIN;
	if (name == "medium")
		return MEDIUM;
	if (name == "thick")
		return THICK;
}