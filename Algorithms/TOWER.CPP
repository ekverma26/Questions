#include<stdio.h>
#include<conio.h>
tower(int,char,char,char);
//char beg,end,aux;
//int n;
void main()
{
clrscr();
int x;
printf("\nenter no. of stands:");
scanf("%d",&x);
tower(x,'A','B','C');
getch();
}
tower(int n,char beg,char aux,char end)
{
    if(n==0)
    {
      return 0;
    }
    else
    {
      tower(n-1,beg,end,aux);
      printf("\n%c -> %c",beg,end);
      tower(n-1,aux,beg,end);
    }
}
