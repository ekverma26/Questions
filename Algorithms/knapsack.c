#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int max(int a,int b)
{
 return (a>b?a:b);
}

int ks(int w,int wt[],int p[],int n)
{
 if(n==0||w==0)
 return 0;

 if(wt[n-1]>w)
 return ks(w,wt,p,n-1);
 else
 return max(p[n-1]+ks(w-wt[n-1],wt,p,n-1),ks(w,wt,p,n-1));
}

void main()
{
clrscr();
int r,i,n,p[10],wt[10],w,x;
printf("\nenter capacity of bag:");
scanf("%d",&w);
printf("\nenter no. of objects:");
scanf("%d",&x);
printf("\nenter profits:");
for(i=0;i<x;i++)
scanf("%d",&p[i]);

printf("\nenter weights:");
for(i=0;i<x;i++)
scanf("%d",&wt[i]);

n=x;
printf("\n%d",n);

r=ks(w,wt,p,n);
printf("\nmax profit is:%d",r);

getch();
}
