#pragma once
#include "Header.h"
#include "Rectangle.h"


class Button : public MyRectangle{

private:

	string name;

	STATUS status;

	void(*func)();

public:

	Button(FRAME frame, COLOR color, string newName) : MyRectangle(frame, color) { name = newName; status = NOT_ACTIVE; }

};