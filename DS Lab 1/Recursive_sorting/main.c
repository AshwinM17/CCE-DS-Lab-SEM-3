#include <stdio.h>
#include <stdlib.h>
void rec_sort(int arr[],int i,int j,int len)
{
    int buffer;
    if(i<len-1)
        {
            if(j<len)
            {


                if(arr[i]>arr[j])
                {
                    buffer=arr[j];
                    arr[j]=arr[i];
                    arr[i]=buffer;
                }
                rec_sort(arr,i,j+1,len);
            }
            rec_sort(arr,i+1,i+2,len);
        }
}
int main()
{
    int n;
    printf("Enter the size of the list\n");
    scanf("%d",&n);
    int list[n],i;
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    rec_sort(list,0,0,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",list[i]);
    }
}
