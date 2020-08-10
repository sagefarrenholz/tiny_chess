/*
 * Sage Farrenholz (C) 2020
 *
 * Summary:
 * Common enums, error codes, etc 
 */

#ifndef CHESS_H
#define CHESS_H

#include <stdint.h>

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

typedef uint8_t Piece;

Color get_piece_color(Piece piece); 

Piece_Type get_piece_type(Piece piece);

// Errors used for moving pieces 
typedef enum Move_Error {
	SUCCESS			,	// Piece successfully moved
	ERROR_PIECE_UNABLE	,	// Piece simply unable to make this movement (eg. pawn moving to its right or left)
	ERROR_PIECE_NOT_FOUND	,	// No piece found at the specified location
	ERROR_PIECE_STUCK	,	// Piece cannot move
	ERROR_PIECE_NOT_OWNED	,	// Attempting move piece of opposite color
	ERROR_PIECE_COLLISION	,	// Destination location is already inhabited by one's own piece
//	ERROR_IN_CHECK		,	// In check and this move will not prevent check 
} Move_Error;

#endif
