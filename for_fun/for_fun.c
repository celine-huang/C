#include <stdio.h>

void print(int *iptr){
    printf("*iptr = %d &(*iptr) = %p iptr = %p &iptr = %p\n", *iptr, &(*iptr), iptr, &iptr);
    return;
}

int main(){
    int i = 0, *iptr;
    printf("uninitialized: *iptr = i\nassignment makes integer from pointer without a cast: *iptr = &i  iptr = i\nlvalue required as left operand of assignment: &iptr = i  &iptr = &i  &(*iptr) = i  &(*iptr) = &i\n-----------------------------------------------------------------\n");
    iptr = &i;
    printf("point to reference: iptr = &i\n");
    print(iptr);
    *iptr = i;
    printf("dereference: *iptr = i\n");
    print(iptr);
    i = *iptr;
    printf("dereference: i = *iptr\n");
    print(iptr);
    return 0;
}
