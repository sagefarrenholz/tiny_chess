/*
 * Sage Farrenholz (C) 2020
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "chess_state.h"

#define p(c, t) chess_piece_init(c, t) 

typedef unsigned u;

Chess_State* chess_state_init(Chess_Piece* board[64]) {
	
	Chess_State* state = (Chess_State*) malloc(sizeof(Chess_State));
	
	if (state == NULL) {
		fprintf(stderr, "Error: could not malloc for chess_state.");
		exit(-1);
	}

	if (board == NULL) {
	
		// Set starting positions
		Chess_Piece* start_pos[64] = {

			p(BLACK, ROOK),  p(BLACK, KNIGHT),  p(BLACK, BISHOP), p(BLACK, QUEEN), p(BLACK, KING),  p(BLACK, BISHOP),  p(BLACK, KNIGHT),  p(BLACK, ROOK),

			p(BLACK, PAWN),  p(BLACK, PAWN),    p(BLACK, PAWN),   p(BLACK, PAWN),  p(BLACK, PAWN),  p(BLACK, PAWN),    p(BLACK, PAWN),    p(BLACK, PAWN),

			    NULL,         NULL,           NULL,           NULL,          NULL,         NULL, 	        NULL,         NULL,	

			    NULL,         NULL,           NULL,           NULL,          NULL,         NULL,     	NULL,         NULL,	

			    NULL,         NULL,           NULL,           NULL,          NULL,         NULL,            NULL, 	      NULL,	

			    NULL,         NULL,           NULL,           NULL,          NULL,         NULL,            NULL, 	      NULL,	

			p(WHITE, PAWN),  p(WHITE, PAWN),    p(WHITE, PAWN),    p(WHITE, PAWN),   p(WHITE, PAWN),  p(WHITE, PAWN),    p(WHITE, PAWN),   p(WHITE, PAWN),

			p(WHITE, ROOK),  p(WHITE, KNIGHT),  p(WHITE, BISHOP),  p(WHITE, QUEEN),  p(WHITE, KING),  p(WHITE, BISHOP),  p(WHITE, KNIGHT), p(WHITE, ROOK),

		};

		memcpy(state->board, start_pos, sizeof(Chess_Piece*) * 64);

	} else {

		memcpy(state->board, board, sizeof(Chess_Piece*) * 64);
	}


	// Init and attach players
	Chess_Player* white_player = chess_player_init(WHITE);
	Chess_Player* black_player = chess_player_init(BLACK);

	// Attach players to the chess state
	state->players[0] = white_player;
	state->players[1] = black_player;
	
	// Add pieces to players
	for (int i = 0; i < 64; i++) {
		Chess_Piece* tmp_piece = state->board[i];
		if (tmp_piece == NULL) continue;
		if (tmp_piece->color == WHITE) {
			chess_player_add_piece(white_player, tmp_piece);	
		} else {
			chess_player_add_piece(black_player, tmp_piece);	
		}
	}

	// Turn 0 is the first turn
	state->turn_count = 0;

	// White moves first
	state->next_turn = WHITE;

	return state;
}

inline static u coortoidx(u x, u y){ return (x - POSITION_INDEX) + (y - POSITION_INDEX) * 8; }

Chess_Piece* chess_state_get_piece(Chess_State* state, u x, u y) {
	return state->board[coortoidx(x, y)];
}

Chess_Player* chess_state_get_player_by_color(Chess_State* state, Color player_color) {
	if (state->players[0]->color == player_color) {
		return state->players[0];
	} else {
		return state->players[1];
	}
}

Chess_Player* chess_state_get_next_player(Chess_State* state) {
	if (state->next_turn == BLACK) {
		return chess_state_get_player_by_color(state, BLACK);
	} else {
		return chess_state_get_player_by_color(state, WHITE);
	}
}

Chess_Error chess_state_move_piece(Chess_State* state, u x1, u y1, u x2, u y2) {

	// Ensure valid positions
	if (x1 > 63 + POSITION_INDEX || x1 < POSITION_INDEX) return G_ERROR_INVALID_PARAMETERS; 
	if (y1 > 63 + POSITION_INDEX || y1 < POSITION_INDEX) return G_ERROR_INVALID_PARAMETERS;  
	if (x2 > 63 + POSITION_INDEX || x2 < POSITION_INDEX) return G_ERROR_INVALID_PARAMETERS; 
	if (y2 > 63 + POSITION_INDEX || y2 < POSITION_INDEX) return G_ERROR_INVALID_PARAMETERS; 
	
	Chess_Player* next_player = chess_state_get_next_player(state);
	
	// If player is in check this move must exit them from the check
	if (next_player->in_check) {
			
	} else {
		
	}

	return SUCCESS;
}


void chess_state_print_status(Chess_State* state) {
	printf("Chess State status --> %p\n", state);
	printf("black player --> %p\n", chess_state_get_player_by_color(state, BLACK));	
	printf("white player --> %p\n", chess_state_get_player_by_color(state, WHITE));	
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			Chess_Piece* tmp_piece = chess_state_get_piece(state, j, i);
			if (tmp_piece != NULL)
				printf("[Piece at x: %d y: %d is color %u and type %u]\t", j, i, tmp_piece->color, tmp_piece->type);
			else 
				printf("[x: %d y: %d is empty]\t", j, i);
		}
		printf("\n");
	}


}
