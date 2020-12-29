/*
 * Sage Farrenholz (C) 2020
 */

#ifndef GAME_HISTORY_H
#define GAME_HISTORY_H

#define STACK_START_SIZE 300

typedef struct Game_History {
	Command* command_stack;	
	int stack_size;
} Game_History;

// Intialize a new game_history object
Game_History* game_history_init(void);

// Push command into history
void game_history_push(Command*);

// Pop command from history
Command* game_history_pop(void);

// Destroys a game history object and its associated resources.
void game_history_destroy(Game_History*);

#endif 
