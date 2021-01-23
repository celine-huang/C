#include <stdio.h>
#include "card.h"

void shuffle(int *deck[]){
    int n = 0;
    while(deck[n] != NULL)
        n++;
    if(n == 0)
        return;
    int *first[n], *second[n];
    int firstn = 0, secondn = 0, i = 0;
    if(n % 2 == 1){
        while(firstn < n / 2 + 1){
            first[firstn] = deck[i];
            firstn++;
            i++;
        }
        first[firstn] = NULL;
    }else{
        while(firstn < n / 2){
            first[firstn] = deck[i];
            firstn++;
            i++;
        }
		first[firstn] = NULL;
    }
    while(deck[i] != NULL){
            second[secondn] = deck[i];
            secondn++;
            i++;
    }
	second[secondn] = NULL;   
    n = 0, firstn = 0, secondn = 0;
    while(deck[n] != NULL){
        if(n % 2 == 0){
            deck[n] = first[firstn];
            firstn++;
        }else{
            deck[n] = second[secondn];
            secondn++;
        }
        n++;
    }
}

void print(int *deck[]){
    int index = 0;
    if(deck[index] == NULL)
        return;
    printf("%d", *deck[index]);
    index++;
    while(deck[index] != NULL){
        printf(" %d", *deck[index]);
        index++;
    }
    printf("\n");
}
