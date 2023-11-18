#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,N,list[10];
    printf("Enter the number of elements\n");
    scanf("%d",&N);
    printf("Enter the numbers\n");
    for(i=0;i<N;i++)
        scanf("%d",&list[i]);
    int buffer;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N-i-1;j++)
            if (list[j]>list[j+1])
        {
            buffer=list[j];
            list[j]=list[j+1];
            list[j+1]=buffer;
        }
    }
    for(i=0;i<N;i++)
        printf("%d ",list[i]);

}
