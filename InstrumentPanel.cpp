#include "stdafx.h"
#include "InstrumentPanel.h"


void InstrumentPanel::InitMenu(const FRAME& setFrame, const colorRGB& setColor, const string& setName) {
	frame = setFrame;
	color = setColor;
	name = setName;
	curWindow = nullptr;
	curButton = nullptr;
}

void InstrumentPanel::AddWindow(const FRAME& frame, const colorRGB& color, const string& newName) {
	windows.push_back(Window(frame, color, newName));
	curWindow = &windows.back();
}

void InstrumentPanel::AddButton(const FRAME& frame, const colorRGB& color, const string& newName) {
	curButton = windows.back().AddButton(frame, color, newName);
}



Window* InstrumentPanel::goToNeccesaryWindow(GO_TO pos) {
	switch (pos) {
	case NEXT:
		if (*curWindow == windows.back())
			curWindow = &windows.front();
		else
			curWindow = std::next(curWindow, 1);
		break;

	case PREV:
		if (*curWindow == windows.front())
			curWindow = &windows.back();
		else
			curWindow = std::prev(curWindow, 1);
		break;
	}

	curButton = &curWindow->getButtons()->back();
	return curWindow;
}


Button* InstrumentPanel::goToNeccesaryButton(GO_TO pos) {
	switch (pos) {
	case NEXT:
		if (*curButton == curWindow->getButtons()->back())
			curButton = &curWindow->getButtons()->front();
		else
			curButton = std::next(curButton, 1);
		break;

	case PREV:
		if (*curButton == curWindow->getButtons()->front())
			curButton = &curWindow->getButtons()->back();
		else
			curButton = std::prev(curButton, 1);
		break;
	}

	return curButton;
}