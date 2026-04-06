#include <stdio.h>
#include <stdlib.h>
#include "fakes.h"
#include "randomizer.h"

int main() {
    xor_seed();
    print_name(2);
    endl();
    print_name(3);
    endl();
    char *n1 = create_name(2);
    char *n2 = create_name(3);
    printf("%s\n\n", n1);
    printf("%s\n\n", n2);
    free(n1);
    free(n2);
    return 0;
}
