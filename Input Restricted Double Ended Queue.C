/*Double Ended Queue*/
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *start=NULL;
void create();
void Insert_front();
void Delete_first();
void Delete_last();
void display();
void main()
{
	int ch;
	clrscr();
	create();
	do
	{
		printf("\nEnter choice:\t 1.insert front \t 2.delete front \t 3.delete end \t 4.Display \t 5.Exit \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				Insert_front();
				break;
			case 2:
				Delete_first();
				break;
			case 3:
				Delete_last();
				break;
			case 4:
				display();
				break;
		}
	}while(ch!=5);
}

void create()
{
	int num;
	struct node *nn,*p;
	printf("Enter -1 to end \tEnter data:");
	scanf("%d",&num);
	while(num!=-1)
	{
		nn=(struct node*)malloc(sizeof(struct node));
		nn->data=num;
		nn->left=nn->right=NULL;
		if(start==NULL)
			start=nn;
		else
		{
			p=start;
			while(p->right!=NULL)
				p=p->right;
			p->right=nn;
			nn->left=p;
		}
		printf("Enter data:");
		scanf("%d",&num);
	}
}

void Insert_front()
{
	int num;
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&num);
	nn->data=num;
	nn->left=NULL;
	nn->right=start;
	start->left=nn;
	start=nn;
}

void Delete_first()
{
	struct node *p;
	if(start==NULL)
		printf("Empty linked list:");
	else
	{
		p=start;
		start=start->right;
		start->left=NULL;
		printf("Element deleted is %d",p->data);
		free(p);
	}
}

void Delete_last()
{
	struct node *p,*prev;
	if(start==NULL)
		printf("Empty Linked list");
	else
	{
		p=start;
		while(p->right!=NULL)
		{
			prev=p;
			p=p->right;
		}
		prev->right=NULL;
		printf("Element deleted is %d",p->data);
		free(p);
	}
}

void display()
{
	struct node *p;
	if(start==NULL)
		printf("Empty Linked List");
	else
	{
		p=start;
		printf("The Linked list is:");
		while(p!=NULL)
		{
			printf("%d\t",p->data);
			p=p->right;
		}
	}
}