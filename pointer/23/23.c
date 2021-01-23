#include <stdio.h>

int max(int *iptr[], int n);

int main()
{
  int n;
  int i;
  int array[100];
  int *iptr[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &(array[(i + 3) % n]));
    iptr[i] = &(array[(i + 3) % n]);
  }

  printf("%d\n", max(iptr, n));
  return 0;
}

int max(int *iptr[], int n){
    int value = *iptr[0];
    for(int i = 1; i < n; i++){
        if(*iptr[i] > value)
            value = *iptr[i];
    }
    return value;
}
