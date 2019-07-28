#include <stdio.h>
void test(int arr[3][3])
{
    int i, j, tmp;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            if (i > j)
            {
                tmp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = tmp;
            }

        }
    }
}

void print_arr(int arr[3][3])
{
    int i,j;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
            printf("%4d",arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void main()
{
    int arr[3][3]={{1, 2, 3,}, {4, 5, 6}, {7, 8, 9}};
    print_arr(arr);
    test(arr);
    print_arr(arr);
}
