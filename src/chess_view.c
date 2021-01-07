/* Copyright (c) 2021, Sage Farrenholz */

#include "chess_view.h"
#include "chess_constructs.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define WPLAYER_ON_WSQUARE 0
#define WPLAYER_ON_BSQUARE 1
#define BPLAYER_ON_WSQUARE 2
#define BPLAYER_ON_BSQUARE 3

#define TILE_WIDTH 19
#define TILE_HEIGHT 8

static void _chess_view_print_board(Chess_View*);

Chess_View* chess_view_init() {

	Chess_View* view = (Chess_View*) malloc(sizeof(Chess_View));
	
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
	
	{
		// load piece graphics 
		char piece_graphics_filename[64] = "../art/piece/pawn.txt";
		FILE* piece_graphics_file = fopen(piece_graphics_filename, "r");

		if (piece_graphics_file != NULL) {
			Chess_Graphic* tmp_graphic;

			// read in each piece graphic
			for (int i = 0; i < NUM_PIECE_GRAPHICS; i++) {
				tmp_graphic = chess_graphic_init(piece_graphics_file);
				if (string_to_piece(tmp_graphic->label) < 6) {
					view->piece_graphics[string_to_piece(tmp_graphic->label)] = tmp_graphic;		
				} else {
					chess_graphic_destroy(tmp_graphic);
				}
			}
			printf("First label: %s\n", view->piece_graphics[0]->label);

			// close piece graphics file
			fclose(piece_graphics_file);
		} else {
			fprintf(stderr, "Chess_Error: could not open file containing piece graphics at %s\n", piece_graphics_filename);
		}
	}

	// draw board
	_chess_view_print_board(view);
	refresh();
	endwin();	

	return view;
}

void chess_view_destroy(Chess_View* view) {
	for (int i = 0; i < NUM_PIECE_GRAPHICS; i++) {
		if (view->piece_graphics[i] != NULL) {
			chess_graphic_destroy(view->piece_graphics[i]);
		}
	}
	free(view);
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

static void _chess_view_print_board(Chess_View* view) {
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

void chess_view_print_piece_idx(Chess_View* view, Chess_Piece* piece, int idx) {
	unsigned* conv = idxtocoor(idx);
	Chess_Graphic* piece_graphic = view->piece_graphics[piece->type];	
	int x = conv[0] * TILE_WIDTH, y = conv[1] * TILE_HEIGHT;
	for (int i = 0; i < piece_graphic->num_characters; i++) {
		char tmp_char = piece_graphic->characters[i];
		attron(COLOR_PAIR(WPLAYER_ON_WSQUARE));
		if (tmp_char == '\n') {
			y++;
			x=conv[0] * TILE_WIDTH;
		} else {
			mvaddch(y, x, tmp_char);
			x++;
		}
		attroff(COLOR_PAIR(BPLAYER_ON_WSQUARE));
	}
	refresh();
	free(conv);
}
