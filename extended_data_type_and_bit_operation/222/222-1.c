#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(void){
    uint8_t book;
    unsigned long long int bookshelf = 0;
    while(scanf("%hhu", &book) != EOF){
        unsigned long long int test = bookshelf;
        for(int i = 7; i >= 0; i--){
            unsigned long long int check = 255;
            if(test >> 8 * i == book){
                unsigned long long int move = (bookshelf & ((unsigned long long int)pow(256,i)-1));
                bookshelf &= ~((unsigned long long int)pow(256,(i+1))-1);
                bookshelf += move * 256;
            }
            check <<= 8 * i;
            test &= ~check;
        }
        test = 255;
        if((bookshelf & test) != 0)
            bookshelf <<= 8;
        bookshelf += book;
    }
    for(int i = 7; i >= 0; i--){
        unsigned long long int test = 255;
        test <<= 8 * i;
        if((bookshelf & test) != 0){
            int takeout = bookshelf >> 8 * i;
            printf("%d ", takeout);
            bookshelf &= ~test;
        }
        else
            printf("0 ");
    }
    printf("\n");
    return 0;
}
