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

// Clears the terminal screen with "cls" on windows and "clear" on other systems.
void clear_screen();

// Put pieces in initial position.
void board_init(uint8_t board[64]);

// Display board to stdout.
void board_print(uint8_t board[64]);        // With file and rank label.
void board_print_nolabel(uint8_t board[64]);

// Converts algebraic notation to board index.
// Mapping (index:square): 0:a1 1:b1 .. 7:h1 8:a2 .. 63:h8.
// Return -1 on invalid input.
// file -- lowercase/uppercase letter between A and H.
// rank -- ascii representation or number between 1 and 8.
uint8_t algebraic_to_index(uint8_t file, uint8_t rank);

#endif      // CHESS_H
