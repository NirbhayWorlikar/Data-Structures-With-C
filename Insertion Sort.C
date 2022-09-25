#include<stdio.h>
#include<conio.h>
void insertion(int*,int); 
void main()
{
int i,n,A[50];
clrscr();
printf("\nEnter how many numbers you want to sort:-");
scanf("%d",& n);
for(i=1;i<=n;i++)
	{
	printf("\nEnter %d number:-",i);
	scanf("%d",& A[i]);
	}
insertion(A,n);
getch();
}

void insertion(int* A,int n)  
{
int k,temp,ptr,j;
A[0]=-1000000;
for(k=2;k<=n;k++)
	{
	temp=A[k];
	ptr=k-1;
	while(temp<A[ptr])
		{
		A[ptr+1]=A[ptr];
		ptr--;
		}
	A[ptr+1]=temp;
	printf("\nSorted List after %d pass:-\n",k-1);
		for(j=1;j<=n;j++)
			printf("%d   ",A[j]);
	}
printf("\nSorted List is:-\n");
for(j=1;j<=n;j++)
	printf("%d   ",A[j]);
}
