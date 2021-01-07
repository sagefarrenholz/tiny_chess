SRC=$(wildcard *.c)
LIBS=ncurses

OUTPUT=pawn

release: $(SRC)
	gcc -O3 -o $(OUTPUT) $(SRC) -l$(LIBS)

debug: $(SRC)
	gcc -g -o $(OUTPUT) $(SRC) -l$(LIBS)

clean:
	rm $(OUTPUT)
