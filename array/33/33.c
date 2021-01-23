#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int hori[n][n], verti[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            hori[i][j] = 0;
            verti[i][j] = 0;
        }
    }
    //compare to the upper one
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1 && arr[i-1][j] == 1){
                verti[i][j]++;
            }
        }
    }
    //compare to the lower one
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1 && arr[i+1][j] == 1){
                verti[i][j]++;
            }
        }
    }
    //compare to the left one
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(arr[i][j] == 1 && arr[i][j-1] == 1){
                hori[i][j]++;
            }
        }
    }
    //compare to the right one
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[i][j] == 1 && arr[i][j+1] == 1){
                hori[i][j]++;
            }
        }
    }
    int intersec = 0, tjunc = 0, turn = 0, dead = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(hori[i][j] + verti[i][j] == 4){
                intersec++;
            }else if(hori[i][j] + verti[i][j] == 3){
                tjunc++;
            }else if(hori[i][j] == 1 && verti[i][j] == 1){
                turn++;
            }else if(hori[i][j] + verti[i][j] == 1){
                dead++;
            }
        }
    }
    printf("%d\n%d\n%d\n%d\n", intersec, tjunc, turn, dead);
    return 0;
}
