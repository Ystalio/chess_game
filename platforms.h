#ifndef _PLATFORMS_H
#define _PLATFORMS_H

/**
 * Place for platform abstraction functions (clear the terminal screen, change
 * font color, etc...)
 */

enum term_colors {
	TCOLOR_WHITE,
	TCOLOR_BLACK,
	TCOLOR_RED,
	//XXX add others?
};

/**
 * Change the foreground/background colors of the terminal.
 */
void term_color_set(enum term_colors fore, enum term_colors back);

/**
 * Clear the whole display area...
 */
void term_clear(void);


#endif //_PLATFORMS_H
