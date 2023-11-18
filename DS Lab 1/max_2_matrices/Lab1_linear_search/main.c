#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,N,list[10];
    printf("Enter the number of Elements:\n");
    scanf("%d",&N);
    printf("Enter the numbers\n");
    for(i=0;i<N;i++)
        scanf("%d",&list[i]);
    int Searchkey,found=0;
    printf("what is to be searched?\n");
    scanf("%d",&Searchkey);
    for (i=0;i<N;i++)
    {
        if(list[i]==Searchkey)
            {
                found=1;
                printf("Found");
                break;
            }
    }
    if (found==0)
        printf("not found");

    return (0);
}
