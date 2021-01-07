/* Copyright (c) 2021, Sage Farrenholz */

#ifndef CHESS_GRAPHIC_H
#define CHESS_GRAPHIC_H

#define MAX_SIZE_BYTES 1024
#define MAX_LABEL_SIZE 128
#define ESCAPE_CHARACTER '!'

#include <stdio.h>

typedef struct Chess_Graphic {
	char characters[MAX_SIZE_BYTES];
	char label[MAX_LABEL_SIZE];
	int num_characters;
	int width;
	int height;
} Chess_Graphic;

Chess_Graphic* chess_graphic_init(FILE* graphic_file);

// does not close the passed file
void chess_graphic_destroy(Chess_Graphic* graphic);

#endif
