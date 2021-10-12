#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "../AoC_C_utils/src/file_util.h"
#include "../AoC_C_utils/src/vector.h"

void d1p1() {
    char *input = file_read_full("inputfiles/day1/input");

    int acc = 0;
    int prev = *input - '0';

    for (size_t i = 1; isdigit(input[i]); i++) {
        int n = input[i] - '0';

        if (n == prev) acc += n;

        prev = n;
    }

    if ((*input - '0') == prev) acc += prev;

    printf("Ans: %i\n", acc);

    free(input);
}

void d1p2() {
    char *input = file_read_full("inputfiles/day1/input");
    vec_t v = vec_create(sizeof(int));

    for (size_t i = 0; isdigit(input[i]); i++) {
        int n = input[i] - '0';

        vec_push(&v, &n);
    }

    int acc = 0;

    for (size_t i = 0; i < v.len; i++) {
        int *a = vec_get(&v, i), *b = vec_get(&v, (i + v.len / 2) % v.len);
        if (*a == *b) {
            acc += *a;
        }
    }

    printf("Ans: %i\n", acc);

    vec_free(&v);
    free(input);
}