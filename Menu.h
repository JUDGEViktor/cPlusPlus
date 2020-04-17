#pragma once
#include "Header.h"
#include "Window.h"


class Menu : public MyRectangle{

private:

	string name;
	vector<Window> windows;

public:

	vector<Window> & GetWindows() {
		return windows;
	}

	Menu(FRAME frame, COLOR color, string newName) : MyRectangle( frame, color ) { name = newName; }

	void AddWindow(FRAME frame, COLOR color, string newName) {
		windows.push_back( Window(frame, color, newName));
	}

	void AddButton(FRAME frame, COLOR color, string newName) {
		windows.back().AddButton(frame, color, newName);
	}

};