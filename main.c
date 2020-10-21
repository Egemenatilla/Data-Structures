#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void createAnArray(int **arr,int element)
{
    int i;
    *arr = (int*)malloc(sizeof(int)*element);
    for(i = 0;i<element;i++)
    {
        *(*arr+i) = rand()%5;
    }
    for(i = 0;i<element;i++)
    {
        printf("%d ",*(*arr+i));
    }
}

void createDynamicMatrix(int ***arr,int line,int column)
{
    int i,j;
    *arr = (int**)malloc(sizeof(int*)*line);
    for(i = 0;i<line;i++)
    {
        *(*arr+i) = (int*)malloc(sizeof(int)*column);
        for(j=0;j<column;j++)
        {
            *(*(*arr+i)+j) = rand()%5;
        }
    }
}

void writeDynamicMatrix(int **arr,int line,int column)
{
   int i,j;
   for(i=0;i<line;i++)
   {
       for(j=0;j<column;j++)
       {
           printf("%d ",*(*(arr+i)+j));
       }
       printf("\n");
   }
}

void dynamicMatrixMultiplication(int **A,int Aline, int Acolumn,
                           int **B, int Bline, int Bcolumn,
                           int **C, int Cline, int Ccolumn){


    int i,j,k;
    if(Acolumn!=Bline)
    {
        printf("The dimensions of the matrices do not match!!!\n");
        return;
    }
    else if(Aline!=Cline || Bcolumn!=Ccolumn)
    {
        printf("The dimensions of the result matrix do not fit the multiplier matrices!!!\n");
        return;
    }
    else
    {
        for(i=0; i<Aline; i++)
            {
                for(j=0; j<Bcolumn; j++)
                {
                    C[i][j]=0;
                    for(k=0; k<Acolumn; k++)
                        C[i][j]=C[i][j]+A[i][k]*B[k][j];
                }
            }
        writeDynamicMatrix(C,Cline,Ccolumn);
    }
}
void menu()
{
    printf("-------------------------------------\n");
    printf("Welcome!\n");
    printf("Press (1) for create an array\n");
    printf("Press (2) for create a matrix\n");
    printf("Press (3) for matrix multiplication\n");
    printf("Press (4) for exit\n");
    printf("-------------------------------------\n\n");
}


int main()
{
    srand(time(NULL));
    int **A,**B,**C;
    int *dizi;
    int choice;
    int element,line,column,line1,column1;
    menu();
    choice=0;
    printf("\nEnter the choice\n");
    while(choice!=4)
    {
        scanf("%d",&choice);
        if(choice==4)
        {
            printf("Ending...");
            break;
        }
        if(choice==1)
        {
           printf("Enter the number of element");
           scanf("%d",&element);
           createAnArray(&dizi,element);

        }
        else if(choice==2)
        {
            printf("Enter the number line\n");
            scanf("%d",&line);
            printf("Enter the number of column\n");
            scanf("%d",&column);
            createDynamicMatrix(&A,line,column);
            writeDynamicMatrix(A,line,column);

        }
        else if(choice==3)
        {
            printf("First matrix\n");
            printf("Enter the number line\n");
            scanf("%d",&line);
            printf("Enter the number of column\n");
            scanf("%d",&column);
            createDynamicMatrix(&A,line,column);
            writeDynamicMatrix(A,line,column);
            printf("Second Matrix\n");
            printf("Enter the number line\n");
            scanf("%d",&line1);
            printf("Enter the number of column\n");
            scanf("%d",&column1);
            createDynamicMatrix(&B,line1,column1);
            writeDynamicMatrix(B,line1,column1);
            printf("Product Matrix\n");
            createDynamicMatrix(&C,line,column1);
            dynamicMatrixMultiplication(A,line,column,B,line1,column1,C,line,column1);

        }
        printf("\nEnter the choice\n");
    }

    return 0;
}
