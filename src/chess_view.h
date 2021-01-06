/* Copyright (c) 2021, Sage Farrenholz */

#ifndef CHESS_VIEW_H
#define CHESS_VIEW_H

typedef struct Chess_View {
	
} Chess_View;

Chess_View* chess_view_init();

void chess_view_print_board(Chess_View*);

void chess_view_destroy(Chess_View*);

#endif
