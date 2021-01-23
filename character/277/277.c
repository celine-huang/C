#include <stdio.h>
#include <assert.h>
#define STRINGLEN 15

void PrintDigit(char string[STRINGLEN], int width, int height);

int main(void){
    char string[STRINGLEN];
    int width, height; 
    while(scanf("%s", string) != EOF){
        scanf("%d%d\n", &width, &height);
        assert(width >= 4 && width <= 9 && height >= 5 && height <= 15 && height % 2 == 1);
        PrintDigit(string, width, height);
    }
    return 0;
}

void PrintDigit(char string[STRINGLEN], int width, int height){
    //top horizontal line
    int i = 0;
    while(string[i] != '\0'){
        printf(" ");
        switch(string[i]){
            case '0': case '2': case '3': case '5': case '6': case '7': case '8': case '9':
                for(int j = 0; j < width - 3; j++)
                    printf("%c", string[i]);
                break;
            case '1': case '4':
                for(int j = 0; j < width - 3; j++)
                    printf(" ");
                break;
        }
        printf("  ");
        i++;
    }
    printf("\n");
    //first two vertical lines
    for(int j = 0; j < (height - 3) / 2; j++){
        i = 0;
        while(string[i] != '\0'){    
    	    switch(string[i]){
                case '0': case '4': case '7': case '8': case '9':
                    printf("%c", string[i]);
                    for(int k = 0; k < width - 3; k++)
                        printf(" ");
                    printf("%c", string[i]);
                break;
            case '1': case '2': case '3':
                    printf(" ");
                    for(int k = 0; k < width - 3; k++)
                        printf(" ");
                    printf("%c", string[i]);
                break;
            case '5': case '6':
                    printf("%c", string[i]);
                    for(int k = 0; k < width - 3; k++)
                        printf(" ");
                    printf(" ");
                break;
            }
            printf(" ");
            i++;
        }
        printf("\n");
    }
    //middle horizontal line
    i = 0;
    while(string[i] != '\0'){
        printf(" ");
        switch(string[i]){
            case '2': case '3': case '4': case '5': case '6': case '8': case '9':
                for(int j = 0; j < width - 3; j++)
                    printf("%c", string[i]);
                break;
            case '0': case '1': case '7':
                for(int j = 0; j < width - 3; j++)
                    printf(" ");
                break;
        }
        printf("  ");
        i++;
    }
    printf("\n");
    //last two vertical lines
    for(int j = 0; j < (height - 3) / 2; j++){
        i = 0;
        while(string[i] != '\0'){    
    	    switch(string[i]){
                case '0': case '6': case '8':
                    printf("%c", string[i]);
                    for(int k = 0; k < width - 3; k++)
                        printf(" ");
                    printf("%c", string[i]);
                break;
            case '1': case '3': case '4': case '5': case '7': case '9': 
                    printf(" ");
                    for(int k = 0; k < width - 3; k++)
                        printf(" ");
                    printf("%c", string[i]);
                break;
            case '2':
                    printf("%c", string[i]);
                    for(int k = 0; k < width - 3; k++)
                        printf(" ");
                    printf(" ");
                break;
            }
            printf(" ");
            i++;
        }
        printf("\n");
    }
    //bottom horizontal line
    i = 0;
    while(string[i] != '\0'){
        printf(" ");
        switch(string[i]){
            case '0': case '2': case '3': case '5': case '6': case '8':
                for(int j = 0; j < width - 3; j++)
                    printf("%c", string[i]);
                break;
            case '1': case '4': case '7': case '9':
                for(int j = 0; j < width - 3; j++)
                    printf(" ");
                break;
        }
        printf("  ");
        i++;
    }
    printf("\n");
    return;
}
