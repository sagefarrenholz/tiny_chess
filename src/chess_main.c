/* Copyright (c) 2021, Sage Farrenholz */

#include <stdlib.h>

#include <ncurses.h>

#include "chess.h"

int main(int argc, char** argv) {
	
	initscr();
	printw("Test!");
	refresh();
	getch();
	endwin();

	return EXIT_SUCCESS;
}
