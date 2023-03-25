CC = gcc
FFLAGS = -Wall -std=c99 -Xpreprocessor -fopenmp
LFLAGS = -lgomp -lm


OBJECTS = forloop.o \
	  matrix.o

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean :
	rm -f $(OBJECTS) *.exe *.txt *.out

