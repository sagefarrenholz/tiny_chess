/* Copyright (c) 2021, Sage Farrenholz */

#ifndef CHESS_VIEW_H
#define CHESS_VIEW_H

#include "chess_piece.h"
#include "chess_graphic.h"

#define NUM_PIECE_GRAPHICS 6

typedef struct Chess_View {
	Chess_Graphic* piece_graphics[NUM_PIECE_GRAPHICS];
	
} Chess_View;

Chess_View* chess_view_init();

void chess_view_print_piece_idx(Chess_View* view, Chess_Piece* piece, int index);
void chess_view_print_piece(Chess_View* view, Chess_Piece* piece, int x, int y);

void chess_view_destroy(Chess_View* view);

#endif
