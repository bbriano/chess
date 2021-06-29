CFLAGS = -std=c99 -Wall -Wextra
EXECUTABLE = chess
OBJECTS = main.o board.o pgn.o


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) main.o board.o pgn.o -o $(EXECUTABLE)

.o:
	$(CC) $(CFLAGS) -c $<


.PHONY: clean

clean:
	$(RM) *.o $(EXECUTABLE)
