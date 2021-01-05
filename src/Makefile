SRC=$(wildcard *.c)

release: $(SRC)
	gcc -o chess $(SRC) 

reference:
	gcc -o chess main.c chess_state.c memory.c
debug:
	gcc -m32 -Os -s -o chess main.c chess_state.c memory.c
