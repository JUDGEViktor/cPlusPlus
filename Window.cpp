#include "stdafx.h"
#include "Window.h"

Button* Window::AddButton(const FRAME& frame, const colorRGB& color, const string& newName) {
	buttons.push_back(Button(frame, color, newName));
	return &buttons.back();
}

vector<Button>* Window::getButtons() {
	return &buttons;
}

FUNCTION_TO_DO Window::getCurFunction() {
	if (name == "BRUSH_TYPES")
		return CHANGE_INSTRUMENT;
	if (name == "COLORS")
		return CHANGE_COLOR;
	if (name == "WIDTH")
		return CHANGE_WIDTH;
}