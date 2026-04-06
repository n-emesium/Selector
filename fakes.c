#include "fakes.h"
#include "randomizer.h"
#include <stdio.h>
#include <stdlib.h>
char cset[] = "abcdefghijklmnopqrstuvwxyz";
char scale = 'A' - 'a';
#define SCALE scale
void print_name(int x) {
    for (int i = 0; i < x; i++) {
        char t = get(INDLIMIT);
        putchar(cset[get(LALPH)] + SCALE);
        for (char j = 1; j < t; j++) putchar(cset[get(LALPH)]);
        space();
    }
}

char *create_name(int x) {
    int s = (x - 1 > 0 ? x - 1 : 0);
    char arr[x];
    int sz = 0;
    for (int i = 0; i < x; i++) arr[i] = get(INDLIMIT), sz += arr[i];
    char *name = (char *)malloc(sizeof(char) * (s + 1 + sz));
    int dx = 0;
    for (int i = 0; i < x; i++) {
        int xt = arr[i];
        int xd = dx;
        // putchar(cset[get(LALPH)] + SCALE);
        name[dx++] = cset[get(LALPH)] + SCALE;
        for (int j = xd + 1; j < xd + xt; j++) name[dx++] = cset[get(LALPH)];
        name[dx++] = ' ';
    }
    name[dx - 1] = '\0';
    return name;
}

int mlen(char * __restrict s) {
    char * __restrict p = s; 
    while (*s++);
    return p - s - 1;
}
