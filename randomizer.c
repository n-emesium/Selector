#include <time.h>
#include <stdlib.h>
#include "randomizer.h"
uint seed() {
    struct timespec s;
    clock_gettime(CLOCK_REALTIME, &s);
    uint ss = (uint)s.tv_nsec ^ (uint)s.tv_sec;
    srand(ss);
    return ss;
}


