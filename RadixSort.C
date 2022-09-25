#include<stdio.h>
#include<conio.h>
# define MAX 20
void bucket_sort(int [],int);
void main()
{
int a[MAX],n,i;
clrscr();
printf("\nEnter the number of elements:");
scanf("%d",&n);
for(i=0;i<n;i++)
	{
	printf("Enter element a[%d]:",i+1);
	scanf("%d",&a[i]);
	}
clrscr();
printf("\nInput array is:\n");
for(i=0;i<n;i++)
	{
	printf("\t%d",a[i]);
	}
bucket_sort(a,n);
printf("\nSorted Array is:\n");
for(i=0;i<n;i++)
	{
	printf("\t%d",a[i]);
	}
getch();
}
void bucket_sort(int a[], int n)
{
int bucket[MAX][10],digit,bucket_count[10],i,large=a[0],nop=0,div=1,pass,j,k;
for(i=1;i<n;i++)
	{
	if(large<a[i])
		{
		large=a[i];
		}
	}
while(large>0)
	{
	nop++;
	large/=10;
	}
for(pass=0;pass<nop;pass++)
	{
	for(i=0;i<10;i++)
		{
		bucket_count[i]=0;
		}
	for(i=0;i<n;i++)
		{
		digit=(a[i]/div)%10;
		bucket[digit][bucket_count[digit]]=a[i];
		bucket_count[digit]+=1;
		}
	k=0;
	for(i=0;i<10;i++)
		{
		for(j=0;j<bucket_count[i];j++)
			{
			a[k++]=bucket[i][j];
			}
		}
	div=div*10;
	}
}