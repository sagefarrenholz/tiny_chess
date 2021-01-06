/* Copyright (c) 2021, Sage Farrenholz */

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "chess_constructs.h"

typedef struct Chess_Piece {
	Color color;
	Piece_Type type;
} Chess_Piece;	

Chess_Piece* chess_piece_init(Color, Piece_Type);

void chess_piece_destroy(Chess_Piece*);

#endif
