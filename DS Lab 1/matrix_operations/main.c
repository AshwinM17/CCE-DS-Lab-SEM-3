#include <stdio.h>
#include <stdlib.h>

void reader(int row,int column,int a[][column]);
void multiplier();
void addition();
void magic_square();
int main()
{
    int n;
    printf("What do you want to do?\nPress 1 for addition\nPress 2 for multiplication\nPress 3 for checking magic square\n");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        {
            addition();
            break;
        }
    case 2:
        {
            multiplier();
            break;
        }
    case 3:
        magic_square();
        break;
    }
}

void reader(int row,int column,int a[][column])
{
    int i,j;

    for (i=0;i<row;i++)
        for(j=0;j<column;j++)
            scanf("%d",&a[i][j]);
}

void multiplier()
{
    int row1,column1,row2,column2,i,j;                  //reading matrix 1
    printf("Enter the number of rows of matrix 1\n");
    scanf("%d",&row1);
    printf("Enter the number of columns of matrix 1\n");
    scanf("%d",&column1);
    int a[row1][column1];
    printf("Enter the elemets of 1st matrix\n");
    reader(row1,column1,a);

    printf("Enter the number of rows of matrix 2\n");   //reading matrix 2
    scanf("%d",&row2);
    printf("Enter the number of columns of matrix 2\n");
    scanf("%d",&column2);
    int b[row2][column2];
    printf("Enter the elemets of 2nd matrix\n");
    reader(row2,column2,b);

    printf("Trying to multiply\n");                   //checking if matrices can be multiplied
    int row3=row1,column3=column2;
    int c[row3][column3];
    int sum=0,k;
    if (column1==row2)
    {
        for (i=0;i<row1;i++)
            for(j=0;j<column2;j++)
            {
                for(k=0;k<column1;k++)
                    sum+=a[i][k]*b[k][j];
                c[i][j]=sum;
                sum=0;
            }
        printf("Multiplied matrix:\n");
        for (i=0;i<row1;i++)
        {
            for(j=0;j<column2;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }

    }
    else
        printf("these matrices can't be multiplied\n");

}

void addition()
{
    int row1,column1,row2,column2,i,j;                  //reading matrix 1
    printf("Enter the number of rows of matrix 1\n");
    scanf("%d",&row1);
    printf("Enter the number of columns of matrix 1\n");
    scanf("%d",&column1);
    int a[row1][column1];
    printf("Enter the elemets of 1st matrix\n");
    reader(row1,column1,a);

    printf("Enter the number of rows of matrix 2\n");   //reading matrix 2
    scanf("%d",&row2);
    printf("Enter the number of columns of matrix 2\n");
    scanf("%d",&column2);
    int b[row2][column2];
    printf("Enter the elemets of 2nd matrix\n");
    reader(row2,column2,b);

    printf("Trying to add\n");
    if (row1==row2 && column1==column2)
    {
        int c[row1][column1];
        for (i=0;i<row1;i++)
            for (j=0;j<column1;j++)
                c[i][j]=a[i][j]+b[i][j];
        printf("Added matrix:\n");
        for (i=0;i<row1;i++)
        {
            for(j=0;j<column2;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }
    }
    else
        printf("can not add");

}

void magic_square()
{
    int row1,column1,row2,column2,i,j;                  //reading matrix
    printf("Enter the number of rows of matrix\n");
    scanf("%d",&row1);
    printf("Enter the number of columns of matrix\n");
    scanf("%d",&column1);
    int a[row1][column1];
    printf("Enter the elemets of the matrix\n");
    reader(row1,column1,a);
    if (row1==column1)
    {
       int sum1=0,sum2=0,i,j;
       for(i=0;i<row1;i++)
            for(j=0;j<column1;j++)                     //checking diagonals
       {
           if(i==j)
            sum1+=a[i][j];

           if(j==(column1-i-1))
            sum2+=a[i][j];
       }
       int flag;
       if (sum1==sum2)
       {
           flag=1;
           int sumrow=0,sumcol=0;
           for(i=0;i<row1;i++)
           {
               for(j=0;j<row1;j++)
               {
                   sumrow+=a[i][j];
                   sumcol+=a[j][i];
               }
               if (sum1!=sumrow || sumcol!=sum1)
               {
                   flag=0;
                   break;
               }
               sumrow=sumcol=0;
           }
       }
       if (flag==1)
        printf("It is a Magic square");
       else
        printf("It is not a Magic square");
    }
    else
        printf("Matrix is not a square matrix,thus can't be a magic square");
}
