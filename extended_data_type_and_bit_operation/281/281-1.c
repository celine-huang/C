#include <stdio.h>

int main(void){
    int n;
    while(scanf("%d", &n) != EOF){
        int bit = 0;
        while(n > 0){
            if((n & 1) != 0)
                bit++;
            n >>= 1;
        }
        printf("%d\n", bit);
    }
    return 0;
}
