/* Copyright (c) 2021, Sage Farrenholz */

#include "chess_view.h"
#include "chess_constructs.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#define WPLAYER_ON_WSQUARE 0
#define WPLAYER_ON_BSQUARE 1
#define BPLAYER_ON_WSQUARE 2
#define BPLAYER_ON_BSQUARE 3

#define TILE_WIDTH 18
#define TILE_HEIGHT 8

static void _chess_view_print_board(Chess_View*);

Chess_View* chess_view_init() {

	Chess_View* view = NULL;
	
	// ncurses setup
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	if (!has_colors()) { fprintf(stderr, "Chess_Error: terminal does not support color, exiting."); exit(-1); }
	start_color();

	// color pairs
	init_pair(WPLAYER_ON_WSQUARE, COLOR_YELLOW, COLOR_WHITE);
	init_pair(WPLAYER_ON_BSQUARE, COLOR_YELLOW, COLOR_BLACK);
	init_pair(BPLAYER_ON_WSQUARE, COLOR_RED, COLOR_WHITE);
	init_pair(BPLAYER_ON_BSQUARE, COLOR_RED, COLOR_BLACK);
	
	// draw board
	_chess_view_print_board(view);
	refresh();
	getch();

	return view;
}

void chess_view_destroy(Chess_View* state) {
	endwin();
}

static void _chess_view_print_tile(short color_pair_number, int x_offset, int y_offset) {
	for (int row = 0; row < TILE_HEIGHT; row++) {
		for (int col = 0; col < TILE_WIDTH; col++){
			attron(COLOR_PAIR(color_pair_number));
			mvaddch(row + y_offset, col + x_offset, ' ');
			attroff(COLOR_PAIR(color_pair_number));
		}
	}
}

static void _chess_view_print_board(Chess_View* state) {
	Color tile_color = WHITE;
	for (int tile_row = 0; tile_row < 8; tile_row++) {
		for (int tile_col = 0; tile_col < 8; tile_col++) {
			if (tile_color == WHITE) {
				_chess_view_print_tile(BPLAYER_ON_WSQUARE, tile_col * TILE_WIDTH, tile_row * TILE_HEIGHT);
			       	if (tile_col < 7) tile_color = BLACK;
			} else {
				_chess_view_print_tile(BPLAYER_ON_BSQUARE, tile_col * TILE_WIDTH, tile_row * TILE_HEIGHT);
			       	if (tile_col < 7) tile_color = WHITE;
			}
		} 	
		
	}
}

