/* Copyright (c) 2021, Sage Farrenholz */ 

#include <stdlib.h>

#include "chess_piece.h"

Chess_Piece* chess_piece_init(Color _color, Piece_Type _type) {
	Chess_Piece* piece = (Chess_Piece*) malloc(sizeof(Chess_Piece));
	piece->color = _color;
	piece->type = _type;
	return piece;
}

void chess_piece_destroy(Chess_Piece* piece) {
	free(piece);
}
