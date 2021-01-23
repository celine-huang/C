#include <stdio.h>

void intersection(int map[100][100], int result[4]);
//intersection:0,t-junction:1,turn:2,dead:3

int main(void){
    int map[100][100];
    int result[4] = {0};
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            scanf("%d", &map[i][j]);
        }
    }
    intersection(map, result);
    for(int i = 0; i < 4; i++)
        printf("%d\n", result[i]);
    return 0;
}

void intersection(int map[100][100], int result[4]){
    int hori[100][100] = {0}, verti[100][100] = {0};
    //compare to the upper one
    for(int i = 1; i < 100; i++)
        for(int j = 0; j < 100; j++)
            if(map[i][j] == 1 && map[i-1][j] == 1)
                verti[i][j]++;
    //compare to the lower one
    for(int i = 0; i < 99; i++)
        for(int j = 0; j < 100; j++)
            if(map[i][j] == 1 && map[i+1][j] == 1)
                verti[i][j]++;
    //compare to the left one
    for(int i = 0; i < 100; i++)
        for(int j = 1; j < 100; j++)
            if(map[i][j] == 1 && map[i][j-1] == 1)
                hori[i][j]++;
    //compare to the right one
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 99; j++)
            if(map[i][j] == 1 && map[i][j+1] == 1)
                hori[i][j]++;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(hori[i][j] + verti[i][j] == 4)
                result[0]++;
            else if(hori[i][j] + verti[i][j] == 3)
                result[1]++;
            else if(hori[i][j] == 1 && verti[i][j] == 1)
                result[2]++;
            else if(hori[i][j] + verti[i][j] == 1)
                result[3]++;
        }
    }
    return;
}
