/* Copyright (c) 2021, Sage Farrenholz*/

#ifndef CHESS_CONSTRUCTS_H
#define CHESS_CONSTRUCTS_H

typedef enum Color {
	BLACK = 0x00u	,
	WHITE = 0x80u	,
} Color;

typedef enum Piece_Type {
	EMPTY = 0x00u	,
	PAWN = 0x01u	,
	ROOK = 0x02u	,
	KNIGHT = 0x03u	,
	BISHOP = 0x04u	,
	QUEEN = 0x05u	,
	KING = 0x06u	,
} Piece_Type;

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
