#include <stdio.h>

int main(void){
    char string[108];
    scanf("%s", string);
    int alphabet[26] = {0};
    int i = 0;
    while(string[i] != '\0'){
        if(string[i] >= 65 && string[i] <= 90)
            alphabet[string[i]-65]++;
        else if(string[i] >= 97 && string[i] <= 122)
            alphabet[string[i]-97]++;
        i++;
    }
    for(int i = 0; i < 26; i++)
        printf("%d\n", alphabet[i]);
    return 0;
}
