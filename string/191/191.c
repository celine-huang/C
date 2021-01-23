#include <stdio.h>
#include <string.h>

void count(char *string, int *nchar, int *nword, int *ntokens, int *nline){
    //nchar
    *nchar = strlen(string);
    //nword
    *nword = 0;
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *start = string;
    int skipLength = strcspn(start, letters);
    while(skipLength < strlen(start)){
        start += skipLength;
        int wordLength = strspn(start, letters);
        *nword += 1;
        start += wordLength;
        skipLength = strcspn(start, letters);
    }
    //ntokens
    *ntokens = 0;
    char whiteSpace[] = " \t\n";
    start = string;
    skipLength = strspn(start, whiteSpace);
    while(skipLength < strlen(start)){
        start += skipLength;
        int tokenLength = strcspn(start, whiteSpace);
        *ntokens += 1;
        start += tokenLength;
        skipLength = strspn(start, whiteSpace);
    }
    //nline
    *nline = 0;
    for(int i = 0; i < *nchar; i++){
      if(string[i] == '\n')
        *nline += 1;
    }
}

int main()
{
    int len, numChar, numWord, numTokens, numLine;
    char str[]="\tThis is Sample-Input string.\nHope this helps!\n\n";
    count(str, &numChar, &numWord, &numTokens, &numLine);
    printf("%s: %d %d %d %d\n", str, numChar, numWord, numTokens, numLine);
    return 0;
}
