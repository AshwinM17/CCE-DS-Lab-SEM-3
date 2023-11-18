#include <stdio.h>
#include <stdlib.h>
struct student
    {
        char name[50];
        int roll_no;
        char grade;
    };
typedef struct student stud;
stud reader()
{
    stud s;
    fflush(stdin);
    printf("Enter the name:-\n");
    gets(s.name);
    printf("Enter the roll no:-\n");
    scanf("%d",&s.roll_no);
    fflush(stdin);
    printf("Enter the grade:-\n");
    scanf("%c",&s.grade);
    return s;
}
 void display(stud arr[],int n)
 {
     int i;
     for(i=0;i<n;i++){
        printf("Name:");
        puts(arr[i].name);
        printf("roll_no:%d\nGrade:%c\n\n",arr[i].roll_no,arr[i].grade);
     }
 }

void sort(stud arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)  //using bubble sort
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j].roll_no>arr[j+1].roll_no)
            {
                stud buffer=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=buffer;
            }
        }

    }
}
int main()
{
    stud list[100];
    int n,i;
    printf("Numbers of students data to be added\n");
    scanf("%d",&n);
    fflush(stdin);
    for(i=0;i<n;i++)
        list[i]=reader();
    printf("The sorted student information is:\n");
    sort(list,n);
    display(list,n);

}

