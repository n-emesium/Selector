#include "set.h"
#include <stdlib.h>
#include <stdio.h>
#include "randomizer.h"
void print_set(set *s) {
    int k = s->k, ll = s->ll, g = s->g;
    int **arr = s->arr;
    int upto = g - 1;
    for (int i = 0; i < upto; i++) {
        for (int j = 0; j < k; j++) printf("%4d ", arr[i][j]);
        printf("--> Group %d\n\n", i + 1);
    }
    int *last = arr[upto];
    for (int i = 0; i < ll; i++) printf("%4d ", last[i]);
    printf("--> Group %d\n", g);
}

void free_set(set *s) {
    int t = s->g; 
    for (int i = 0; i < t; i++) free(s->arr[i]);
    free(s->arr);
    free(s);
}

set *store_pick(int sz, int k) {
    if (!(sz && k)) return NULL;
    set *s = (set *)malloc(sizeof(set));
    s->k = k;
    s->sz = sz;
    int from[sz];
    for (int i = 0; i < sz; i++) from[i] = i/*get(UPPER)*/;
    int d = sz / k;
    int m = sz - d * k;
    int total = d + !!m - 1;
    int **ret = (int **)malloc(sizeof(int *) * (total + 1));
    for (int i = 0; i < total; i++) {
        int *put = (int *)malloc(sizeof(int) * k);
        for (int j = 0; j < k; j++) {
            int x = get(sz);
            put[j] = from[x];
            from[x] = from[sz-- -1];
        }
        ret[i] = put;
    }
    int *last = (int *)malloc(sizeof(int) * sz);
    d = 0;
    m = sz;
    while (sz) {
        int x = get(sz);
        last[d++] = from[x];
        from[x] = from[sz-- - 1];
    }
    ret[total] = last;
    s->ll = m;
    s->arr = ret;
    s->g = total + 1;
    return s;
}

void pick(int sz, int k) {
    if (!(sz && k)) return;
    int from[sz];
    for (int i = 0; i < sz; i++) from[i] = get(UPPER);
    int l = sz / k;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < k; j++) {
            int x = get(sz);
            printf("%4d ", from[x]);
            from[x] = from[sz-- - 1];
        }
        printf("--> Group %d\n\n", i + 1);
    }
    char c = sz;
    while (sz) {
        int x = get(sz);
        printf("%4d ", from[x]);
        from[x] = from[sz-- - 1];
    }
    if (!c) return;
    printf("--> Group %d\n", l + 1);
}
