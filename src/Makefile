SRC=$(wildcard *.c)
LIBS="ncurses"

release: $(SRC)
	gcc -o chess $(SRC) -l$(LIBS)

debug: $(SRC)
	gcc -g -o chess $(SRC) -l$(LIBS)
