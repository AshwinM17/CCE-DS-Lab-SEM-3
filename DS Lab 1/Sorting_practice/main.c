#include <stdio.h>
#include <stdlib.h>
int selection_sort(int list[],int N);
int bubble_sort(int list[],int N);
int insertion_sort(int list[],int N);
int main()
{
    int N,i,sorttype;
    printf("Enter the number of elements\n");
    scanf("%d",&N);
    int list[N];
    printf("Enter the numbers\n");
    for(i=0;i<N;i++)
        scanf("%d",&list[i]);
    printf("Sort by which method?\n1 for bubblesort\n2 for selection sort\n3 for insertion sort\n");
    scanf("%d",&sorttype);
    switch(sorttype)
    {
        case 1:
        {
           bubble_sort(list,N);
           break;
        }
        case 2:
        {
            selection_sort(list,N);
            break;

        }
        case 3:
        {
            insertion_sort(list,N);
            break;
        }
    }
    for(i=0;i<N;i++)
       printf("%d ",list[i]);
    return 0;
}

int bubble_sort(int list[],int N)
{
    int i,j;
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
    printf("Done by Bubble sort.\n");
}
int selection_sort(int list[],int N)
{
    int i,j;
    int pos,value;
    for(i=0;i<N-1;i++)
    {
        value=list[i];
        pos=i;
        for(j=i+1;j<N;j++)
        {
            if (list[j]<value)
            {
                value=list[j];
                pos=j;
            }
        }
        list[pos]=list[i];
        list[i]=value;
    }
    printf("Done by Selection sort.\n");
}

int insertion_sort(int list[],int N)
{
    int i,j,buffer;
    for(i=1;i<N;i++)
    {
        int ei=list[i];
        int prev=i-1;
        for(;prev>=0 && list[prev]>ei;prev--)
            list[prev+1]=list[prev];
        list[prev+1]=ei;
    }
    printf("Done by Insertion sort.\n");

}
