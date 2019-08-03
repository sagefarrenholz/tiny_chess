#include "chess.h" 

typedef struct Player {

	uint8_t* board;		//The board this player is playing on.
	uint8_t team;		//Player's color.
	


} Player;

int main() {

	/*
	In commandline chess a 64 byte array repesents all of the pieces
	on the board and also empty spaces.

	A NULL byte (0x00) is an empty space
	For a space with a piece, the type of piece is repesented by the last 3 bits:
	001 Pawn
	010 Rook
	011 Knight
	100 Bishop
	101 Queen
	110 King

	The color of the piece is repesented by the 4th bit from the right.
	0 Black
	1 White

	Examples
	0b00001011 White Knight
	0x05 Black Queen

	The board is indexed from left to right, bottom to top.
	A1 is represented by index 0.
	H1 is represented by index 7.
	H8 is represented by index 63.
	*/

		Player* player = (Player*) malloc(sizeof(Player));
		if (player) {
			//Intro sequence.
			//Print title screen here

			//Command / Game loop.
			
			while (1) {
				//Command buffer
				char* cmdbuff = (char*)calloc(256, sizeof(char));
				//time_t prevtime = time(NULL);	//Get current time.
				//time_t currtime;
				//If deltatime >= 1 sec redraw turn clock; 1hz.
				
				//Render here
				
				char* com = NULL; //Main command
				char** arg = NULL; //Command arguments.
				int argc = 0; //Argument amount;
				printf("Type \"help\" for a list of commands\n>");
				#pragma warning(disable:4996)
				fgets(cmdbuff, 256, stdin);
				while (strtok())
				for (size_t i = 0; i < strlen(cmdbuff); i++) {
					if (cmdbuff[i] == '\n') break;
					if (cmdbuff[i] == ' ') continue;
					if (!com) {
						printf("command %c", cmdbuff[i]);
					} else {
						printf("arguement %c", cmdbuff[i]);
					}
						
				}
				free(cmdbuff);
			}

			
			//End Sequence
		}
	free(player);
	return 0;
}

uint8_t coortoidx(char* coor) {
	uint8_t y = coor[1];
	uint8_t x = 0;
	switch (coor[0]) {
	case 'a':
		x = 1;
		break;
	case 'b':
		x = 2;
		break;
	case 'c':
		x = 3;
		break;
	case 'd':
		x = 4;
		break;
	case 'e':
		x = 5;
		break;
	case 'f':
		x = 6;
		break;
	case 'g':
		x = 7;
		break;
	case 'h':
		x = 8;
		break;
	}
	return x * y - 1;
}

/*
//White side.
player->board[0] = 0x0A;	//White Rook A1
player->board[1] = 0x0B;	//White Knight B1
player->board[2] = 0x0C;	//White Bishop C1
player->board[3] = 0x0D;	//White Queen D1
player->board[4] = 0x0E;	//White King E1
player->board[5] = 0x0C;	//White Bishop F1
player->board[6] = 0x0B;	//White Knight G1
player->board[7] = 0x0A;	//White Rook H1
player->board[8] = 0x09;	//White Pawn A2
player->board[9] = 0x09;	//White Pawn B2
player->board[10] = 0x09;	//White Pawn C2
player->board[11] = 0x09;	//White Pawn D2
player->board[12] = 0x09;	//White Pawn E2
player->board[13] = 0x09;	//White Pawn F2
player->board[14] = 0x09;	//White Pawn G2
player->board[15] = 0x09;	//White Pawn H2

//Black Side
player->board[48] = 0x01;	//Black Pawn A7
player->board[49] = 0x01;	//Black Pawn B7
player->board[50] = 0x01;	//Black Pawn C7
player->board[51] = 0x01;	//Black Pawn D7
player->board[52] = 0x01;	//Black Pawn E7
player->board[53] = 0x01;	//Black Pawn F7
player->board[54] = 0x01;	//Black Pawn G7
player->board[55] = 0x01;	//Black Pawn H7
player->board[56] = 0x02;	//Black Rook A8
player->board[57] = 0x03;	//Black Knight B8
player->board[58] = 0x04;	//Black Bishop C8
player->board[59] = 0x05;	//Black Queen D8
player->board[60] = 0x06;	//Black King E8
player->board[61] = 0x04;	//Black Bishop F8
player->board[62] = 0x03;	//Black Knight G8
player->board[63] = 0x02;	//Black Rook H8
*/