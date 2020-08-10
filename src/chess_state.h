/*
 * Sage Farrenholz (C) 2020
 */

#ifndef CHESS_STATE_H
#define CHESS_STATE_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "chess.h"
#include "memory.h"

typedef struct Chess_State {
	Piece board[64]; 
	int turn_count;	
	Color next_turn;
	bool black_is_check, white_is_check;	     
} Chess_State;

/*
 * init_state
 * 
 * Summary:
 * Allocates memory for board, pieces, move stack, etc. 
 * Organizes pieces to standard starting positions.
 */
Chess_State* init_chess_state();

// Deletes a chess state
void rm_chess_state(Chess_State* state);

// Returns the piece at a given location
Piece get_piece(Chess_State* state, unsigned x, unsigned y);

// Move a piece WITHOUT a validity check, returns a Move_Error (view Move_Error in chess.h), 0 = success
Move_Error free_move(Chess_State* state, unsigned source_x, unsigned source_y, unsigned dest_x, unsigned dest_y);

// Move a piece WITH a validity check, returns a Move_Error (view Move_Error in chess.h), 0 = success
Move_Error move(Chess_State* state, unsigned source_x, unsigned source_y, unsigned dest_x, unsigned dest_y);

// Add a piece into the game, used for promotions
void add_piece();

#endif
