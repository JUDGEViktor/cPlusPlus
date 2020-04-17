#include "ReadFile.h"


OBJECT_NAME ParseFile::FindObject(string const line) {
	if (line.find("menu.") != string::npos)
		return OBJ_MENU;
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

void ParseFile::GetNumbers(string& line, vector <float>& result) {

	result.clear();

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
	return;
}

void ParseFile::GetName(string& line, string& name) {

	ReplaceTrash(line);

	stringstream ss;

	ss << line;

	string temp;

	string found;
	while (!ss.eof()) {
		if (stringstream(temp) >> found)
			name = found;

		ss >> temp;
	}
	return;
}

void  ParseFile::GetColor(string& line, vector <float>& result) {
	GetNumbers(line, result);
	return;
}

void  ParseFile::GetFrame(string& line, vector <float>& result) {
	GetNumbers(line, result);
	return;
}



Element* ParseFile::GetPrevMenu() {
	for (vector <Element>::iterator it = elements.end() - 1; it != elements.end(); it--) {
		if ((*it).GetMyObject() == OBJ_MENU)
			return &(*it);
	}
}

Element* ParseFile::GetPrevWindow() {
	for (vector <Element>::iterator it = elements.end() - 1; it != elements.begin(); it--) {
		if ((*it).GetMyObject() == OBJ_WINDOW)
			return &(*it);
	}
}

Element* ParseFile::GetPrev() {
	switch (elements.back().GetMyObject()) {
	case OBJ_WINDOW:
		return GetPrevMenu();

	case OBJ_BUTTON:
		return GetPrevWindow();
	}
}

void ParseFile::ScanFile(ifstream& FILE) {
	int count_ends = 1;
	Element* curObject = nullptr;
	while (getline(FILE, line)) {

		object = FindObject(line);
		operation = FindOperation(line);

		switch (operation) {
		case OP_BEGIN:
			elements.push_back(Element(object));
			curObject = &elements.back();
			break;

		case OP_END:
			curObject = GetPrev();
			break;

		case OP_COLOR:
			GetColor(line, numbers);
			curObject->SetColor(numbers);
			break;

		case OP_FRAME:
			GetFrame(line, numbers);
			curObject->SetFrame(numbers);
			break;

		case OP_NAME:
			GetName(line, name);
			curObject->SetName(name);
			break;
		case OP_NONE:
			break;
		}


	}
}


Menu ParseFile::InitMenu() {

	Menu menu({ 0, 0, 0, 0 }, { 0, 0, 0 }, "0");

	for (vector <Element>::iterator it = elements.begin(); it != elements.end(); it++) {

		switch ((*it).GetMyObject()) {

		case OBJ_MENU:
			menu = Menu((*it).Getframe(), (*it).GetColor(), (*it).GetName());
			break;

		case OBJ_WINDOW:
			menu.AddWindow((*it).Getframe(), (*it).GetColor(), (*it).GetName());
			break;

		case OBJ_BUTTON:
			menu.AddButton((*it).Getframe(), (*it).GetColor(), (*it).GetName());
			break;

		}

	}
	return menu;
}