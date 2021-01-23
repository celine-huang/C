#include <stdio.h>

int main(void){
    int dec;
    while(scanf("%d", &dec) != EOF){
        int bin[35], i = 0;
        while(dec >= 2){
            bin[i] = dec % 2;
            dec /= 2;
            i++;
        }
        bin[i] = dec;
        int num = 0;
        for(int j = i; j >= 0; j--)
            if(bin[j] & 1 != 0)
                num++;
        printf("%d\n", num);
    }
    return 0;
}
