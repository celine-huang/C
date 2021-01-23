#include <stdio.h>

int main(void){
    int n;
    while(scanf("%d", &n) != EOF){
        int bit = 0, cons = 0;
        while(n > 0){
            if((n & 1) != 0)
                bit++;
            else
                bit = 0;
            if(bit > cons)
                cons = bit;
            n >>= 1;
        }
        printf("%d\n", cons);
    }
    return 0;
}
