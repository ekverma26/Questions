#include<stdio.h>
#include<conio.h>
void main()
{ clrscr();
  float at[10],dt[10];
  int i,j,k,n;
  printf("Enter number of trains");
  scanf("%d",&n);
  printf("\nEnter arrival and departure time of trains");
  printf("\n\tARRIVAL \t DEPARTURE");
  for(i=1;i<=n;i++)
  {
   printf("\n Train %d",i);
   scanf("%f", &at[i]);
   scanf("%f", &dt[i]);
  }
  for(i=1;i<=n;i++)
  {
   for(j=i+1; j<=n;j++)
   {
    if(dt[i]>dt[j])
    {
     int t=dt[i];
     dt[i]=dt[j];
     dt[j]=t;
     }
     }
     }
  i=1;j=1;
  int max=0,p=0;
  while(i<=n && j<=n)
  {
    if(at[i]<=dt[j])
    {
     i++;
     p++;
     if(max<p)
	max=p;
    }
    else
    {
     j++;
     p--;
    }
  }
    while(i<=n)
    {
     i++;
     p++;
     if(max<p)
	p++;
    }
    while(j<=n)
    {
     j++;
     p--;
    }

  printf("\n No of platforms needed:%d",max);
getch();
}
