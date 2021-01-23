#include <stdio.h>
#define ROW 15
#define COL 15

int moveWays (int matrix[][COL], int row, int col, int step[][COL], int r, int c) {
    if(matrix[row][col] == 0){
        step[row][col] = 0;
        return 0;
    }
    if(row == r - 1 && col == 0){
        step[row][col] = 1;
        return 1;
    }
    if(row == r - 1){
        step[row][col] = moveWays(matrix, row, col-1, step, r, c);
        return moveWays(matrix, row, col-1, step, r, c);
    }
    if(col == 0){
        step[row][col] = moveWays(matrix, row+1, col, step, r, c);
        return moveWays(matrix, row+1, col, step, r, c);
    }    
    step[row][col] = (moveWays(matrix, row + 1, col, step, r, c) + moveWays(matrix, row, col - 1, step, r, c));
    return (moveWays(matrix, row + 1, col, step, r, c) + moveWays(matrix, row, col - 1, step, r, c));
}

int main (void) {
    int r, c;
    scanf("%d%d", &r, &c);
    int matrix[ROW][COL];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);
	int step[ROW][COL];
	printf("%d\n", moveWays(matrix, 0, c - 1, step, r, c));
	for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            printf("%d ", step[i][j]);
		printf("\n");
	}
    return 0;
}
