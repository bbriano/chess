#ifndef BOARD_H
#define BOARD_H

#define PIECE_WHITE_KING 'K'
#define PIECE_WHITE_QUEEN 'Q'
#define PIECE_WHITE_BISHOP 'B'
#define PIECE_WHITE_KNIGHT 'N'
#define PIECE_WHITE_ROOK 'R'
#define PIECE_WHITE_PAWN 'P'
#define PIECE_BLACK_KING 'k'
#define PIECE_BLACK_QUEEN 'q'
#define PIECE_BLACK_BISHOP 'b'
#define PIECE_BLACK_KNIGHT 'n'
#define PIECE_BLACK_ROOK 'r'
#define PIECE_BLACK_PAWN 'p'

typedef struct {
    char cell[64];       // rank r, file f -> cell[8*(8-r) + (f-1)]
    int whites_turn;
} board_t;

// Allocate new board; put pieces in initial position.
// Call free(board) after use.
board_t *board_new();

// Display board as ascii grid.
void board_print(board_t *b);

// Convert from chess coordinate to array index for board_t.cell.
int board_coordinate_to_index(int rank, int file);

#endif
