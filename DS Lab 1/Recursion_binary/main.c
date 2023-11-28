#include <stdio.h>
#include <stdlib.h>
int binsearch(int arr[],int low,int high,int element)
{
    if (high>=low)
    {
        int mid=(low+high)/2;

        if (arr[mid]==element)
        {
            return mid;
        }
        if(arr[mid]>element)
        {
            return binsearch(arr,low,mid-1,element);
        }
        if (arr[mid]<element)
        {
            return binsearch(arr,mid+1,high,element);
        }
    }
    return -1;

}
int main()
{
    int n;
    printf("Enter the number of elements in the list\n");
    scanf("%d",&n);
    int list[n],i;
    printf("Enter the elements in ascending order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    printf("What is to be searched\n");
    int searched;
    scanf("%d",&searched);
    int location=binsearch(list,0,n-1,searched);
    if (location==-1)
    {
        printf("Not found\n");
    }
    else
    {
        printf("found at loaction:%d",location+1);
    }
    return 0;
}
