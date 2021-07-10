CFLAGS = -std=c99 -Wall -Wextra -pedantic
EXECUTABLE = chess
OBJECTS = chess.o


$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS)

.o:
	$(CC) $(CFLAGS) -c $<


.PHONY: clean

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)
