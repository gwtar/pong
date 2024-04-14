CC := gcc
CFLAGS := -Wall -Wextra -Wconversion -O2 -lraylib
SRC := main.c init.c logic.c draw.c
OBJ := main.o init.o logic.o draw.o

output: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o output

$(OBJ): $(SRC)
	$(CC) $(SRC) -c

clean:
	rm $(OBJ)

uninstall:
	rm output
