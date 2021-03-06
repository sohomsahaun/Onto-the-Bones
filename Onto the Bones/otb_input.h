#define KEY_BACKSPACE 8
#define KEY_ENTER 13
#define KEY_ESC	  27
#define KEY_SPACE 32

int hdir, vdir, skip, interact, restart, pause;
bool Typing = false, GameWon = false;
std::string Name;

void input_refresh() {
	hdir = 0;
	vdir = 0;
	skip = 0;
	interact = 0;
	restart = 0;
	pause = 0;
}

void iPassiveMouse(int x, int y) {}
void iMouseMove(int mx, int my) {}
void iMouse(int button, int state, int mx, int my){}
void iKeyboard(unsigned char key) {
	if (Typing) {
		switch (key) {
			case '\r':
				GameWon = true;
			break;
			case KEY_SPACE:
				// Do not allow spaces	
			break;
			case KEY_BACKSPACE:
				if (!Name.empty()) Name.pop_back();
			break;
			default:
				if (Name.size() < MAX_NAME_LENGTH) Name += key;
			break;

		}
	} else {
		input_refresh();
		switch (key) {
			case 'd': hdir =  1; break;
			case 'a': hdir = -1; break;
			case 'w': vdir =  1; break;
			case 's': vdir = -1; break;
			case 'q': skip =  1; break;
			case 'r': restart =  1; break;
			case 'e': interact = 1; break;

			case KEY_SPACE: skip =  1;	  break;
			case KEY_ENTER: interact = 1; break;
			case KEY_ESC  : pause = 1;	  break;
			default: break;
		}
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