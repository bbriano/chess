#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main()
{
    board_t *b = board_new();
    board_print(b);
    free(b);
}
