#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void createTwoDimensionalArray(int **arr,int line,int column)
{
    int i,j;
    *arr = (int**)malloc(line*sizeof(int*));
    for(i = 0;i<line;i++)
    {
        *(*arr+i)=(int*)malloc(column*sizeof(int));
        for(j=0;j<column;j++)
            {
                *((*arr+i)+j) = rand()%100;
            }
    }
    for(int i = 0; i<line;i++)
    {

        for (int j = 0;j<column;j++)
        {
            printf("%d ",*((*arr+i)+j));
        }
        printf("\n");
    }
}

int main()
{
    int **arr;
    int line =3;
    int column =4;
    createTwoDimensionalArray(&arr, line , column);

    return 0;
}
