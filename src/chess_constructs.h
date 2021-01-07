/* Copyright (c) 2021, Sage Farrenholz*/

#ifndef CHESS_CONSTRUCTS_H
#define CHESS_CONSTRUCTS_H

#ifndef POSITION_INDEX
#define POSITION_INDEX 1
#endif

#include <ctype.h>
#include <string.h>

unsigned coortoidx(unsigned x, unsigned y);
unsigned* idxtocoor(unsigned idx);

typedef enum Color {
	BLACK = 0x00u	,
	WHITE = 0x80u	,
} Color;

typedef enum Piece_Type {
	PAWN = 0x00u	,
	ROOK = 0x01u	,
	KNIGHT = 0x02u	,
	BISHOP = 0x03u	,
	QUEEN = 0x04u	,
	KING = 0x05u	,
} Piece_Type;

Piece_Type string_to_piece(char* type_string); 

typedef enum Chess_Error {
//  General Errors
	SUCCESS			,	// Piece successfully moved
	G_ERROR_INVALID_PARAMETERS,	// Parameters given were invalid (e.g. out of bounds) 
//  Move Errors
	M_ERROR_UNABLE		,	// Outside of piece's moveset (eg. pawn moving to its right or left)
	M_ERROR_NOT_FOUND	,	// No piece found at the specified location
	M_ERROR_STUCK		,	// Piece cannot move
	M_ERROR_NOT_OWNED	,	// Attempting move piece of opposite color
	M_ERROR_COLLISION	,	// Destination location is already inhabited by one's own piece
	M_ERROR_IN_CHECK	,	// In check and this move will not prevent check 
} Chess_Error;

#endif
