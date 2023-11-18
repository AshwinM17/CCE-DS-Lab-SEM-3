#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,N,list[10];
    printf("Enter the number of elements:\n");
    scanf("%d",&N);
    printf("Enter the numbers\n");
    for(i=0;i<N;i++)
        scanf("%d",&list[i]);
    int Searchkey,found=0;
    printf("what is to be searched?\n");
    scanf("%d",&Searchkey);
    int high,low=0,mid;
    high=N-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if (Searchkey==list[mid])
        {
            printf("Found at position %d",mid+1);
            found=1;
            break;
        }
        if (Searchkey<list[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    if (found==0)
        printf("Not Found");
    return 0;
}

