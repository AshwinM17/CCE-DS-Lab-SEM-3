#include <stdio.h>
#include <stdlib.h>
int length_str(char arr[]);
void concatenate(char arr1[],char arr2[]);
void str_cmp(char arr1[],char arr2[]);
void insert(int location,char arr1[],char substr[]);
void delete_str(char str[],char substr[]);
int main()
{
    int choice;
    char contin='y';
    printf("What do you want to perform on strings?\n");

    while (contin=='y'){
            printf("Press 1 for length\n2 for concatenate\n3 for string compare\n4 for inserting a substring\n5 for deleting a substring\n");
        scanf("%d",&choice);
    fflush(stdin);
    char str1[100],str2[100];
    switch(choice)
    {
    case 1:
        {

            printf("Enter the string\n");
            gets(str1);
            printf("Length=%d\n",length_str(str1));
            printf("Continue?(y/n)\n");
            scanf("%c",&contin);
            break;
        }
    case 2:
        {
            printf("Enter the first string\n");
            gets(str1);
            printf("Enter the second string\n");
            gets(str2);
            concatenate(str1,str2);
            printf("Continue?(y/n)\n");
            scanf("%c",&contin);
            break;
        }
    case 3:
        {
            printf("Enter the first string\n");
            gets(str1);
            printf("Enter the second string\n");
            gets(str2);
            str_cmp(str1,str2);
            printf("Continue?(y/n)\n");
            scanf("%c",&contin);
            break;
        }
    case 4:
        {
            printf("Enter the main string\n");
            gets(str1);
            printf("Enter the string to be inserted\n");
            gets(str2);
            int location;
            printf("Enter the location to which the substing has to be added\n");
            scanf("%d",&location);
            fflush(stdin);
            insert(location,str1,str2);
            printf("Continue?(y/n)\n");
            scanf("%c",&contin);
            break;
        }
    case 5:
        {
            printf("Enter the main string\n");
            gets(str1);
            printf("Enter the string to be deleted\n");
            gets(str2);
            delete_str(str1,str2);
            printf("Continue?(y/n)\n");
            scanf("%c",&contin);;
            break;
        }
    }
    }
    return 0;
}
int length_str(char arr[])
{
    int counter=0;
    for(;arr[counter]!='\0';counter++);
    return counter;
}
void concatenate(char arr1[],char arr2[])
{
    int len1,len2,i;
    len1=length_str(arr1);
    len2=length_str(arr2);
    char concat_str[len1+len2+1];
    for (i=0;i<len1;i++)
        concat_str[i]=arr1[i];
    for(i=0;i<=len2;i++)
        concat_str[i+len1]=arr2[i];
    printf("Concatenated string:\n");
    puts(concat_str);

}
void str_cmp(char arr1[],char arr2[])
{
    int i,len1,len2,result,check=0;
    len1=length_str(arr1);
    len2=length_str(arr2);
    int max;
    if (len1>len2)
        max=len1;
    else if(len1<len2)
        max=len2;
    else
    {
        max=len1;

    }
    for (i=0;i<max;i++)
    {
        if (arr1[i]!=arr2[i])
        {
            if (arr1[i]>arr2[i])
            {
                printf("On Comparing,1st string is higher\n");
                check=1;
                break;
            }
            else
            {
                printf("On Comparing,2nd string is higher\n");
                check=1;
                break;
            }

        }
    }
    if (check==0)
        printf("Strings are same\n");
}
void insert(int location,char arr1[],char substr[])
{
    int len1,len2,i,j;
    int loc_index=location-1;
    len1=length_str(arr1);
    len2=length_str(substr);
    for(i=len1;i>=loc_index;i--)
        arr1[i+len2]=arr1[i];
    for(i=loc_index,j=0;i<(loc_index+len2);i++)
        arr1[i]=substr[j++];
    puts(arr1);

}
void delete_str(char str[],char substr[])
{
    int len1=length_str(str);
    int len2=length_str(substr);
    int i,j,k,flag=1;
    for(i=0;i<=len1-len2;i++)
    {
        if(str[i]==substr[0])
            flag=1;
        for (j=i,k=0;k<len2;j++,k++)
        {
            if (str[j]!=substr[k])
            {
                flag=0;
                break;
            }
        }
        if (flag==1)
        {
            for(j=i+len2;j<=len1;j++)
            {
                str[j-len2]=str[j];
            }
            len1-=len2;
            i--;
        }

    }
    puts(str);
}


