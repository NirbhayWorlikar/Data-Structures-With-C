#include<stdio.h>
#include<conio.h>
#include<process.h>
struct cqueue
{
	int data;
	struct cqueue *next;
};
struct cqueue *front=NULL;
struct cqueue *rear=NULL;
void enqueue()
{
	struct cqueue *ptr;
	ptr=(struct cqueue *)malloc(sizeof(struct cqueue));
	if(ptr!=NULL)
		{
		printf("\nEnter the value to be pushed in queue:");
		scanf("%d",&ptr->data);
		if(rear==NULL)
			{
			front=rear=ptr;
			}
		else
			{
			rear->next=ptr;
			rear=ptr;
			}
		rear->next=front;
		}
	printf("\Front=%u\tRear=%u\tptr=%u",front,rear,ptr);
}
void dequeue()
{
	struct cqueue *temp=front;
	if(temp==NULL)
		printf("\nQueue Underflow\n");
	else
		{
		printf("\nValue popped of queue is:%d.\n",front->data);
		if(front==rear)
			front=rear=NULL;
		else
		{
		front=front->next;
		rear->next=front;
		}
		free(temp);
		}
	printf("\Front=%u\tRear=%u\ttemp=%u",front,rear,temp);
}
void display()
{
	struct cqueue *temp=front;
	if(temp==NULL)
		printf("\nQueue Underflow\n");
	else
	{
	while(temp!=rear)
		{
		printf("%d\t",temp->data);
		temp=temp->next;
		}
		printf("%d",temp->data);
	}
	printf("\Front=%u\tRear=%u\ttemp=%u",front,rear,temp);
}
void main()
{
	int choice;
	clrscr();
	do
	{
	printf("\n------MENU---------\n");
	printf("1\tEnqueue\n");
	printf("2\tDequeue\n");
	printf("3\tDisplay\n");
	printf("4\tExit\n");
	printf("\n-------------------\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
		{
		case 1: enqueue();
			break;
		case 2: dequeue();
			break;
		case 3: display();
			break;
		case 4: exit(0);
		default:printf("Sorry!!! You have entered Wrong choice.\n");
			break;
		}
	}while(1);
}