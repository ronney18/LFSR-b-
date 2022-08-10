CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic
OBJ = LFSR.o PhotoMagic.o
DEPS = 
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = PhotoMagic

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(EXE)
