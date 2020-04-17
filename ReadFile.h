#pragma once
#include "Header.h"
#include "Menu.h"
#include "Element.h"


class ParseFile {

private:

	OBJECT_NAME object;
	OPERATION_NAME operation;

	void* func;

	string line;

	vector <float> numbers;

	string name;

	vector <Element> elements;


	OBJECT_NAME FindObject(string const line);

	OPERATION_NAME FindOperation(string const line);

	void ReplaceTrash(string& line);

	void GetNumbers(string& line, vector <float>& result);

	void GetName(string& line, string& name);
	
	void  GetColor(string& line, vector <float>& result);

	void  GetFrame(string& line, vector <float>& result);



	Element* GetPrevMenu();

	Element* GetPrevWindow();

	Element* GetPrev();


public:

	void ScanFile(ifstream& FILE);

	Menu InitMenu();

};

