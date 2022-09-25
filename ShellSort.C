#include<stdio.h>
#include<conio.h>
void shell(int*,int);
void shell(int* A,int n)
{
int i,h,j,x,k,a=0;
h=n/2;
while(h!=0)
{
for(i=h;i<=(n-1);i++)
{
	j=i;
	x=A[i];
	while(A[j-h]>x && j>(h-1))
	{
		A[j]=A[j-h];
		j=j-h;
	}
	A[j]=x;
}
h=h/2;
printf("\nSorted List after %d pass is:-\n",++a);
for(k=0;k<n;k++)
	printf("%d  ",A[k]);
}
printf("\nSoterd List is:-\n");
for(k=0;k<n;k++)
	printf("%d  ",A[k]);
}

void main()
{
int i,n,A[20];
clrscr();
printf("\nEnter how many numbers you eant to sort:-");
scanf("%d",& n);
for(i=0;i<n;i++)
{
printf("\nEnter %d number:-",i+1);
scanf("%d",&A[i]);
}
shell(A,n);
getch();
}