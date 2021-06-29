#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: cdb file.pgn");
        return 1;
    }

    // Create and print board.
    board_t b;
    board_init(&b);
    board_print(&b);
}
