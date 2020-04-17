#pragma once

#include "Header.h"
#include "Menu.h"
#include <windows.h>
#include <stdio.h>


Menu menu({ 0, 0, 0, 0 }, { 0, 0, 0 }, "0");

bool fullscreen = false;
bool mouseDown = false;


void InitMenu(Menu newMenu) {
	menu = newMenu;
}


void DISPLAY() {

	float menu_length = (float) abs( menu.GetFrame().BEGINING_POINT.x -menu.GetFrame().OPPOSIT_POINT.x ) / 2;
	float menu_height = (float) abs( menu.GetFrame().BEGINING_POINT.y - menu.GetFrame().OPPOSIT_POINT.y ) / 2;

	float menu_centre_X = menu_length;
	float menu_centre_Y = menu_height;

	glColor3ub(menu.GetColor().R, menu.GetColor().G, menu.GetColor().B);
	glRectf((menu.GetFrame().BEGINING_POINT.x - menu_centre_X) / menu_length, (menu_centre_Y - menu.GetFrame().BEGINING_POINT.y) / menu_height, (menu.GetFrame().OPPOSIT_POINT.x - menu_centre_X) / menu_length, (menu_centre_Y - menu.GetFrame().OPPOSIT_POINT.y) / menu_height);


	for (vector <Window>::iterator it_windows = menu.GetWindows().begin(); it_windows != menu.GetWindows().end(); it_windows++) {

		glColor3ub((*it_windows).GetColor().R, (*it_windows).GetColor().G, (*it_windows).GetColor().B);
		glRectf( ((*it_windows).GetFrame().BEGINING_POINT.x - menu_centre_X) / menu_length, (menu_centre_Y - (*it_windows).GetFrame().BEGINING_POINT.y) / menu_height,
			((*it_windows).GetFrame().OPPOSIT_POINT.x - menu_centre_X) / menu_length, (menu_centre_Y - (*it_windows).GetFrame().OPPOSIT_POINT.y) / menu_height );

		for (vector <Button>::iterator it_buttons = (*it_windows).GetButtons().begin(); it_buttons != (*it_windows).GetButtons().end(); it_buttons++) {
			glColor3ub((*it_buttons).GetColor().R, (*it_buttons).GetColor().G, (*it_buttons).GetColor().B);
			glRectf( ((*it_buttons).GetFrame().BEGINING_POINT.x - menu_centre_X ) / menu_length, (menu_centre_Y - (*it_buttons).GetFrame().BEGINING_POINT.y) / menu_height,
				((*it_buttons).GetFrame().OPPOSIT_POINT.x - menu_centre_X) / menu_length, (menu_centre_Y - (*it_buttons).GetFrame().OPPOSIT_POINT.y ) / menu_height );
		}
	}

	glFlush();

}


/*Button SearchForButton(int x, int y) {

	for (vector <Window>::iterator it_windows = menu.GetWindows().begin(); it_windows != menu.GetWindows().end(); it_windows++) {
		for (vector <Button>::iterator it_buttons = (*it_windows).GetButtons().begin(); it_buttons != (*it_windows).GetButtons().end(); it_buttons++) {

			if ( (float)x >= (*it_buttons).GetFrame().BEGINING_POINT.x && (float)x <= (*it_buttons).GetFrame().OPPOSIT_POINT.x
				&& (float)y >= (*it_buttons).GetFrame().OPPOSIT_POINT.y && (float)y <= (*it_buttons).GetFrame().OPPOSIT_POINT.y) {
				return (*it_buttons);
			}

		}
	}

}*/


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(1); break;
	}
}

void specialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
	{
		fullscreen = !fullscreen;

		if (fullscreen)
			glutFullScreen();
		else
		{
			glutReshapeWindow(500, 500);
			glutPositionWindow(50, 50);
		}
	}
}

/*void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Button curButton = SearchForButton(x, y);
		//curButton.DoFunc();
	}
	else
		mouseDown = false;
}*/



void DRAW(Menu menu) {

	InitMenu(menu);

	glutInitWindowSize(abs( menu.GetFrame().BEGINING_POINT.x - menu.GetFrame().OPPOSIT_POINT.x ), abs( menu.GetFrame().BEGINING_POINT.y - menu.GetFrame().OPPOSIT_POINT.y ));
	glutInitWindowPosition(menu.GetFrame().BEGINING_POINT.x, menu.GetFrame().BEGINING_POINT.y);

	glutCreateWindow("OpenGL window");
	glClearColor(0, 0, 1, 1);

	glutDisplayFunc(DISPLAY);

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	//glutMouseFunc(mouse);
	glutMainLoop();
}




