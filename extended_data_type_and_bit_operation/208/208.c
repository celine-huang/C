#include <stdio.h>
#include <ctype.h>

int main(void){
    int width, depth;
    scanf("%d%d", &width, &depth);
    char bitmap[depth][width];
    char one, zero;
    char c;
    int i = 0;
    while(i < 2){
        scanf("%c", &c);
        if(isgraph(c) && i == 1){
            zero = c;
            i++;
        }
        if(isgraph(c) && i == 0){
            one = c;
            i++;
        }
    }
    int n = width * depth / 32, left = width * depth % 32;
    unsigned int num[n+1];
    for(i = 0; i < n; i++){
        scanf("%u", &num[i]);
        for(int j = 31; j >= 0; j--){
            if((num[i] & 1) != 0)
                bitmap[(i*32+j)/width][(i*32+j)%width] = one;
            else
                bitmap[(i*32+j)/width][(i*32+j)%width] = zero;
            num[i] >>= 1;
        }
    }
    if(left != 0){
        unsigned int last;
        scanf("%u", &last);
        last >>= 32 - left;
        for(int i = 1; i <= left; i++){
            if((last & 1) != 0)
                bitmap[(depth*width-i)/width][(depth*width-i)%width] = one;
            else
                bitmap[(depth*width-i)/width][(depth*width-i)%width] = zero;
            last >>= 1;
        }
    }
    for(int i = 0; i < depth; i++){
        for(int j = 0; j < width; j++)
            printf("%c", bitmap[i][j]);
        printf("\n");
    }
    return 0;
}
