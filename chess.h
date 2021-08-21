#ifndef CHESS_H
#define CHESS_H

#include <stdint.h>

#define WHITE_KING 'K'
#define WHITE_QUEEN 'Q'
#define WHITE_BISHOP 'B'
#define WHITE_KNIGHT 'N'
#define WHITE_ROOK 'R'
#define WHITE_PAWN 'P'
#define BLACK_KING 'k'
#define BLACK_QUEEN 'q'
#define BLACK_BISHOP 'b'
#define BLACK_KNIGHT 'n'
#define BLACK_ROOK 'r'
#define BLACK_PAWN 'p'
#define NO_PIECE ' '

// Represents a chess board with 64 squares.
//	index	square
//	0	a1
//	1	b1
//	..	..
//	7	h1
//	8	a2
//	..	..
//	63	h8
typedef char board_t[64];

// Clears the terminal screen with "cls" on windows and "clear" on other systems.
void clear_screen();

// Put pieces in initial position.
void board_init(board_t);

// Display board to stdout.
void board_print(board_t);
void board_print_label(board_t);	// With file and rank label.

// Converts algebraic notation to board index [0..63].
// Returns board index or -1 on invalid input.
// file -- lowercase/uppercase letter between A and H.
// rank -- ascii representation or number between 1 and 8.
int8_t algebraic_to_index(char file, char rank);

#endif		// CHESS_H
