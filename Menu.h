#pragma once
#include "Libraries.h"
#include "Window.h"


class Menu : public MenuEntity {

private:

	vector<Window> windows;

public:

	Menu(FRAME setFrame, colorRGB setColor, string setName) : MenuEntity(setFrame, setColor, setName) {}

	void AddWindow(FRAME frame, colorRGB color, string newName) {
		windows.push_back(Window(frame, color, newName));
	}

	void AddButton(FRAME frame, colorRGB color, string newName) {
		windows.back().AddButton(frame, color, newName);
	}


};