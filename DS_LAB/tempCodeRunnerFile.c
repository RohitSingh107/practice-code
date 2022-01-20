#include<stdio.h>

void display_matrix(int row, int col, int (*arr)[col]){
    printf("Your Matrix: \n");
    for(int i = 0; i<row; i++){
        printf("|\t");
        for(int j =0; j<col; j++){
            printf("%d\t", *(*(arr + i) + j));
        }
        printf("|\n");
    }
}

void show_averages(int row, int col, int (*arr)[col]){

    float column_total = 0;
    float row_total = 0;

    printf("Matrix with averages of row and column: \n");
    for(int i = 0; i<row; i++){
        printf("|\t");
        column_total = 0;
        for(int j =0; j<col; j++){
            printf("%d\t", *(*(arr + i) + j));
            column_total += *(*(arr + i) + j);
        }
        printf("%.2f\t", column_total / col);
        printf("|\n");
    }

    printf("|\t");
    for(int i = 0; i<col; i++){
        row_total = 0;
        for(int j =0; j<row; j++){
            row_total += *(*(arr + j) + i);
        }
        printf("%.2f\t", row_total / row);
    }
    printf("\t|\n");

}


int main(){

    int row, col;
    
    printf("Enter the number of rows: ");
    scanf("%d", &row);

    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int matrix[row][col];

    for(int i = 0; i< row; i++){
        for(int j = 0; j< col; j++){
            printf("Enter the element at index [%d][%d] : ", i, j);
            scanf("%d", *(matrix + i) + j );
        }
    }

    display_matrix(row, col, matrix);
    show_averages(row, col, matrix);

    


    return 0;
}