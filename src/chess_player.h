#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <stdbool.h>

#include "chess.h"
#include "chess_piece.h"

// Shouldn't be possible to acquire more than 30 pieces
#define PIECE_LIMIT 30

typedef struct Chess_Player {
	Chess_Piece* owned_pieces[PIECE_LIMIT];		
	int num_pieces;
	Color color;
	bool in_check;
} Chess_Player;

Chess_Player* chess_player_init(Color);

Chess_Piece* chess_player_add_piece(Chess_Player*, Chess_Piece*);

void chess_player_destroy(Chess_Player*);

#endif
