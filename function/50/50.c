#include <stdio.h>

int findrectangle(int l, int b, int r, int t);
int leftbottom(int a, int b);
int righttop(int a, int b);

int main(void){
    int co[3][4];//0:left,1:bottom,2:right,3:top
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++)
            scanf("%d", &co[i][j]);
    
    int rec1[3];
    for(int i = 0; i < 3; i++)
        rec1[i] = findrectangle(co[i][0], co[i][1], co[i][2], co[i][3]);
    
    int rec2[3];
    for(int i = 0; i < 3; i++){
        if(i == 2)//0&2
            rec2[i] = findrectangle(leftbottom(co[i-2][0], co[i][0]), leftbottom(co[i-2][1], co[i][1]), righttop(co[i-2][2], co[i][2]), righttop(co[i-2][3], co[i][3]));
        else//0&1,1&2
            rec2[i] = findrectangle(leftbottom(co[i][0], co[i+1][0]), leftbottom(co[i][1], co[i+1][1]), righttop(co[i][2], co[i+1][2]), righttop(co[i][3], co[i+1][3]));
    }
    
    int rec3 = findrectangle(leftbottom(leftbottom(co[0][0], co[1][0]), co[2][0]), leftbottom(leftbottom(co[0][1], co[1][1]), co[2][1]), righttop(righttop(co[0][2], co[1][2]), co[2][2]), righttop(righttop(co[0][3], co[1][3]), co[2][3]));
    
    int overlap = 0;
    for(int i = 0; i < 3; i++){
        overlap = overlap + rec1[i] - rec2[i];
    }
    overlap += rec3;
    printf("%d\n", overlap);
    return 0;
}

int leftbottom(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int righttop(int a, int b){
    if(a > b)
        return b;
    else
        return a;
}

int findrectangle(int l, int b, int r, int t){
    return (r - l) * (t - b);
}
