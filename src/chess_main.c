/* Copyright (c) 2021, Sage Farrenholz */

#include <stdlib.h>

#include <ncurses.h>

#include "chess.h"

int main(int argc, char** argv) {
	
	Chess_State* state = chess_state_init(false);	
	chess_state_destroy(state);

	return EXIT_SUCCESS;
}
