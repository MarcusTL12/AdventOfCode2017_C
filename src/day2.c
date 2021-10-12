#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../AoC_C_utils/src/file_util.h"

void d2p1() {
    char *input = file_read_full("inputfiles/day2/ex1");

    int acc = 0;

    bool done = false;

    char *p = input;

    while (!done) {
        int min = atoi(p), max = min;
        bool line_done = false;
        while (isdigit(*p)) p++;
        while (!isdigit(*p)) p++;
        while (!line_done) {
            while (isdigit(*p)) p++;
            while (!isdigit(*p)) {
                if (*p == '\n') line_done = true;
                p++;
            }
        }
    }

    free(input);
}

void d2p2() {}
