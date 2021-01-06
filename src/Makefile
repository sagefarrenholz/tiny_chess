SRC=$(wildcard *.c)
LIBS="ncurses"

release: $(SRC)
	gcc -o chess $(SRC) -l$(LIBS)

reference:
	gcc -o chess main.c chess_state.c memory.c
debug:
	gcc -m32 -Os -s -o chess main.c chess_state.c memory.c
