#include <stdio.h>
#include <string.h>
#define STRINGLEN 128

int main(void){
    char string[STRINGLEN], output[STRINGLEN] = "";
    while(scanf("%s", string) != EOF){
        int stringlen = strlen(string);
        int outputlen = strlen(output);
        int fusion = 0;
        for(int i = 1; i <= stringlen; i++){
            int lap = 0;
            for(int j = 0; j < i; j++)
                if(string[j] == output[outputlen-i+j])
                    lap++;
            if(lap == i)
                fusion = lap;
        }
        for(int i = outputlen - fusion; i < outputlen; i++)
            output[i] = '\0';
        strcat(output, string);
    }
    printf("%s\n", output);
    return 0;
}
