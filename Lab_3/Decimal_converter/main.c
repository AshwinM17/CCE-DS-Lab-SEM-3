#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main()
{
    int num,base;
    printf("Enter the number:\n");
    scanf("%d",&num);
    printf("Enter the base:\n");
    scanf("%d",&base);
    element e;
    int numcpy=num;
    while(num>0)
    {
        e.key=(num%base);
        push(e);
        num/=base;
    }
    printf("%d in base %d is\n",numcpy,base);
    display();
    return 0;
}
