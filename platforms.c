#include "platforms.h"
#include <stdio.h>

#ifdef __WIN32__
// Windows platform...
#include <windows.h>
#include <stdlib.h>

int color_to_wincode(enum term_colors color) {
	switch(color){
	case TCOLOR_WHITE:
		return 15;
	case TCOLOR_BLACK:
		return 0;
	case TCOLOR_RED:
		return 12; //just the red which was too dark
	}

	return 0;
}

void term_color_set(enum term_colors fore, enum term_colors back) {

	// convert to Windows codes
	int code = color_to_wincode(fore) + color_to_wincode(back)*16;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, code);
}


void term_clear(void) {
	system("cls");
}

void flush_stdin(void) {
	int c;
	do {
		c = getchar();
	} while(c != '\n' && c != EOF);
}


#else //__WIN32__
// non-windows platforms (assume UNIX-like, with more or less POSIX compliance)

int color_to_vtcode(enum term_colors color) {
	switch(color) {
	case TCOLOR_WHITE:
		return 7;
	case TCOLOR_BLACK:
		return 0;
	case TCOLOR_RED:
		return 1;
	}

	return 0;
}

void term_color_set(enum term_colors fore, enum term_colors back) {
	// not really clean and a bit error-prone, but should work

	printf("\x1B[%d;%dm", color_to_vtcode(fore)+30, color_to_vtcode(back)+40);
	fflush(stdout);
}



void term_clear(void) {
	printf("\x1B[2J\x1B[H");
	fflush(stdout);
}

void flush_stdin(void) {
	// don't know why there is no good way to do that in POSIX spec...
	int c;
	do {
		c = getchar();
	} while(c != '\n' && c != EOF);
}

#endif
