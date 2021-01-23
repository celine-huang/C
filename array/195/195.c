#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int move[3][3] = {0};
    int i = 0, time = 0;
    while(i < n){
        int x, y;
        scanf("%d%d", &x, &y);
        if(x >= 0 && x <= 2 && y >= 0 && y <= 2 && move[x][y] == 0){
            time++;
            if(time%2 == 1)
                move[x][y] = 1;
            else if(time%2 == 0)
                move[x][y] = 2;
            //0:none;1:black;2:white
        }
        i++;
    }
    int win = 0;
    for(i = 0; i < 3; i++){
        if(move[i][0] == move[i][1] && move[i][1] == move[i][2])
            win = move[i][0];
        if(move[0][i] == move[1][i] && move[1][i] == move[2][i])
            win = move[0][i];
    }
    if(move[0][0] == move[1][1] && move[1][1] == move[2][2])
        win = move[0][0];
    if(move[0][2] == move[1][1] && move [1][1] == move[2][0])
        win = move[0][2];
    if(win == 0)
        printf("There is a draw.\n");
    else if(win == 1)
        printf("Black wins.\n");
    else if(win == 2)
        printf("White wins.\n");
    return 0;
}
