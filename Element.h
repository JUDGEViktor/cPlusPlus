#pragma once
#include "Header.h"

class Element {

protected:

	OBJECT_NAME object;

	COLOR color;
	FRAME frame;
	string name;
	void(*func)();

public:

	Element(OBJECT_NAME newObject) {
		object = newObject;
	}

	COLOR GetColor() {
		return color;
	}

	FRAME Getframe() {
		return frame;
	}

	string GetName() {
		return name;
	}

	OBJECT_NAME GetMyObject() {
		return object;
	}

	void SetObject(OBJECT_NAME newobject) {
		object = newobject;
	}

	void SetColor(vector <float>& numbers) {
		color.R = numbers[0];
		color.G = numbers[1];
		color.B = numbers[2];
	}

	void SetFrame(vector <float>& numbers) {
		frame.BEGINING_POINT.x = numbers[0];
		frame.BEGINING_POINT.y = numbers[1];

		frame.OPPOSIT_POINT.x = numbers[2];
		frame.OPPOSIT_POINT.y = numbers[3];
	}

	void SetName(string newName) {
		name = newName;
	}
};
