#include <stdio.h>
#include <stdlib.h>

// Here, the parameter is an array of pointers
void assign(int **arr, int m, int n) //? void function((*arr)[n]);
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the value at index [%d][%d]: ", i, j);
            scanf("%d", (*(arr + i) + j));
        }
    }
}

void average(int **arr, int m, int n)
{
    float sum = 0, avg;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", *(*(arr + i) + j));
            sum += *(*(arr + i) + j);
        }
        // printf("\n");
        avg = sum / n;
        printf("%.2f", avg);
        printf("\n");
        sum = 0;
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            // printf("%d", *(*(arr + i) + j));
            sum += *(*(arr + i) + j);
        }
        // printf("\n");
        avg = sum / m;
        printf("%.2f\t", avg);
        sum = 0;
    }
}

int main()
{
    int m, n;
    printf("Enter the size of the Matrix: ");
    scanf("%d %d", &m, &n);

    int **arr = (int **)malloc(m * sizeof(int *)); //* dynamic

    for (int r = 0; r < m; r++)
    {
        arr[r] = (int *)malloc(n * sizeof(int));
    }

    assign(arr, m, n);

    // print 2D array
    printf("Matrix Entered:");
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }

    average(arr, m, n);

    // deallocate memory
    for (int i = 0; i < m; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}