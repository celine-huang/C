#include <stdio.h>
#include <ctype.h>

int main(void){
    char string[100];
    int tail = 0;
    while(scanf("%c", &string[tail]) != EOF){
        if(string[tail] == '\n'){
            int head = 0;
            while(isspace(string[head]))
                head++;
            while(isspace(string[tail]))
                tail--;
            for(int i = head; i <= tail; i++)
                printf("%c", string[i]);
            printf("\n");
            tail = -1;
        }
        tail++;
    }
    return 0;
}
