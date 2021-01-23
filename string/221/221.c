#include <stdio.h>
#include <assert.h>
#include <string.h>
#define STRINGLENGTH 256
#define LINENUM 128
#define WORDNUM 128
#define LETTERNUM 256

int main(void){
    int m;
    scanf("%d", &m);
    char string[STRINGLENGTH];
    char line[LINENUM][WORDNUM][LETTERNUM];
    int linect = 0, wordct = 0;
    int letterct[LINENUM] = {0};
    while(scanf("%s", string) != EOF){
        int stringlength = strlen(string);
        assert(stringlength <= m);
        if(letterct[linect] + wordct + stringlength < m){
            strcpy(line[linect][wordct], string);
            letterct[linect] += stringlength;
            wordct++;
        }else if(letterct[linect] + wordct + stringlength == m){
            strcpy(line[linect][wordct], string);
            letterct[linect] += stringlength;
            linect++;
            letterct[linect] = 0;
            wordct = 0;
        }else{
            wordct = 0;
            linect++;
            strcpy(line[linect][wordct], string);
            letterct[linect] = stringlength;
            wordct++;
        }
    }    
    for(int i = 0; i <= linect; i++){
        wordct = 0;
        while(line[i][wordct][0] != '\0')
            wordct++;
        int space = m - letterct[i];
        if(space != 0){
		    for(int j = 0; j < space % (wordct-1); j++){
		        printf("%s", line[i][j]);
		        for(int k = 0; k <= space / (wordct-1); k++)
		            printf(" ");
		    }
		    for(int j = space % (wordct-1); j < (wordct-1); j++){
		        printf("%s", line[i][j]);
		        for(int k = 0; k < space / (wordct-1); k++)
		            printf(" ");
		    }
        }
        printf("%s\n", line[i][wordct-1]);
    }
    return 0;
}
