#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
clrscr();
char name[10][10],tname[10][10],temp[10],n,i,j;
printf("\nenter no. of names:");
scanf("%d",&n);
printf("\nenter names:");
for(i=0;i<n;i++)
{
scanf("%s",&name[i]);
strcpy(tname[i],name[i]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
  {
if(strcmp(name[i],name[j])>0)
    {
strcpy(temp,name[i]);
strcpy(name[i],name[j]);
strcpy(name[j],temp);
    }
  }
}
printf("\nSorted names of students:");
for(i=0;i<n;i++)
{
printf("\n%s",name[i]);
}
getch();
}
