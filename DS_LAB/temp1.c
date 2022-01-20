#include <stdio.h>

int main()
{

    // Question 4: Make two arrays and merge them in the way that elements from both arrays are grouped odd and even.

    // Making first array
    int n1;
    printf("Enter the size of fisrt array: ");
    scanf("%d", &n1);
    int ar1[n1];
    for (int i = 0; i < n1; i++)
    {
        printf("Enter the element at index %d in fisrt array: ", i);
        scanf("%d", &ar1[i]);
    }

    // Making second array
    int n2;
    printf("\n\nEnter the size of second array: ");
    scanf("%d", &n2);
    int ar2[n2];
    for (int i = 0; i < n2; i++)
    {
        printf("Enter the element at index %d in second array: ", i);
        scanf("%d", &ar2[i]);
    }

    // Merging them
    int t = n1 + n2;
    int temp[t];
    for (int i = 0, j = n1; i < n1 || j < t - 1; i++, j++)
    {
        temp[i] = ar1[i];
        temp[j] = ar2[j - n1];
    }

    for(int i = 0; i < t; i++)
    {
        printf("%d \n", temp[i]);
    }

    // Making the final third array
    // int j = 0;
    // int k = 0;
    // int ar3[n1 + n2];
    // for(int i = 0; i< (n1 + n2); i++){
    //     if(temp[i] % 2 != 0){
    //         ar3[j] = temp[i];
    //         j++;
    //     }
    //     else{
    //         ar3[n1 + n2 -1 -k] = temp[i];
    //         k++;
    //     }
    // }

    // for(int i = 0; i< n1 + n2; i++){
    //     printf("element at index %d is %d \n", i, ar3[i]);
    // }

    return 0;
}