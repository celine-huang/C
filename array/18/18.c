#include <stdio.h>
int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    int arr[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int lar[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            lar[i][j] = 0;
        }
    }
    //compare to the upper one
    for(int i = 1; i < r; i++){
        for(int j = 0; j < c; j++){
            if(arr[i][j] > arr[i-1][j]){
                lar[i][j]++;
            }
        }
    }
    //compare to the lower one
    for(int i = 0; i < r-1; i++){
        for(int j = 0; j < c; j++){
            if(arr[i][j] > arr[i+1][j]){
                lar[i][j]++;
            }
        }
    }
    //compare to the left one
    for(int i = 0; i < r; i++){
        for(int j = 1; j < c; j++){
            if(arr[i][j] > arr[i][j-1]){
                lar[i][j]++;
            }
        }
    }
    //compare to the right one
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c-1; j++){
            if(arr[i][j] > arr[i][j+1]){
                lar[i][j]++;
            }
        }
    }
    int print[r*c], num = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(((i == 0 && j == 0) || (i == 0 && j == c-1) || (i == r-1 && j == 0) || (i == r-1 && j == c-1)) && lar[i][j] == 2){
                print[num] = arr[i][j];
                num++;
            }else if((i == 0 || i == r-1 || j == 0 || j == c-1) && lar[i][j] == 3){
                print[num] = arr[i][j];
                num++;
            }else if(lar[i][j] == 4){
                print[num] = arr[i][j];
                num++;
            }
        }
    }
    for(int i = 0; i < num; i++){
        printf("%d\n", print[i]);
    }
    return 0;
}
