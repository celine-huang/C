#include <stdio.h>

int max(int array[5][5]){
    int value = array[0][0];
    for(int i = 0; i < 5; i++)
        for(int j = 1; j < 5; j++)
            if(array[i][j] > value)
                value = array[i][j];
    return value;
}

int main()
{
  int i, j;
  int array[5][5];
  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++)
      scanf("%d", &(array[i][j]));
  printf("%d\n", max(array));
  return 0;
}
