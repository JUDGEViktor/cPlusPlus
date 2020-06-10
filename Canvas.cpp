#include "stdafx.h"
#include "Canvas.h"


void Canvas::InitCanvas(const FRAME& setFrame, const string& setName) {
	frame = setFrame;
	name = setName;

	int length = abs(frame.BEGINING_POINT.x - frame.OPPOSIT_POINT.x);
	int height = abs(frame.BEGINING_POINT.y - frame.OPPOSIT_POINT.y);

	for (int line = 0; line < length; line++) {
		board.push_back(vector<pixel>());
		for (int column = 0; column < height; column++) {
			board[line].push_back(pixel());
			board[line][column].pixelColor = { 255, 255, 255 };
			board[line][column].pixelCoord = { line, column };
		}
	}
}


ofstream Canvas::saveCanvas() {
	ofstream fileToSave;
	fileToSave.open(name + ".txt");
	for (auto line : board) {
		for (auto column : line) {
			fileToSave << column.pixelColor.r << "," << column.pixelColor.g << ","
				<< column.pixelColor.b << " ";
		}
		fileToSave << endl;
	}
	return fileToSave;
}

void Canvas::ReplaceComma(string& line) {
	string trash = "(),;";
	for (char chr : trash)
		replace(line.begin(), line.end(), chr, ' ');
	return;
}

vector<int> Canvas::FindColor(string& line) {

	vector<int> result;

	ReplaceComma(line);

	stringstream ss;

	ss << line;

	string temp;

	int found;
	while (!ss.eof()) {
		if (stringstream(temp) >> found)
			result.push_back((int)found);

		ss >> temp;
	}
	return result;
}

void Canvas::downloadCanvas(ifstream& fileToDownload){
	string line;
	int i, j;
	for (i = 0; getline(fileToDownload, line); i++) {
		board.push_back(vector<pixel>());
		istringstream iss(line);
		vector<std::string> tokens;
		copy(istream_iterator<std::string>(iss),
			istream_iterator<std::string>(),
			back_inserter<std::vector<std::string>>(tokens));
		
		for (j = 0; j < tokens.size(); j++) {
			vector <int> color = FindColor(tokens.at(j));
			board[j].push_back(pixel());
			board[i][j].pixelColor = { color[0], color[1], color[2] };
			board[i][j].pixelCoord = { i, j };
		}
	}

}