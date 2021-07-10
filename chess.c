#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "chess.h"

#define USAGE "Usage: chess [-c]\n"

int main(int argc, char **argv)
{
    (void) argc;        // Silence -Wunused-parameter

    // Set default options.
    bool opt_clear = false;     // -c to set true
    bool opt_label = true;      // -l to set false

    // Parse options.
    while (*++argv) {
        if (**argv != '-') {
            fprintf(stderr, USAGE);
            exit(1);
        }
        char *c = *argv;
        while (*++c) {
            switch (*c) {
                case 'c':
                    opt_clear = true;
                    break;
                case 'l':
                    opt_label = false;
                    break;
                default:
                    fprintf(stderr, USAGE);
                    exit(1);
            }
        }
    }

    board_t board;
    board_init(board);
    bool whites_turn = true;
    bool game_over = false;

    // Game loop.
    while (!game_over) {
        if (opt_clear) {
            clear_screen();
        }

        if (opt_label) {
            board_print(board);
        } else {
            board_print_nolabel(board);
        }

        while (true) {
            if (whites_turn) {
                printf("(white) ");
            } else {
                printf("(black) ");
            }

            // TODO: read move
            // TODO: validate move
            // TODO: move piece
            // TODO: check checkmate
            getchar();

            whites_turn = !whites_turn;
        }
    }
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void board_init(board_t board)
{
    // Set empty squares.
    for (int rank=3; rank<=6; rank++) {
        for (int file='A'; file<='H'; file++) {
            board[algebraic_to_index(file, rank)] = NO_PIECE;
        }
    }

    // Set white pieces.
    board[algebraic_to_index('A', 1)] = WHITE_ROOK;
    board[algebraic_to_index('B', 1)] = WHITE_KNIGHT;
    board[algebraic_to_index('C', 1)] = WHITE_BISHOP;
    board[algebraic_to_index('D', 1)] = WHITE_QUEEN;
    board[algebraic_to_index('E', 1)] = WHITE_KING;
    board[algebraic_to_index('F', 1)] = WHITE_BISHOP;
    board[algebraic_to_index('G', 1)] = WHITE_KNIGHT;
    board[algebraic_to_index('H', 1)] = WHITE_ROOK;
    for (char file='A'; file<='H'; file++) {
        board[algebraic_to_index(file, 2)] = WHITE_PAWN;
    }

    // Set black pieces.
    board[algebraic_to_index('A', 8)] = BLACK_ROOK;
    board[algebraic_to_index('B', 8)] = BLACK_KNIGHT;
    board[algebraic_to_index('C', 8)] = BLACK_BISHOP;
    board[algebraic_to_index('D', 8)] = BLACK_QUEEN;
    board[algebraic_to_index('E', 8)] = BLACK_KING;
    board[algebraic_to_index('F', 8)] = BLACK_BISHOP;
    board[algebraic_to_index('G', 8)] = BLACK_KNIGHT;
    board[algebraic_to_index('H', 8)] = BLACK_ROOK;
    for (char file='A'; file<='H'; file++) {
        board[algebraic_to_index(file, 7)] = BLACK_PAWN;
    }
}

void board_print(board_t board)
{
    printf("     A   B   C   D   E   F   G   H\n");
    printf("   +---+---+---+---+---+---+---+---+\n");

    for (int rank=8; rank>=1; rank--) {
        printf(" %d |", rank);      // Left rank column label.

        for (int file='A'; file<='H'; file++) {
            printf(" %c |", board[algebraic_to_index(file, rank)]);
        }

        printf(" %d\n", rank);      // Right rank column label.
        printf("   +---+---+---+---+---+---+---+---+\n");
    }

    printf("     A   B   C   D   E   F   G   H\n");
}

void board_print_nolabel(board_t board)
{
    printf("+---+---+---+---+---+---+---+---+\n");

    for (int rank=8; rank>=1; rank--) {
        printf("|");

        for (int file='A'; file<='H'; file++) {
            printf(" %c |", board[algebraic_to_index(file, rank)]);
        }

        printf("\n");
        printf("+---+---+---+---+---+---+---+---+\n");
    }
}

int8_t algebraic_to_index(char file, char rank)
{
    // Check within range.
    bool file_upper = 'A' <= file && file <= 'H';
    bool file_lower = 'a' <= file && file <= 'h';
    bool rank_numeric = 1 <= rank && rank <= 8;
    bool rank_numeric_ascii = '1' <= rank && rank <= '8';

    // Report if not within range.
    if (!(file_upper || file_lower)) {
        return -1;
    }
    if (!(rank_numeric || rank_numeric_ascii)) {
        return -1;
    }

    // Converge 2 cases to 1.
    if (file_lower) {
        file >>= 5;
    }
    if (rank_numeric_ascii) {
        rank -= '0';
    }

    // Make file and rank range over [0,8)
    file -= 'A';
    rank -= 1;
    assert(0 <= file && file < 8);
    assert(0 <= rank && rank < 8);

    // Return index.
    return 8*rank + file;
}
