#pragma once
#include "Libraries.h"

constexpr auto PIXEL_SIZE = 1;

struct pixel {
	coordinates pixelCoord;
	colorRGB pixelColor;
};

using Pixels = vector<vector<pixel>>;


class Canvas {

private:

	FRAME frame;

	string name;

	Pixels board;

	void ReplaceComma(string& line);

	vector<int> FindColor(string& line);


public:

	void InitCanvas(const FRAME& setFrame, const string& setName);

	ofstream saveCanvas();

	void downloadCanvas(ifstream& fileToDownload);

	const Pixels getBoard() {
		return board;
	}


};