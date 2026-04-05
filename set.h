#ifndef __SET__H__
#define __SET__H__
#define UPPER 100
typedef struct {
    int **arr;  
    int sz, k, ll, g;
} set;

void print_set(set *);
void free_set(set *);
set *store_pick(int, int);
void pick(int, int);
#endif
