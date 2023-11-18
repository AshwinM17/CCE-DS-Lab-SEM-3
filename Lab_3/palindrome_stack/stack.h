#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdbool.h>
#define Max_size 100
typedef struct
{
    // changes to be made here for datatype
    char key;
}element;
element stack[Max_size];
element pop();
bool isfull();
bool isempty();
void push(element e);
void display();
#endif // STACK_H_INCLUDED
