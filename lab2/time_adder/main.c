#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int hours;
    int mins;
    int sec;
}time;
 time read()
 {
    time t;
    printf("Enter the hours minutes and seconds\n");
    scanf("%d",&t.hours);
    scanf("%d",&t.mins);
    scanf("%d",&t.sec);
    return t;
 }
 void display(time t)
 {
     printf("Hours:%d Mins:%d Seconds:%d\n",t.hours,t.mins,t.sec);
 }
time adder(time t1,time t2)
{
    time tt;
    tt.hours=t1.hours+t2.hours;
    tt.mins=t1.mins+t2.mins;
    tt.sec=t1.sec+t2.sec;
    if (tt.sec>=60)
    {
        tt.sec-=60;
        tt.mins++;
    }
    if (tt.mins>=60)
    {
        tt.mins-=60;
        tt.hours++;
    }
    return tt;
}
time diff(time t1,time t2)
{
    time t,err={-1,-1,-1};
    if (t1.sec<t2.sec)
    {
        if(t1.mins!=0)
        {
            t1.mins--;
            t1.sec+=60;
        }
        else if(t1.hours!=0)
        {
            t1.hours--;
            t1.mins+=59;
            t1.sec+=60;
        }
        else
        {
            printf("Subtraction cant be done\n");
            return err;
        }
    }
    t.sec=t1.sec-t2.sec;
    if(t1.mins<t2.mins)
    {
        if(t1.hours!=0)
        {
            t1.hours--;
            t1.mins+=60;
        }
        else
        {
            printf("Subtraction cant be done\n");
            return err;
        }
    }
    t.mins=t1.mins-t2.mins;
    if (t1.hours<t2.hours)
    {
        printf("Subtraction cant be done\n");
        return err;
    }
    else
        t.hours=t1.hours-t2.hours;
    return t;
}
int main()
{
    time t1,t2,td,ts;
    t1=read();
    t2=read();
    printf("Time 1:\n");
    display(t1);
    printf("Time 2:\n");
    display(t2);
    ts=adder(t1,t2);
    printf("On addition:\n");
    display(ts);
    printf("On Subtraction\n");
    td=diff(t1,t2);
    display(td);

}
