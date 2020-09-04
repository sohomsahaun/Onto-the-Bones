#ifndef __INIT
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "iGraphics.h"
#define __INIT
#endif

int hdir, vdir;
void input_refresh() {
	hdir = vdir = 0;
}

void iPassiveMouse(int x, int y) {}
void iMouseMove(int mx, int my) {}
void iMouse(int button, int state, int mx, int my){}
void iKeyboard(unsigned char key) {
	input_refresh();
	switch (key) {
		case 'd': hdir =  1; break;
		case 'a': hdir = -1; break;
		case 'w': vdir =  1; break;
		case 's': vdir = -1; break;
		default: break;
	}
}
void iSpecialKeyboard(unsigned char key) {
	input_refresh();
	switch (key) {
		case GLUT_KEY_RIGHT: hdir =  1; break;
		case GLUT_KEY_LEFT : hdir = -1; break;
		case GLUT_KEY_UP   : vdir =  1; break;
		case GLUT_KEY_DOWN : vdir = -1; break;
		default: break;
	}
}