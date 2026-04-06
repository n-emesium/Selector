#ifndef __INIT__H__
#define __INIT__H__
#include <string>
#include <vector>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using std::vector;
using std::string;
vector<string> init(int, char**);
vector<string> init(int, char **, int *);
uint matoi(char *);

#endif
