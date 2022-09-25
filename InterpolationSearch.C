#include<stdio.h>
#include<conio.h>
void main()
{
void inter(int *,int,int);
int A[20],i,n,key;
clrscr();
printf("\nEnter how many numbers you want to insert into list(In acsending order):-");
scanf("%d",& n);
for(i=0;i<n;i++)
	{
	printf("\nEnter %d number:-",i+1);
	scanf("%d",&A[i]);
	}
printf("\nEnter number to be serarch in given list:-");
scanf("%d",& key);
inter(A,n,key);
getch();
}

void inter(int* A,int n,int key)
{
int low,mid,high,loc,i=0;
low=0;
high=n-1;
mid=low+(int)((high-low)*(float)(key-A[low])/(float)(A[high]-A[low]));
if(A[mid]==key)
{
	printf("\nFor %d pass:-\n",++i);
	printf("A[Low]=%d\tA[Mid]=%d\tA[High]=%d",A[low],A[mid],A[high]);
}
while(low<=high && A[mid]!=key)
	{
	printf("\nFor %d pass:-\n",++i);
	printf("A[Low]=%d\tA[Mid]=%d\tA[High]=%d",A[low],A[mid],A[high]);
	if(key<A[mid])
	      high=mid-1;
	else
	      low=mid+1;
	mid=low+(int)((high-low)*(float)(key-A[low])/(float)(A[high]-A[low]));
	}
if(A[mid]==key)
	{
	printf("\nFor %d pass:-\n",++i);
	printf("A[Low]=%d\tA[Mid]=%d\tA[High]=%d",A[low],A[mid],A[high]);
	printf("\nSearch is successful & element found at position %d\n",mid+1);
	}
else
	{
	printf("\nFor %d pass:-\n",++i);
	printf("A[Low]=%d\tA[Mid]=%d\tA[High]=%d",A[low],A[mid],A[high]);
	printf("\nSearch is Unsuccessful\n");
	}
}