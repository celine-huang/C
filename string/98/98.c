#include <stdio.h>
#include <string.h>
#include <assert.h>
#define NAMELENGTH 64
#define INGREDIENTNUM 10

typedef struct food{
    char name[NAMELENGTH];
    int ingredientNum;
    char ingredient[INGREDIENTNUM][NAMELENGTH];
}Food;

int find(char *name, const Food food[]){
    int index = 0;
    while(strcmp(name, food[index].name) != 0)
        index++;
    return index; 
}

void bubbleSort(char array[][NAMELENGTH], int n){
    for(int i = n - 2; i >= 0; i--)
        for(int j = 0; j <= i; j++)
            if(strcmp(array[j], array[j+1]) > 0){
                char temp[NAMELENGTH];
                strcpy(temp, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], temp);
            }
}

int main(void){
    int n;
    scanf("%d", &n);
    assert(n > 0 && n <= 100);
    Food food[n];
    for(int i = 0; i < n; i++){
        scanf("%s", food[i].name);
        scanf("%d", &food[i].ingredientNum);
        assert(food[i].ingredientNum > 0 && food[i].ingredientNum <= 10);
        for(int j = 0; j < food[i].ingredientNum; j++)
            scanf("%s", food[i].ingredient[j]);
        food[i].ingredient[food[i].ingredientNum][0] = '\0';
    }
    int m;
    scanf("%d", &m);
    char query[m][2][NAMELENGTH];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < 2; j++)
            scanf("%s", query[i][j]);
    for(int i = 0; i < m; i++){
        int comp1 = find(query[i][0], food);
        int comp2 = find(query[i][1], food);
        char same[INGREDIENTNUM][NAMELENGTH] = {0};
        int sameNum = 0;
        int j = 0;
        while(food[comp1].ingredient[j][0] != '\0'){
            int k = 0;
            while(food[comp2].ingredient[k][0] != '\0'){
                if(strcmp(food[comp1].ingredient[j], food[comp2].ingredient[k]) == 0){
                    strcpy(same[sameNum], food[comp1].ingredient[j]);
                    sameNum++;
                }
                k++;
            }
            j++;
        }
        if(same[0][0] == '\0')
            printf("nothing\n");
        else{
            bubbleSort(same, sameNum);
            printf("%s", same[0]);
            for(int k = 1; k < sameNum; k++)
                printf(" %s", same[k]);
            printf("\n");
        }
    }
    return 0;
}
