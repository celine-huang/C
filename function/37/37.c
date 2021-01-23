#include <stdio.h>

int value(int type, int width, int height, int length);

int main(){
    int type, width, height, length;
    scanf("%d%d%d%d", &type, &width, &height, &length);
    printf("%d\n", value(type, width, height, length));
    return 0;
}

int value(int type, int width, int height, int length){
    if(type != 79 && type != 47 && type != 29 && type != 82 && type != 26 && type != 22)
        return -1;
    else if(width <= 0 || height <= 0 || length <= 0)
        return -2;
    else{
        int price;
        switch(type){
            case 79: //gold
                price = 30;
                break;
            case 47: //silver
                price = 10;
                break;
            case 29: //copper
                price = 4;
                break;
            case 82: //lead
                price = 5;
                break;
            case 26: //iron
                price = 3;
                break;
            case 22: //titanium
                price = 9;
                break;
        }
        int a = width, b = height, c = length;
        while(a % b != 0){
            int t = a % b;
            a = b;
            b = t;
        }
        while(c % b != 0){
            int t = c % b;
            c = b;
            b = t;
        }
        price = width * height * length * b * b * b * price;
        return price;
    }
}
