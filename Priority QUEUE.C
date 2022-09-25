#include<stdio.h>
#include<conio.h>
#define MAX 20

int q[MAX],f=-1,r=-1;

void insertion(int a[]);
void insertq(int e);
int deleteq();
void main()
{
  int n,c,val,i;
  clrscr();
  top:
  printf("\n1 : insert\n");
  printf("2 : delete\n");
  printf("3 : display\n");
  printf("0 : exit\n");
  scanf("%d",&c);
  switch(c)
  {
  case 0: 
goto end;
  case 1: 
printf("Enter element\n");
	scanf("%d",&n);
insertq(n);
	break;
  case 2: 
val=deleteq();
	printf("Element deleted is\t%d\n",val);
	break;
  case 3:
	printf("\nSorted Queue is \n");
	for(i=f;i<=r;i++)
	printf("\t%d",q[i]);
	break;
  }
  goto top;
  end:
}
void insertion(int a[])
{
	int temp,j,k,i;
	for(k=f+1;k<=r;k++)
	{
		temp=a[k];
		j=k-1;
		while(temp<a[j] && j>=f)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
void insertq(int e)
{
	if(r==MAX-1)
	printf("Overflow\n");
	else
	q[++r]=e;
	if(f==-1)
	f++;
	insertion(q);
}
int deleteq()
{
	if(f==-1||f>r)
	{
	 printf("Underflow\n");
	 return -1;
	}
	else
	return q[f++];
}