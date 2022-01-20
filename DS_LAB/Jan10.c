#include<stdio.h>

void display_matrix(int row, int col, int (*arr)[col]){
    printf("Matrix: \n");
    for(int i = 0 ; i < row; i++){
        printf("|");
        for(int j = 0; j < col; j++){
            printf("\t%d\t", arr[i][j]);
        }
        printf("|\n");
    }
}

int main(){

    printf("Enter the No. of rows in matrix: ");
    int row;
    scanf("%d", &row);
    printf("Enter the No. of columns in matrix: ");
    int col;
    scanf("%d", &col);
    
    int matrix[row][col];
    
    int nonZero = 0;

    for(int i = 0 ; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("Enter the matrix at index [%d][%d]: ", i, j);
            scanf("%d", *(matrix + i) +j);
            if(matrix[i][j] != 0){
                nonZero++;
            }
        }
    }

    printf("\nThis is entered matrix:\n");
    display_matrix(row, col, matrix);

    int cl = 0;
    int transformSparseMatrix[3][nonZero];
    for(int i = 0 ; i < row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j] != 0){
                transformSparseMatrix[0][cl] = i; 
                transformSparseMatrix[1][cl] = j; 
                transformSparseMatrix[2][cl] = matrix[i][j];
                cl++;
            }
        }
    }


    printf("\nThis is new transformed matrix: \n");
    display_matrix(3, nonZero, transformSparseMatrix);

    return 0;
}