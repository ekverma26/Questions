#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void show(int);
void nqueen(int,int);
int place(int,int);
int x[20],count=0;

void main()
{
  int n;
  clrscr();
  printf("\nenter no. of queens:");
  scanf("%d",&n);
  nqueen(1,n);
  getch();
}

void nqueen(int row,int n)
{
  int column;
  for(column=1;column<=n;column++)
  {
    if(place(row,column))
    {
      x[row]=column;
      if(row==n)
      show(n);
      else
      nqueen(row+1,n);
    }
  }
}

int place(int row, int column)
{
  int i;
  for(i=1;i<=row-1;i++)
  {
   if(x[i]==column)
   return 0;
   else
   if(abs(x[i]-column)==abs(i-row))
   return 0;
  }
  return 1;
}

void show(int n)
{
  int i,j;
  printf("\n\nSolution:%d\n\n",++count);

  for(i=1;i<=n;i++)
  printf("\t%d",i);
  for(i=1;i<=n;i++)
  {
   printf("\n\n%d",i);
   for(j=1;j<=n;j++)
   {
    if(x[i]==j)
    printf("\tQ");
    else
    printf("\t-");
   }
  }
}



