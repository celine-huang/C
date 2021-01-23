#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
    int problem, ac, wa;
    scanf("%d%d%d", &problem, &ac, &wa);
    char correctans[problem][10];
    for(int i = 0; i < problem; i++)
        scanf("%s", correctans[i]);
    int student;
    scanf("%d", &student);
    char studentans[student][problem][10];
    for(int i = 0; i < student; i++)
        for(int j = 0; j < problem; j++){
            scanf("%s", studentans[i][j]);
            if(strcmp(studentans[i][j], "N/A") != 0){
                int k = 0;
                while(studentans[i][j][k] != '\0'){
                    studentans[i][j][k] = toupper(studentans[i][j][k]);
                    k++;
                }
                for(int m = k - 2; m >= 0; m--)
                    for(int n = 0; n <= m; n++)
                        if(studentans[i][j][n] > studentans[i][j][n+1]){
                            char temp = studentans[i][j][n];
                            studentans[i][j][n] = studentans[i][j][n+1];
                            studentans[i][j][n+1] = temp;
                        }
            }
        }
    for(int i = 0; i < student; i++){
        int total = 0;
        for(int j = 0; j < problem; j++){
            if(strcmp(studentans[i][j], correctans[j]) == 0)
                total += ac;
            else if(strcmp(studentans[i][j], "N/A") == 0)
                total += 0;
            else
                total -= wa;
        }
        if(total < 0)
            total = 0;
        printf("%d\n", total);
    }
    return 0;
}
