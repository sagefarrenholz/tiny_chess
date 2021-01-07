/* Copyright (c) 2021, Sage Farrenholz*/

#include "chess_constructs.h"
#include <stdlib.h>

unsigned coortoidx(unsigned x, unsigned y) { return (x - POSITION_INDEX) + (y - POSITION_INDEX) * 8;}

unsigned* idxtocoor(unsigned idx) { 
	unsigned* x = (unsigned*) malloc(sizeof(unsigned) * 2);
	x[0] = idx % 8;
	x[1] = idx / 8;
	return x;
}

Piece_Type string_to_piece(char* type_string) {
	if (type_string == NULL) return -1;
	for (int i = 0; i < strlen(type_string); i++) {
		type_string[i] = tolower(type_string[i]);
	}
	switch(type_string[0]) {
		case 'p':
			return PAWN;
		case 'b':
			return BISHOP;
		case 'r':
			return ROOK;
		case 'q':
			return QUEEN;
		case 'k':
			if (type_string[1] == 'n') {
				return KNIGHT;	
			} else {
				return KING;
			}
	}
	return -1;
} 
