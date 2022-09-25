#include<stdio.h>
#include<conio.h>
#include<process.h>
void enqueue();
void dequeue();
void display();
int queue[10],front=-1,rear=-1,n;
void main()
{
	int choice;
	clrscr();
	printf("Enter the capasity of queue: ");
	scanf("%d",&n);
	while(1)
	{
		printf("\n----Queue Operations----\n");
		printf("1.   Enqueue\n");
		printf("2.   Dequeue\n");
		printf("3.   Display\n");
		printf("4.   Exit\n");
		printf("\tEnter your choice: ");
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
			default:printf("\nYou have entered wrong choice.\n");
		}
	}
}
void enqueue()
{
	if((rear+1)%n==front)
	{
		printf("\nCircular QUEUE OVERFLOW.\n");
		return;
	}
	if(front==-1 && rear==-1)
		front=0;
	rear=(rear+1)%n;
	printf("Enter value to be inserted: ");
	scanf("%d",&queue[rear]);
}
void dequeue()
{
	if(front==-1)
	{
		printf("\nQUEUE UNDERFLOW.\n");
		return;
	}
	printf("\n %d is deleted from queue.\n",queue[front]);
	if(front==rear)
		front=rear=-1;
	else
		front=(front+1)%n;
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("\nQueue is empty.\n");
		return;
	}
	if(front<=rear)
	{
	for(i=front;i<=rear;i++)
		printf("%d\t",queue[i]);
	}
	else
	{
	for(i=front;i<n;i++)
		printf("%d\t",queue[i]);
	for(i=0;i<=rear;i++)
		printf("%d\t",queue[i]);
	}
}