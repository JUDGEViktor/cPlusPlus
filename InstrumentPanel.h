#pragma once
#include "Libraries.h"
#include "Window.h"


enum GO_TO {
	PREV,
	NEXT
};


class InstrumentPanel : public MenuEntity {

private:

	vector<Window> windows;

	Window* curWindow;

	Button* curButton;

public:

	InstrumentPanel() : MenuEntity() {}

	void InitMenu(const FRAME& setFrame, const colorRGB& setColor, const string& setName);

	void AddWindow(const FRAME& frame, const colorRGB& color, const string& newName);

	void AddButton(const FRAME& frame, const colorRGB& color, const string& newName);



	Window* goToNeccesaryWindow(GO_TO pos);

	
	Button* goToNeccesaryButton(GO_TO pos);


	FUNCTION_TO_DO knowfunctionToDo() {
		return curWindow->getCurFunction();
	}

	BUTTON_TYPE knowCurInstrument() {
		return curButton->getCurInstrument();
	}

	COLORS knowCurColor() {
		return curButton->getCurColor();
	}

	WIDTH_TYPE knowCurWidth() {
		return curButton->getCurWidth();
	}

};
