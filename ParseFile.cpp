#include "stdafx.h"
#include "ParseFile.h"


OBJECT_NAME ParseFile::FindObject(string const line) {
	if (line.find("menu.") != string::npos)
		return OBJ_MENU;
	if (line.find("canvas.") != string::npos)
		return OBJ_CANVAS;
	if (line.find("window.") != string::npos)
		return OBJ_WINDOW;
	if (line.find("button.") != string::npos)
		return OBJ_BUTTON;
	return OBJ_NONE;
}

OPERATION_NAME ParseFile::FindOperation(string const line) {
	if (line.find("begin:") != string::npos)
		return OP_BEGIN;
	if (line.find("end") != string::npos)
		return OP_END;
	if (line.find("color") != string::npos)
		return OP_COLOR;
	if (line.find("name") != string::npos)
		return OP_NAME;
	if (line.find("frame") != string::npos)
		return OP_FRAME;
	return OP_NONE;
}

void ParseFile::ReplaceTrash(string& line) {
	string trash = "(),;";
	for (char chr : trash)
		replace(line.begin(), line.end(), chr, ' ');
	return;
}

vector<float> ParseFile::FindNumbers(string& line) {

	vector<float> result;

	ReplaceTrash(line);

	stringstream ss;

	ss << line;

	string temp;

	float found;
	while (!ss.eof()) {
		if (stringstream(temp) >> found)
			result.push_back((float)found);

		ss >> temp;
	}
	return result;
}

string ParseFile::FindName(string& line) {

	string result;

	ReplaceTrash(line);

	stringstream ss;

	ss << line;

	string temp;

	string found;
	while (!ss.eof()) {
		if (stringstream(temp) >> found)
			result = found;

		ss >> temp;
	}
	return result;
}

vector<float> ParseFile::FindColor(string& line){ 
	return FindNumbers(line);
}

vector<float> ParseFile::FindFrame(string& line) {
	return FindNumbers(line);
}


Element* ParseFile::Find(OBJECT_NAME objectToFind) {

	for (vector <Element>::iterator it = elements.end() - 1; it != elements.begin(); it--) {
		if (it->object == objectToFind)
			return &(*it);
	}
}



Element* ParseFile::GetPrevMenu() {

	return(Find(OBJ_MENU));
}

Element* ParseFile::GetPrevWindow() {

	return(Find(OBJ_WINDOW));
}

Element* ParseFile::GetPrev() {
	switch (elements.back().object) {
	case OBJ_WINDOW:
		return GetPrevMenu();

	case OBJ_BUTTON:
		return GetPrevWindow();
	}
}

void ParseFile::ScanFile(ifstream& FILE) {

	Element* curObject = nullptr;

	OPERATION_NAME curOperation;

	string line; 

	string name;

	while (getline(FILE, line)) {

		curOperation = FindOperation(line);

		switch (curOperation) {
		case OP_BEGIN:
			elements.push_back(Element(FindObject(line)));
			curObject = &elements.back();
			break;

		case OP_END:
			curObject = GetPrev();
			break;

		case OP_COLOR:
			curObject->SetColor(FindColor(line));
			break;

		case OP_FRAME:
			curObject->SetFrame(FindFrame(line));
			break;

		case OP_NAME:
			curObject->SetName(FindName(line));
			break;

		case OP_NONE:
			break;
		}


	}
}


void ParseFile::InitMenu(InstrumentPanel& instruments, Canvas& canvas) {

	for (auto element : elements) {

		switch (element.object) {

		case OBJ_MENU:
			instruments.InitMenu(element.frame, element.color, element.name);
			//menu = Menu(element.frame, element.color, element.name);
			break;

		case OBJ_CANVAS:
			canvas.InitCanvas(element.frame, element.name);
			break;

		case OBJ_WINDOW:
			instruments.AddWindow(element.frame, element.color, element.name);
			break;

		case OBJ_BUTTON:
			instruments.AddButton(element.frame, element.color, element.name);
			break;

		}

	}
}