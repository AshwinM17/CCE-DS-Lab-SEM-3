#include <stdio.h>
#include <stdlib.h>
int rep_add(int m,int n);
int main()
{
    int x,y;
    printf("Enter the numbers to be multiplied:\n");
    scanf("%d %d",&x,&y);

    printf("product=%d",rep_add(x,y));
}
int rep_add(int m,int n)
{
    if(n==1)
    {
        return m;
    }
    return m+rep_add(m,n-1);
}
