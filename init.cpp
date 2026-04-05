#include <vector>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include "init.h"
using namespace std;
vector<string> init(int argc, char **argv) {
    string buffer;
    string read;
    ifstream fp;
    vector<string> names;
    if (argc == 1 && !isatty(0)) while (cin >> buffer) names.push_back(buffer);
    else if (argc == 2) read = argv[1];
    fp = ifstream(read);
    if (!fp) {for (int i = 1; i < argc; i++) names.push_back(argv[i]);}
    else while (fp >> buffer) names.push_back(buffer);
    return names;
}

uint matoi(char *s) {
    uint c = 0;
    while (*s && (c = 10 * c + (*s++ - '0')));
    return c;
}

vector<string> init(int argc, char **argv, int* sz, int* k) {
    if (argc < 3) exit(-1);
    int s1 = matoi(argv[1]), s2 = matoi(argv[2]);
    int l = max(s1, s2);
    *sz = l;
    vector<string> ans = init(argc - 2, argv + 2);
    *k = ans.size();
    return ans;
}
