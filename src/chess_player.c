/* Copyright (C) 2021, Sage Farrenholz */

#include <stdio.h>
#include <stdlib.h>

#include "chess_player.h"

Chess_Player* chess_player_init(Color _color){
	Chess_Player* player = (Chess_Player*) malloc(sizeof(Chess_Player));	
	player->num_pieces = 0;
	player->color = _color;
	return player;
}

Chess_Piece* chess_player_add_piece(Chess_Player* player, Chess_Piece* piece) {
	if (player->num_pieces <= PIECE_LIMIT) {
		return	player->owned_pieces[player->num_pieces++] = piece;
	}
	return NULL;
}

void chess_player_destroy(Chess_Player* player) {
	free((void*)player);
}
