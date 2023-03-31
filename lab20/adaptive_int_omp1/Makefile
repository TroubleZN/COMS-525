CC = gcc
FFLAGS = -Wall -std=c99 -fopenmp
LFLAGS = -lgomp -lm


OBJECTS = main.o

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean :
	rm -f $(OBJECTS) *.exe *.data

