#include <stdio.h>
#include <stdlib.h>

int main() {

	#pragma warning(disable:4996)
	FILE* titlescreen = fopen("../art/screen/title.txt", "r+b");
	char* inbuff = malloc(32);
	char* outbuff = malloc(SIZE_MAX);
	//printf("Welcome to \nEnter your name\n>");
	fread(outbuff, 1, 300, titlescreen);
	if ("%s", scanf(inbuff)) {
		printf("An error occured.");
	}



	return 0;
}