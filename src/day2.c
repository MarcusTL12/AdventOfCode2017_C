#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../AoC_C_utils/src/file_util.h"
#include "../AoC_C_utils/src/iterator.h"
#include "../AoC_C_utils/src/string_util.h"

void d2p1() {
    char *input = file_read_full("inputfiles/day2/ex1");

    iterator line_it = str_split_iter(input, '\n', true, 0, true);
    str_t line;

    iterator num_it = str_split_iter(NULL, ' ', false, 0, true);

    while (iter_next(line_it, &line)) {
        printf("Line len: %zu; \"%.*s\"\n", line.len, (int)line.len,
               line.start);

        // char *num_str;
        str_t num_str;
        str_split_iter_refresh(num_it, line.start, line.len);

        while (iter_next(num_it, &num_str)) {
            int n = atoi(num_str.start);

            printf("num len: %zu; %i\n", num_str.len, n);
        }
    }

    free(input);
}

void d2p2() {}
