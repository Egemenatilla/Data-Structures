#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int *arr; //An pointer array
    int element;
    printf("Enter number of elements: ");
    scanf("%d",&element);
    srand(time(NULL));

    arr = (int*)malloc(sizeof(int)*element);

    for(int i = 0;i<element;i++)
    {
        *(arr+i) = rand()%100;
    }

    for(int i = 0;i<element;i++)
        printf("%d ",*(arr+i));

    return 0;
}
