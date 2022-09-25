#include<stdio.h>
#include<conio.h>
#include<process.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *start1=NULL;
void create();
void reverse();
void print();
void main()
{
	int choice,key;
	do
	{
	clrscr();
	printf("\n------------MENU------------\n");
	printf("1\tCreate\n");
	printf("2\tReverse\n");
	printf("3\tDisplay\n");
	printf("4\tExit\n");
	printf("\n----------------------------\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
		{
		case 1:
			create();
			break;
		case 2:
			reverse();
			break;
		case 3:
			print();
			break;
		case 4:
			printf("\nWe are exiting...");
			printf("\nEnter any key to exit...");
			getch();
			exit(0);
		default:
			printf("Sorry!!!You have entered a wrong choice.\n");
			printf("\nEnter any key to return to main menu.");
			getch();
			break;
		}
	}while(1);
}
void print()
{
struct node *temp=start;
if(temp==NULL)
	printf("\nList is empty.");
else
	{
	printf("\n");
	while(temp!=NULL)
		{
		printf("%d\t",temp->data);
		temp=temp->next;
		}
	}
printf("\nEnter any key to return to main menu.");
getch();
}
void create()
{
struct node *ptr,*temp;
int val;
start=NULL;
printf("\nTo stop creation of linked list enter -1.");
printf("\nEnter value:");
scanf("%d",&val);
while(val!=-1)
	{
	ptr=(struct node*)malloc(sizeof(struct node));
	temp=start;
	if(ptr!=NULL)
		{
		ptr->data=val;
		if(temp==NULL)
			{
			start=ptr;
			start->next=ptr->next=NULL;
			}
		else
			{
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=ptr;
			ptr->next=NULL;
			}
		}
	printf("Enter value:");
	scanf("%d",&val);
	}
printf("\nCreated List is:\n");
print();
}
void reverse()
{
struct node *p, *q;
if(start==NULL)
	printf("\nLinked List is empty.");
else
	{
	p=start->next;
	q=p->next;
	start->next=NULL;
	while(p!=NULL)
		{
		p->next=start;
		start=p;
		p=q;
		q=q->next;
		}
	}
printf("\nThe reversed list is:\n");
print();
}