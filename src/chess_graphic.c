/* Copyright (c) 2021, Sage Farrenholz */

#include "chess_graphic.h"

#include <stdlib.h>

Chess_Graphic* chess_graphic_init(FILE* graphic_file) {
	
	Chess_Graphic* graphic = (Chess_Graphic*) malloc(sizeof(Chess_Graphic));

	graphic->width = 0;
	graphic->height = 0;
	graphic->num_characters = 0;

	{
		char format[32];
		snprintf(format, sizeof(format), "%%*[^%c]%%%ds", ESCAPE_CHARACTER, MAX_LABEL_SIZE - 1);

		// read label
		if (fscanf(graphic_file, format, graphic->label) != 1) {
			fprintf(stderr, "Chess_Error: could not parse label, ensure the label is less 126 characters and starts with a \"!\"\n");
			goto get_me_out;
		}  
		if (feof(graphic_file)) goto get_me_out;
	}
	
	// read in graphic

	char tmp_char;
	int width_count = 0;

	while(!feof(graphic_file)) {
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

	get_me_out:
		return graphic;
}

void chess_graphic_destroy(Chess_Graphic* graphic) {
	free(graphic);
}
