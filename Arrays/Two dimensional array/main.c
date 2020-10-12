#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int **arr;
    int line,column;
    printf("Enter the number of line: ");
    scanf("%d",&line);
    printf("Enter the number of column: ");
    scanf("%d",&column);

    arr = (int**)malloc(sizeof(int*));
    for(int i = 0;i<line;i++)
    {
        *(arr+i) = (int*)malloc(sizeof(int)*column);
        for(int j = 0;j<column;j++)
        {
            *(*(arr+i)+j) = rand()%100;
        }
    }
    for(int i = 0; i<line;i++)
    {

        for (int j = 0;j<column;j++)
        {
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
    return 0;
}
