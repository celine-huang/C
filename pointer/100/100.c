#include <stdio.h>
#include <assert.h>

void snake(const int *ptr_array[100][100], int m);

int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;

  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }

  snake(ptr_array, m);

  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }

  return 0;
}

void snake(const int *ptr_array[100][100], int m){
    for(int i = m * m - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(*ptr_array[j/m][j%m] > *ptr_array[(j+1)/m][(j+1)%m]){
                const int *temp = ptr_array[j/m][j%m];
                ptr_array[j/m][j%m] = ptr_array[(j+1)/m][(j+1)%m];
                ptr_array[(j+1)/m][(j+1)%m] = temp;
            }           
        }
    }
    for(int i = 0; i < m; i++){
        if(i % 2 == 1){
            for(int j = 0; j < m / 2; j++){
                const int *temp = ptr_array[i][j];
                ptr_array[i][j] = ptr_array[i][m-j-1];
                ptr_array[i][m-j-1] = temp;
            }
        }
    }
    return;
}
