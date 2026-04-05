#ifndef __INIT__H__
#define __INIT__H__
#include <string>
#include <vector>
#define uint unsigned int
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
vector<string> init(int, char**);
vector<string> init(int, char **, int *, int *);
uint matoi(char *);

#endif
