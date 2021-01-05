/* Sage Farrenholz © 2020 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <stdbool.h>

#include "chess.h"
#include "chess_player.h"
#include "chess_piece.h"

#ifndef POSITION_INDEX
#define POSITION_INDEX 1
#endif

//typedef Chess_Piece Chess_Board[64];

typedef struct Chess_State {
	Chess_Piece* board[64];
	Chess_Player* players[2];	
	int turn_count;	
	Color next_turn;
	bool black_is_check, white_is_check;	     
	
	// TODO add game history to rewind game
} Chess_State;

// Intialize a chess state, board may be null
Chess_State* chess_state_init(Chess_Piece* board[64]);

// Deletes a chess state
void chess_state_destroy(Chess_State* state);

// Returns the piece at a given location
Chess_Piece* chess_state_get_piece(Chess_State* state, unsigned x, unsigned y);

// Move a piece from source position to destination position, returns Move Error 
Chess_Error chess_state_move_piece(Chess_State* state, unsigned source_x, unsigned source_y, unsigned dest_x, unsigned dest_y); 

// Get the player whose turn it is
Chess_Player* chess_state_get_next_player(Chess_State* state);

// Retrieve a player by color
Chess_Player* chess_state_get_player_by_color(Chess_State* state, Color player_color);

// Unequivocally sets a piece (without error), use empty for setting empty space
void chess_state_set_piece(Chess_State* state, unsigned x, unsigned y, Chess_Piece);

void chess_state_print_status();

#endif
