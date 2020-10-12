#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void createOneDimensionalArray(int **arr,int element )
{
    *arr = (int*)malloc(sizeof(int)*element);
    for(int i = 0;i<element;i++)
    {
        *(*arr+i) = rand()%100;
    }
    for(int i = 0;i<element;i++)
        printf("%d ",*(*arr+i));

}

int main()
{
    int element;
    int *arr;
    printf("Enter the number of elements: ");
    scanf("%d",&element);

    createOneDimensionalArray(&arr,element);

    return 0;
}
