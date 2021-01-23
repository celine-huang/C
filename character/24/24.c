#include <stdio.h>
#include <ctype.h>

int main(void){
    char string[108];
    scanf("%s", string);
    int digit = 0, letter = 0, vowel = 0, consonant = 0;
    int i = 0;
    while(string[i] != '\0'){
        if(isdigit(string[i]))
            digit++;
        if(isalpha(string[i])){
            letter++;
            if(string[i] == 'a' || string[i] == 'A' || string[i] == 'e' || string[i] == 'E' || string[i] == 'i' || string[i] == 'I' || string[i] == 'o' || string[i] == 'O' || string[i] == 'u' || string[i] == 'U')
                vowel++;
            else
                consonant++;
        }
        i++;
    }
    printf("%d %d %d %d\n", digit, letter, vowel, consonant);
    return 0;
}
