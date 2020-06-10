#include "stdafx.h"
#include "User.h"

void User::changeInstrument() {
	switch (instruments.knowCurInstrument()) {

	case PENCIL:
		curInstrument = new Pencil();
		break;

	case ERASER:
		curInstrument = new Eraser();
		break;

	case RECTANGLE:
		curInstrument = new FigureRectangle();
		break;

	case CIRCLE:
		curInstrument = new FigureCircle();
		break;
	}

}

void User::ChangeColor() {
	switch (instruments.knowCurColor()) {
	case RED:
		curInstrument->setColor({ 255, 0, 0 });
		break;

	case YELLOW:
		curInstrument->setColor({ 255, 255, 0 });
		break;

	case BLUE:
		curInstrument->setColor({ 0, 0, 255 });
		break;

	}
}

void User::ChangeWidth() {
	switch (instruments.knowCurWidth()) {
	case THIN:
		curInstrument->setWidth(1);
		break;

	case MEDIUM:
		curInstrument->setWidth(2);
		break;

	case THICK:
		curInstrument->setWidth(4);
		break;
	}
}

ofstream User::saveFile() {
	return canvas.saveCanvas();
}

void User::downloadFile(ifstream& fileToSave) {
	canvas.downloadCanvas(fileToSave);
}

void User::actionWithInstrument(POINT cursorPos) {
	curInstrument->action({ cursorPos.x, cursorPos.y });
}

void User::draw(HDC hdc) {
	drawCanvas(hdc, canvas.getBoard());
	curInstrument->draw(hdc);
}

void User::initMenu(ifstream& FILE) {
	script.ScanFile(FILE);
	script.InitMenu(instruments, canvas);
	curInstrument = new Pencil;
}

void User::changeWindow(GO_TO pos) {
	instruments.goToNeccesaryWindow(pos);
}

void User::changeButton(GO_TO pos) {
	instruments.goToNeccesaryButton(pos);
}

void User::browseMenu() {
	FUNCTION_TO_DO curFunction = instruments.knowfunctionToDo();

	switch (curFunction) {
	case CHANGE_INSTRUMENT:
		changeInstrument();
		break;

	case CHANGE_COLOR:
		ChangeColor();
		break;

	case CHANGE_WIDTH:
		ChangeWidth();
		break;
	}


}