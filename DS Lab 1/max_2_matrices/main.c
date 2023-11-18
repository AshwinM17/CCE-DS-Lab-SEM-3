#include <stdio.h>
#include <stdlib.h>
void reader(int row,int column,int a[][column]);
int main()
{
    int row,column,i,j;
    printf("Enter the number of rows\n");
    scanf("%d",&row);
    printf("Enter the number of columns\n");
    scanf("%d",&column);
    int a[row][column],b[row][column],c[row][column];
    printf("Enter the elemets of 1st matrix\n");
    reader(row,column,a);
    printf("Enter the elemets of 2nd matrix\n");
    reader(row,column,b);
    for (i=0;i<row;i++)
        for(j=0;j<column;j++)
        {
            if(a[i][j]>=b[i][j])
                c[i][j]=a[i][j];
            else
                c[i][j]=b[i][j];
        }
    printf("Max Matrix:-\n");
    for (i=0;i<row;i++)
        {

            for(j=0;j<column;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }


}
void reader(int row,int column,int a[][column])
{
    int i,j;

    for (i=0;i<row;i++)
        for(j=0;j<column;j++)
            scanf("%d",&a[i][j]);
}
