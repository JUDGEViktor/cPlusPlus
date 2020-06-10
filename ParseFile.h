#pragma once
#include "Libraries.h"
#include "InstrumentPanel.h"
#include "Canvas.h"
#include "Element.h"


class ParseFile {

private:

	vector <Element> elements;


	OBJECT_NAME FindObject(string const line);

	OPERATION_NAME FindOperation(string const line);

	void ReplaceTrash(string& line);

	vector<float> FindNumbers(string& line);

	string FindName(string& line);

	vector<float> FindColor(string& line);

	vector<float> FindFrame(string& line);


	Element* Find(OBJECT_NAME objectToFind);

	Element* GetPrevMenu();

	Element* GetPrevWindow();

	Element* GetPrev();


public:

	void ScanFile(ifstream& FILE);

	void InitMenu(InstrumentPanel& instruments, Canvas& canvas);

};

