#include<stdio.h>
#include<conio.h>

void main()
{
int fileno,blockno,frag[20],f[20],b[20],ff[20],bf[20],i,j,temp;
clrscr();
printf("\nenter no. of files:");
scanf("%d",&fileno);
printf("\nenter files:");
for(i=1;i<=fileno;i++)
scanf("%d",&f[i]);
printf("\nenter block no.");
scanf("%d",&blockno);
printf("\nenter blocks:");
for(i=1;i<=blockno;i++)
scanf("%d",&b[i]);

for(i=1;i<=fileno;i++)
{
for(j=1;j<=blockno;j++)
{
 if(bf[j]!=1)
 {
  temp=b[j]-f[i];
  if(temp>=0)
  {
   ff[i]=j;
   break;
  }
 }
}
 bf[ff[i]]=1;
 frag[i]=temp;
}
printf("\nFile No.\tFIle size\tBlock No\tBlock Size\tFragment");
for(i=1;i<=fileno;i++)
{
 printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
}
getch();
}
