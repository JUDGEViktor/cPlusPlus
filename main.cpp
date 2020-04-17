#include "Header.h"
#include "ReadFile.h"
#include "graphics.h"




int main(int argc, char **argv)
{
	ParseFile script;
	ifstream inFile;
	inFile.open("menu.txt", std::ifstream::in);


	script.ScanFile(inFile);
	Menu menu = script.InitMenu();

	DRAW(menu);
	
	return 0;
}