#include <stdio.h>
#include <string.h>

int compare_and_add(char *string, char seen[][80], int count[]);
void sort_and_print(char seen[][80], int count[]);
int main(){
 char seen[20][80] = {{0}};
 int count[20] = {0};
 compare_and_add( "This",   seen, count );
 compare_and_add( "is",     seen, count );
 compare_and_add( "an",     seen, count );
 compare_and_add( "apple,", seen, count );
 compare_and_add( "and",    seen, count );
 compare_and_add( "this",   seen, count );
 compare_and_add( "is",     seen, count );
 compare_and_add( "a",      seen, count );
 compare_and_add( "book.",  seen, count );
 sort_and_print( seen, count );
}

int compare_and_add(char *string, char seen[][80], int count[]){
    int i = 0;
    while(seen[i][0] != '\0'){
        if(strcmp(string, seen[i]) == 0){
            count[i]++;
            return 1;
        }
        i++;
    }
    strcpy(seen[i], string);
    count[i] = 1;
    return 0;
}

void sort_and_print(char seen[][80], int count[]){
    int n = 0;
    while(seen[n][0] != '\0')
        n++;
    for(int i = n - 2; i >= 0; i--)
        for(int j = 0; j <= i; j++)
            if(count[j] > count[j+1] || (count[j] == count[j+1] && strcmp(seen[j], seen[j+1]) > 0)){
                char temp[80] = {0};
                strcpy(temp, seen[j]);
                strcpy(seen[j], seen[j+1]);
                strcpy(seen[j+1], temp);
                int t = count[j];
                count[j] = count[j+1];
                count[j+1] = t;
            }
    for(int i = 0; i < n; i++)
        printf("%d %s\n", count[i], seen[i]);
    return;
}
