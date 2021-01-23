#include <stdio.h>
#include "set.h"

void init(Set *set) {
    *set = 0;
}

void add(Set *set, int i) {
    int bit = 1;
    for(int j = 0; j < i; j++)
        bit *= 2;
    *set |= bit;
}

void has(Set set, int i) {
    int bit = 1;
    for(int j = 0; j < i; j++)
        bit *= 2;
    if((set & bit) != 0)
        printf("set has %d\n", i);
    else
        printf("set does not have %d\n", i);
}

Set setUnion(Set a, Set b) {
    return (a | b);
}

Set setIntersect(Set a, Set b) {
    return (a & b);
}

Set setDifference(Set a, Set b) {
    return (a ^ b);
}
