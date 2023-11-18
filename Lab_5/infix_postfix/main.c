#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <ctype.h>
#include <string.h>
void InfixtoPostfix(char infix[])
{
  int ilen=strlen(infix);
  char postfix[ilen];
  char cc;
  element ce;
  int iindex,pindex=0,i;

  for(iindex=0;iindex<ilen;iindex++)
  {
      cc=infix[iindex];
      if(isalnum(cc))
      {
          postfix[pindex++]=cc;
      }
      else if(cc=='(')
      {
          ce.key=cc;
          push(ce);
      }
      else if(cc==')')
      {
          while(!isempty()&&peek().key!='(')
          {
              postfix[pindex++]=pop().key;
          }
          if(isempty())
            {
                printf("Invalid");
                return;
            }
          else if (peek().key=='(')
                    pop();
      }
      else{
        while((!isempty())&& (precedence(peek().key)>=precedence(cc))) //till the time we get an operand with lower precedence at the stack top
              {
                postfix[pindex++]=pop().key;
              }
              ce.key=cc;
              push(ce);
      }
  }

  while(!isempty())
  {
      postfix[pindex++]=pop().key;
  }

  postfix[pindex]='\0';
    printf("Postfixed expression is:\n");
  printf("%s",postfix);

}

void main()
{
    char infix[50];
    printf("Enter the Expression\n");
    gets(infix);

    InfixtoPostfix(infix);

}
