CFLAGS= -Wall -Wextra

chess: main.c board.c board.h
	$(CC) $(CFLAGS) main.c board.c -o chess
