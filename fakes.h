#ifndef __FAKES__
#define __FAKES__
#define INDLIMIT 10
#define LALPH 26
#include <stdio.h>
#define space() (putchar(' '))
#define endl() (putchar('\n'))
extern char scale;
extern char cset[];
void print_name(int);
char *create_name(int);
int mlen(char * restrict);
#endif
