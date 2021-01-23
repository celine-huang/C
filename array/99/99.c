#include <stdio.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    char name[n][64];
    int board[n][m][m];
    for(int i = 0; i < n; i++){
        scanf("%s", name[i]);
        fflush(stdin);
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                scanf("%d", &board[i][j][k]);
            }
        }
    }
    int call, bingo;
    for(int i = 0; i < m*m; i++){
        scanf("%d", &call);
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(board[j][k][l] == call){
                        board[j][k][l] = 0;
                    }
                    int b = 0, c = 0, d = 0, line = 0;
                    while(b < n){
                        while(c < m){
                            while(d < m-1){
                                if(board[b][c][d] == board[b][c][d+1]){
                                    line++;
                                }
                                d++;
                            }
                            if(line == 5){
                                bingo = call;
                            }
                            c++;
                        }
                        b++;
                    }
                }
            }
        }
    }

    return 0;
}
