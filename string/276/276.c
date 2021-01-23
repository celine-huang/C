#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LINENUM 128
#define STRINGLEN 128

int main(void){
    char temp[STRINGLEN], abbr[LINENUM][STRINGLEN];
    int linenum = 0, letter = 0;
    while(scanf("%s", temp) != EOF){
        if(strcmp(temp, "of") != 0 && strcmp(temp, "and") != 0 && strcmp(temp, "the") != 0 && strcmp(temp, "at") != 0){
            abbr[linenum][letter] = toupper(temp[0]);
            letter++;
            int i = 0;
            while(temp[i] != '\0')
                i++;
            if(temp[i-1] == '.'){
                linenum++;
                letter = 0;
            }
        }
    }
    int i = 0;
    while(abbr[i][0] != '\0'){
        printf("%s\n", abbr[i]);
        i++;
    }
    return 0;
}
