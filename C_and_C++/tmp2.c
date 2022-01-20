#include <stdio.h>

int main()
{
       int sparmat[100][100];
       int row,colm;
       
       printf("Enter the no. of rows & column max 100\n");
       scanf("%d %d",&row,&colm);
       
       printf("Enter the sparsmatrix\n");
       for (int i=0;i<row;i++){
        for (int j=0;j<colm;j++)
        {
            scanf("%d",&sparmat[i][j]);
        }
       }


      int size =0;
      for (int i=0;i<row;i++){
        for (int j=0;j<colm;j++)
        {
            if (sparmat[i][j] !=0)
            size++;
        }
        }

      int mat[3][size];
      int k=0;
      for (int i=0;i<row;i++){
        for (int j=0;j<colm;j++)
        {
            if (sparmat[i][j] !=0){
            mat[0][k] = i;
            mat[1][k] = j;
            mat[2][k] = sparmat[i][j];
            k++;
            }
        }
        }
      
   

      printf("Final Matrix:\n\n");
      for (int i=0;i<3;i++)
        {   for (int j=0;j<size;j++){
               printf("%d\t", mat[i][j]);
            }
            printf("\n");
        }
    return 0;
}