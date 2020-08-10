/*
 * Sage Farrenholz (C) 2020
 */

#include <stdio.h>
#include <unistd.h>

#include "memory.h"
#include "chess_state.h"
#include "chess.h"

int main(int argc, char **argv){

	// TODO parse options 

	// Create and initialize game state
	Chess_State* state = init_chess_state(); 

	Move_Error me = free_move(state, 0, 0, 1, 1);
	printf("%x\n",get_piece(state, 1, 1));	
	rm_chess_state(state);
}
