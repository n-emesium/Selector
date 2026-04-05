#include <unistd.h>
#include <iostream>
#include <vector>
#include "randomizer.h"
#include "set.h"
#include "init.h"
void assign_names(set *s, vector<string> names) {
    int gr = s->g - 1, k = s->k, ll = s->ll;
    int **arr = s->arr;
    for (int i = 0; i < gr; i++) {
        for (int j = 0; j < k; j++) cout << names[arr[i][j]] << " ";
        cout << "--> Group " << i + 1 << "\n\n";
    }
    int *v = arr[gr];
    for (int i = 0; i < ll; i++) cout << names[v[i]] << " "; cout << "--> Group " << gr + 1 << "\n";
}
using namespace std;
int main(int argc, char *argv[]) {
    seed();
    int k, sz;
    vector<string> names = init(argc, argv, &k, &sz);
    set *s = store_pick(sz, k);
    assign_names(s, names);
    free_set(s);
}
