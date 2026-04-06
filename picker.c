#include "set.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "randomizer.h"
#define max(a, b) ((a) > (b) ? (a) : (b))
#define uint unsigned int
static inline uint matoi(char *s) {
    uint c = 0;
    while (*s && (c = 10 * c + (*s++ - '0')));
    return c;
}
int main(int argc, char *argv[]) {
    if (argc < 3) {printf("You gave %d many args, 3 are needed.\n", argc - 1); return 1;}
    xor_seed();
    int sz = matoi(argv[1]), k = matoi(argv[2]);
    int l = max(sz, k), s = sz + k - l;
    pick(l, s);
    putchar('\n');
    set *a = store_pick(l, s);
    print_set(a);
    free_set(a);
    return 0;
}
