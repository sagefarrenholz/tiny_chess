/* Sage Farrenholz © 2020 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "../chess.h"

typedef Piece Chess_Board[64];

typedef struct Chess_State {
	Chess_Board board;
	int turn_count;	
	Color next_turn;
	bool black_is_check, white_is_check;	     
	// TODO add game history to rewind game
} Chess_State;

// Intialize a chess state, board may be null
Chess_State* chess_state_init(Chess_Board board);

// Deletes a chess state
void chess_state_destroy(Chess_State* state);

// Returns the piece at a given location
Piece chess_state_get_piece(Chess_State* state, unsigned x, unsigned y);

// Move a piece from source position to destination position, returns Move Error 
Move_Error chess_state_move_piece(Chess_State* state, unsigned source_x, unsigned source_y, unsigned dest_x, unsigned dest_y); 

// Unequivocally sets a piece (without error), use empty for setting empty space
void chess_state_set_piece(Chess_State* state, unsigned x, unsigned y, Piece);


#endif
