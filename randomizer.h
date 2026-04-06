#ifndef __RANDOMIZER__H__
#define __RANDOMIZER__H__
#include <stdlib.h>
typedef unsigned int uint;
#define get(lim) (rand() % (lim))
uint xor_seed();
#endif
