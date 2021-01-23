#include <stdio.h>
#define ROW 15
#define COL 15

int moveWays (int matrix[][COL], int row, int col, int rows, int columns) {
    if(matrix[row][col] == 0)
        return 0;
    if(row == rows - 1 && col == 0)
        return 1;
    if(row == rows - 1)
        return moveWays(matrix, row, col - 1, rows, columns);
    if(col == 0)
        return moveWays(matrix, row + 1, col, rows, columns);
    return (moveWays(matrix, row + 1, col, rows, columns) + moveWays(matrix, row, col - 1, rows, columns));
}

int main (void) {
    int r, c;
    scanf("%d%d", &r, &c);
    int matrix[ROW][COL];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);
	printf("%d\n", moveWays(matrix, 0, c - 1, r, c));
    return 0;
}
