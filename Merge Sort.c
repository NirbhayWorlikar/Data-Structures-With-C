#include<stdio.h>
#include<conio.h>
void merge(int [],int,int,int);
void mergesort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
	q=(p+r)/2;
	mergesort(a,p,q);
	mergesort(a,q+1,r);
	merge(a,p,q,r);
	}
}
void merge(int a[],int p,int q,int r)
{
	int temp[30],l,m,i,j;
	l=p;
	m=q+1;
	i=p;
	while((l<=q)&&(m<=r))
	{
		if(a[l]<=a[m])
		{
			temp[i]=a[l];
			l++;
		}
		else
		{
			temp[i]=a[m];
			m++;
		}
	i++;
	}
	if(l>q)
	{
		for(j=m;j<=r;j++)
		{
		temp[i]=a[j];
		i++;
		}
	}
	else
	{
		for(j=l;j<=q;j++)
		{
		temp[i]=a[j];
		i++;
		}
	}
	for(j=p;j<=r;j++)
		a[j]=temp[j];
}
void main()
{
	int a[100],n,i;
	clrscr();
	printf("\t\tMerge sort \n");
	printf("\nEnter the no of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf("\nSorted list:");
	for(i=0;i<n;++i)
		printf("%4d",a[i]);
	getch();
}
