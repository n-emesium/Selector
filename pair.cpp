#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "randomizer.h"
#include "init.h"
using namespace std;
ostream& operator<<(ostream& os, vector<pair<string, string>> vec) {
    int sz = vec.size()- 1;
    if (sz == -1) {os << "{}"; return os;}
    os << "{";
    for (int i = 0; i < sz; i++) {
        auto cur = vec[i];
        os << "{" << cur.first << ", " << cur.second << "} , ";
    }
    auto end = vec[sz];
    os << "{" << end.first;
    string x = end.second;
    if (x.size()) os << ", " << x;
    os << "}}";
    return os;
}
vector<pair<string, string>> paired(vector<string> v) {
    vector<pair<string,string>> ans; 
    int sz = v.size();
    while (sz) {
        // int a = rand() % sz--;
        int a = get(sz--);
        string x = v[a];
        swap(v[a], v.back());
        v.pop_back();
        // v.erase(v.begin() + a);
        int b = (sz ? get(sz--) : -1);
        char check = 1;
        ans.push_back(pair<string, string>{x, (b != -1 ?  v[b] : (check = 0, ""))});
        if (check) v.erase(v.begin() + b);
    }
    return ans;
}
int main(int argc, char **argv) {
    seed();
    vector<string> names = init(argc, argv);
    cout << paired(names) << "\n";
}
