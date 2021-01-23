#include <stdio.h>
#include <string.h>
#define STRINGLEN 80

int main(void){
    int n;
    scanf("%d", &n);
    char string[n][2][STRINGLEN];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            scanf("%s", string[i][j]);
    for(int i = 0; i < n; i++){
        if(strcmp(string[i][0], string[i][1]) == 0)
            printf("yes\n");
        else{
            int stringlen1 = strlen(string[i][0]);
            int stringlen2 = strlen(string[i][1]);
            if(stringlen1 == stringlen2){
                int sim = 0, diff = 0;
                for(int j = 0; j < stringlen1; j++){
                    if(string[i][0][j] != string[i][1][j]){
                        if(string[i][0][j] == string[i][1][j+1] && string[i][0][j+1] == string[i][1][j])
                            sim++;
                        else
                            diff++;
                    }
                }
                if(sim == 1 && diff == 1)
                    printf("yes\n");
                else
                    printf("no\n");
            }else if(stringlen1 == stringlen2 + 1){
                int diff = 0;
                for(int j = 0; j < stringlen2; j++){
                    if(string[i][0][j] != string[i][1][j]){
                        if(string[i][0][j+1] != string[i][1][j])
                            diff = 1;
                    }
                }
                if(diff == 0)
                    printf("yes\n");
                else
                    printf("no\n");
            }else if(stringlen1 + 1 == stringlen2){
                int diff = 0;
                for(int j = 0; j < stringlen1; j++){
                    if(string[i][0][j] != string[i][1][j]){
                        if(string[i][0][j] != string[i][1][j+1])
                            diff = 1;
                    }
                }
                if(diff == 0)
                    printf("yes\n");
                else
                    printf("no\n");
            }else
                printf("no\n");
        }
    }
    return 0;
}
