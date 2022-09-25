#include<stdio.h>
#include<conio.h>
# define MAX 10
int a[MAX],n;
void indexss();
void main()
{
	int i;
	clrscr();
	printf("Enter number of elements in array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
		printf("Enter A[%d]: ",i+1);
		scanf("%d",&a[i]);
		}
	indexss();
	getch();
}
void indexss()
{
	int i,j,b,key,index[MAX/2][2];
	printf("Enter size of index block: ");
	scanf("%d",&b);
	printf("Enter number to be searched: ");
	scanf("%d",&key);
	printf("\nIndex Table is shown below:\n");
	printf("\tIndex Position\tIndex Key");
	for(i=0;i<n/b;i++)
		{
		index[i][0]=i*b;
		index[i][1]=a[i*b];
		printf("\n\t  %d\t\t  %d",index[i][0]+1,index[i][1]);
		}
	for(i=0;i<n/b;i++)
		{
		if(index[i][1]==key)
			{
			printf("\n%d is found at position %d.\n",key,index[i][0]+1);
			return;
			}
		else if(index[i][1]>key)
			{
			break;
			}
		}
	if(i==0)
	     {
	     printf("\n%d element is may present between start of list i.e. %d and %d index position.\n",key,1,index[i][0]+1);
	     }
	else if(i<n/b)
		{
		printf("\n%d element is may present between %d and %d index position.\n",key,index[i-1][0]+1,index[i][0]+1);
		}
	else
		{
		printf("\n%d element is may present between %d and end of list i.e. %d index position.\n",key,index[i-1][0]+1,n);
		}
	for(j=index[i-1][0];j<index[i][0] && j<n;j++)
		{
		if(a[j]==key)
			{
			printf("\n%d is found at position %d.\n",key,j+1);
			return;
			}
		}
	printf("\n%d is not present in the list.\n",key);
}

