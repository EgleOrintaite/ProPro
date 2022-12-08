CC=gcc
CFLAGS=-I.
DEPS = library.h
OBJ = Uzduotis3.o Uzduotis3func.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Uzduotis3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
