#pragma once
#include "Header.h"
#include "Menu.h"
#include "Element.h"


/*class Element {

protected:

	OBJECT_NAME object;

	COLOR color;
	FRAME frame;
	string name;

public:

	Element(OBJECT_NAME newObject) {
		object = newObject;
	}

	COLOR GetColor() {
		return color;
	}

	FRAME Getframe() {
		return frame;
	}

	string GetName() {
		return name;
	}

	OBJECT_NAME GetMyObject() {
		return object;
	}

	void SetObject(OBJECT_NAME newobject) {
		object = newobject;
	}

	void SetColor(vector <float>& numbers) {
		color.R = numbers[0];
		color.G = numbers[1];
		color.B = numbers[2];
	}

	void SetFrame(vector <float>& numbers) {
		frame.BEGINING_POINT.x = numbers[0];
		frame.BEGINING_POINT.y = numbers[1];

		frame.HEIGHT = numbers[2];
		frame.LENGTH = numbers[3];
	}

	void SetName(string newName) {
		name = newName;
	}

};*/




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

