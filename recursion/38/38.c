#include <stdio.h>

void makeLotion (int n) {
    if(n == 0)
        return;
    else{
        int D, a, b, c, A, B, C;
        scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
        if(a * A + b * B + c * C == D)
            printf("yes\n");
        else
            printf("no\n");
        makeLotion(n - 1);
    }
}

int main (void) {
    int n;
    scanf("%d", &n);
    makeLotion(n);    
    return 0;
}
