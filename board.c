#include <stdio.h>
#include <stdlib.h>
#include "board.h"

board_t *board_new()
{
    board_t *b = malloc(sizeof(board_t));

    for (int rank=3; rank<=6; rank++) {
        for (int col=1; col<=8; col++) {
            b->cell[board_coordinate_to_index(rank, col)] = ' ';
        }
    }

    b->cell[board_coordinate_to_index(1, 5)] = PIECE_WHITE_KING;
    b->cell[board_coordinate_to_index(1, 4)] = PIECE_WHITE_QUEEN;
    b->cell[board_coordinate_to_index(1, 3)] = PIECE_WHITE_BISHOP;
    b->cell[board_coordinate_to_index(1, 6)] = PIECE_WHITE_BISHOP;
    b->cell[board_coordinate_to_index(1, 2)] = PIECE_WHITE_KNIGHT;
    b->cell[board_coordinate_to_index(1, 7)] = PIECE_WHITE_KNIGHT;
    b->cell[board_coordinate_to_index(1, 1)] = PIECE_WHITE_ROOK;
    b->cell[board_coordinate_to_index(1, 8)] = PIECE_WHITE_ROOK;
    for (int file=1; file<=8; file++) {
        b->cell[board_coordinate_to_index(2, file)] = PIECE_WHITE_PAWN;
    }

    b->cell[board_coordinate_to_index(8, 5)] = PIECE_BLACK_KING;
    b->cell[board_coordinate_to_index(8, 4)] = PIECE_BLACK_QUEEN;
    b->cell[board_coordinate_to_index(8, 3)] = PIECE_BLACK_BISHOP;
    b->cell[board_coordinate_to_index(8, 6)] = PIECE_BLACK_BISHOP;
    b->cell[board_coordinate_to_index(8, 2)] = PIECE_BLACK_KNIGHT;
    b->cell[board_coordinate_to_index(8, 7)] = PIECE_BLACK_KNIGHT;
    b->cell[board_coordinate_to_index(8, 1)] = PIECE_BLACK_ROOK;
    b->cell[board_coordinate_to_index(8, 8)] = PIECE_BLACK_ROOK;
    for (int file=1; file<=8; file++) {
        b->cell[board_coordinate_to_index(7, file)] = PIECE_BLACK_PAWN;
    }

    return b;
}

void board_print(board_t *b)
{
    printf("+---+---+---+---+---+---+---+---+\n");
    for (int rank=8; rank>=1; rank--) {
        printf("|");
        for (int file=1; file<=8; file++) {
            printf(" %c |", b->cell[board_coordinate_to_index(rank, file)]);
        }
        printf("\n+---+---+---+---+---+---+---+---+\n");
    }
}

int board_coordinate_to_index(int rank, int file)
{
    return 8*(8-rank) + (file-1);
}
