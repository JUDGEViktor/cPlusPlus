#pragma once
#include "Libraries.h"
#include "Button.h"

enum FUNCTION_TO_DO {
	CHANGE_INSTRUMENT,
	CHANGE_COLOR,
	CHANGE_WIDTH
};


class Window : public MenuEntity {

private:

	vector<Button> buttons;


public:

	Window(const FRAME& setFrame, const colorRGB& setColor, const string& setName) : MenuEntity(setFrame, setColor, setName) {}

	bool operator == (const Window& c) {
		return (c.name == name);
	}

	Button* AddButton(const FRAME& frame, const colorRGB& color, const string& newName);

	vector<Button>* getButtons();

	FUNCTION_TO_DO getCurFunction();

};
