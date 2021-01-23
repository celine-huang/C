#include <stdio.h>
#include <string.h>

int main(void){
    char digit[1020];
    while(1){
       scanf("%s", digit);
       if(strcmp(digit, "-1") == 0)
           return 0;
       //divisible-by-two
       if((digit[strlen(digit) - 1] - 48) % 2 == 0)
           printf("yes ");
       else
           printf("no ");
       //divisible-by-three
       int sum = 0;
       for(int i = 0; i < strlen(digit); i++)
           sum += digit[i] - 48;
       if(sum % 3 == 0)
           printf("yes ");
       else
           printf("no ");
       //divisible-by-five
       if((digit[strlen(digit) - 1] - 48) % 5 == 0 || (digit[strlen(digit) - 1] - 48) % 5 == 5)
           printf("yes ");
       else
           printf("no ");
       //divisible-by-eleven
       int sumodd = 0, sumeven = 0;
       for(int i = 0; i < strlen(digit); i++){
           if(i % 2 == 0)
               sumodd += digit[i] - 48;
           else
               sumeven += digit[i] - 48;
       }
       if((sumodd - sumeven) % 11 == 0)
           printf("yes\n");
       else
           printf("no\n");
    }
    return 0;
}
