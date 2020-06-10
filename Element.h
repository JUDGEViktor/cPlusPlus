#pragma once
#include "Libraries.h"

enum OBJECT_NAME {
	OBJ_NONE,
	OBJ_MENU,
	OBJ_CANVAS,
	OBJ_WINDOW,
	OBJ_BUTTON,
};


enum OPERATION_NAME {
	OP_NONE,
	OP_BEGIN,
	OP_END,
	OP_COLOR,
	OP_NAME,
	OP_FRAME
};

class Element {

protected:

	OBJECT_NAME object;

	colorRGB color;

	FRAME frame;

	string name;

public:

	friend class ParseFile;

	Element(OBJECT_NAME newObject) {
		object = newObject;
	}

	void SetObject(OBJECT_NAME newobject) {
		object = newobject;
	}

	void SetColor(vector<float> numbers);

	void SetFrame(vector<float> numbers);

	void SetName(string newName) {
		name = newName;
	}
};
