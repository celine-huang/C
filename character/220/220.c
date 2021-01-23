#include <stdio.h>

int main(void){
    int ct = 0;
    char c;
    while(scanf("%c", &c) != EOF){
        if(c == '.'){
            int i = 0;
            while(1){
                scanf("%c", &c);
                //'\n',' ''\n'
                if(c == '\n'){
                    ct++;
                    break;
                }
                //'\0',' ''\0'
                else if(c == '\0'){
                    ct++;
                    printf("%d\n", ct);
                    return 0;
                }
                //' '' '
                else if(i == 0 && c == ' '){
                    i++;
                    /*scanf("%c", &c);
                    if(c == ' ' || c == '\n'){
                        ct++;
                        break;
                    }
                    else if(c == '\0'){
                        ct++;
                        printf("%d\n", ct);
                        return 0;
                    }
                    else{
                        break;
                    }*/
                }
                //' '' '
                else if(i == 1 && c == ' '){
                    ct++;
                    break;
                }
                else{
                    break;
                }
            }
        }
    }
    printf("%d\n", ct);
    return 0;
}
