/* Copyright (c) 2021, Sage Farrenholz */

#include "chess_graphic.h"

#include <stdlib.h>

Chess_Graphic* chess_graphic_init(FILE* graphic_file) {
	
	Chess_Graphic* graphic = (Chess_Graphic*) malloc(sizeof(Chess_Graphic));

	graphic->width = 0;
	graphic->height = 0;
	graphic->num_characters = 0;

	char tmp_char;
	{

		// FIXME this is an attrocity D:
		while (!feof(graphic_file)) {
			tmp_char = fgetc(graphic_file);
			if (tmp_char == ESCAPE_CHARACTER) {
				tmp_char = fgetc(graphic_file);
				int i = 0;
				for (; i < MAX_LABEL_SIZE - 1 && tmp_char != '\n'; i++) {
					graphic->label[i] = tmp_char;				
					tmp_char = fgetc(graphic_file);
				}
				graphic->label[i] = '\0';	
				break;
			}   
		}
		if (feof(graphic_file)) {
			fprintf(stderr, "Chess_Error: label parser hit EOF"); 
			goto get_me_out;
		}
	}
	
	// read in graphic

	int width_count = 0;

	// FIXME may need to insert newlines when we hit an escape or eof 
	while(!feof(graphic_file) && graphic->num_characters < MAX_SIZE_BYTES - 2) {
		tmp_char = fgetc(graphic_file);
		if (tmp_char == ESCAPE_CHARACTER) {
			fseek(graphic_file, ftell(graphic_file) - 1, SEEK_SET);
			break;
		} else if (tmp_char == '\n') {
			if (width_count > graphic->width) graphic->width = width_count;
			graphic->height++;
			width_count = 0;	
		} else {
			width_count++;	
		}
		graphic->characters[graphic->num_characters++] = tmp_char; 
	}
	graphic->characters[graphic->num_characters] = '\0'; 

	get_me_out:
		return graphic;
}

void chess_graphic_destroy(Chess_Graphic* graphic) {
	free(graphic);
}
