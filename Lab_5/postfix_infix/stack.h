#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdbool.h>
#define Max_size 100
//header file
typedef struct
{
    // changes to be made here for datatype
    char key[100];

}element;
bool isempty();
bool isfull();
void push(element e);
element pop();
element peek();
bool isoperator(char cc);
element stack[Max_size];
#endif
