#pragma once
#include "Header.h"
#include "Button.h"

class Element;

class Window : public MyRectangle{

private:

	string name;
	vector<Button> buttons;

public:

	Window(FRAME frame, COLOR color, string newName) : MyRectangle(frame, color) { name = newName; }

	void AddButton(FRAME frame, COLOR color, string newName) {
		buttons.push_back(Button(frame, color, newName));
	}

	vector <Button> & GetButtons() {
		return buttons;
	}


};
