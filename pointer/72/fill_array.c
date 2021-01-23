#include "fill_array.h"

void fill_array(int *ptr[], int n){
    for(int i = 0; i < n; i++)
        *ptr[i] = i;
    int *front = ptr[0], *back = front + 1, ct = 1;
    while(ct < n){
        back = front + 1;
        while(*back == 0)
            back++;
        int sum = *front + *back;
        for(int *fill = front + 1; fill < back; fill++)
            *fill = sum;
        front = back;
        ct++;
    }
}
