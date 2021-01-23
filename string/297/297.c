#include <stdio.h>
#include <string.h>
#define STRINGLEN 100000
#define COMMANDLEN 10
#define DELIMETERLEN 5

int main(void){
    char string[STRINGLEN];
    scanf("%s", string);
    char command[COMMANDLEN];
    scanf("%s", command);
    while(strcmp(command, "end") != 0){
        if(strcmp(command, "replace") == 0){
            int n = strlen(string);
            char x[DELIMETERLEN], y[DELIMETERLEN];
            scanf("%s%s", x, y);
            char temp[STRINGLEN] = "";
            int replaceFirst = 1;
            if(string[0] == x[0])
                strcat(temp, y);
            int replaceLast = 0;
            if(string[n-1] == x[0])
                replaceLast = 1;
            char *start = string;
            start = strtok(start, x);
            while(start != NULL){
                if(replaceFirst == 1)
                    replaceFirst = 0;
                else
                    strcat(temp, y);
                strcat(temp, start);
                start = strtok(NULL, x);
            }
            if(replaceLast == 1)
                strcat(temp, y);
            strcpy(string, temp);
        }else if(strcmp(command, "remove") == 0){
            char x[DELIMETERLEN];
            scanf("%s", x);
            char temp[STRINGLEN] = "";
            char *start = string;
            start = strtok(start, x);
            while(start != NULL){
                strcat(temp, start);
                start = strtok(NULL, x);
            }
            strcpy(string, temp);
        }else if(strcmp(command, "addhead") == 0){
            char x[DELIMETERLEN];
            scanf("%s", x);
            char temp[STRINGLEN];
            strcpy(temp, string);
            strcpy(string, x);
            strcat(string, temp);
        }else if(strcmp(command, "addtail") == 0){
            char x[DELIMETERLEN];
            scanf("%s", x);
            strcat(string, x);
        }else{
            printf("invalid command %s\n", command);
            return 0;
        }
        scanf("%s", command);
    }
    printf("%s\n", string);
    return 0;
}
