#include <stdio.h>

int main(void){
    long long int n;
    while(scanf("%lld", &n) != EOF){
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
