#pragma once
#include "Libraries.h"
#include "BrushAbstract.h"
#include "Eraser.h"
#include "Pencil.h"
#include "FigureRectangle.h"
#include "FigureCircle.h"
#include "ParseFile.h"
#include "InstrumentPanel.h"
#include "Canvas.h"
#include "Graphics.h"


class User : public Graphics {

private:

	BrushAbstract* curInstrument;

	ParseFile script;

	Canvas canvas;

	InstrumentPanel instruments;

	void changeInstrument();

	void ChangeColor();

	void ChangeWidth();

public:

	void actionWithInstrument(POINT cursorPos);

	void draw(HDC hdc);

	void initMenu(ifstream& FILE);

	void changeWindow(GO_TO pos);

	void changeButton(GO_TO pos);

	void browseMenu();

	ofstream saveFile();

	void downloadFile(ifstream& fileToSave);

};