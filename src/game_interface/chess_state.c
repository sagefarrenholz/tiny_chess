/*
 * Sage Farrenholz (C) 2020
 */

#include <string.h>

#include "chess_state.h"

typedef unsigned u;

static u coortoidx(u x, u y){ return x + y * 8; }

Chess_State* chess_state_init(Chess_Board board) {
	
	Chess_State* state = (Chess_State*) malloc(sizeof(Game_State));

	if (board == NULL) {
	
		// Set starting positions
		Board start_pos = {

		BLACK | ROOK,  BLACK | KNIGHT,  BLACK | BISHOP,  BLACK | QUEEN,  BLACK | KING,  BLACK | BISHOP,  BLACK | KNIGHT,  BLACK | ROOK,

		BLACK | PAWN,  BLACK | PAWN,    BLACK | PAWN,    BLACK | PAWN,   BLACK | PAWN,  BLACK | PAWN,    BLACK | PAWN,    BLACK | PAWN,

		    EMPTY,         EMPTY,           EMPTY,           EMPTY,          EMPTY,         EMPTY, 	      EMPTY,          EMPTY,	

		    EMPTY,         EMPTY,           EMPTY,           EMPTY,          EMPTY,         EMPTY, 	      EMPTY,          EMPTY,	

		    EMPTY,         EMPTY,           EMPTY,           EMPTY,          EMPTY,         EMPTY,            EMPTY, 	      EMPTY,	

		    EMPTY,         EMPTY,           EMPTY,           EMPTY,          EMPTY,         EMPTY,            EMPTY, 	      EMPTY,	

		WHITE | PAWN,  WHITE | PAWN,    WHITE | PAWN,    WHITE | PAWN,   WHITE | PAWN,  WHITE | PAWN,     WHITE | PAWN,    WHITE | PAWN,

		WHITE | ROOK,  WHITE | KNIGHT,  WHITE | BISHOP,  WHITE | QUEEN,  WHITE | KING,  WHITE | BISHOP,   WHITE | KNIGHT,  WHITE | ROOK,

		};

		memcpy(state->board, start_pos, sizeof(Piece) * 64);

	} else {

		memcpy(state->board, board, sizeof(Piece) * 64);
	}


	// Turn 0 is the first turn
	state->turn_count = 0;

	// White moves first
	state->next_turn = WHITE;

	return state;
}

void rm_game_state(Game_State* state) {
	mem_free(state);
}

Piece get_piece(Game_State* state, u x, u y) {
	return state->board[coortoidx(x, y)];
}

Move_Error free_move(Game_State* state, u x1, u y1, u x2, u y2) {
	if (state->board[coortoidx(x1, y1)] != EMPTY) {
		state->board[coortoidx(x2, y2)] = state->board[coortoidx(x1, y1)];
		state->board[coortoidx(x1, y1)] = EMPTY; 
	} else {	
		return ERROR_PIECE_NOT_FOUND;
	}
	return SUCCESS;
}
