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
void insert_beg();
void del_beg();
void print();
void main()
{
	int choice,key;
	do
	{
	clrscr();
	printf("\n------------MENU------------\n");
	printf("1\tCreate\n");
	printf("2\tInsert at Beginning\n");
	printf("3\tDelete at beginning\n");
	printf("4\tPrint\n");
	printf("5\tExit\n");
	printf("\n----------------------------\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
		{
		case 1:
			create();
			break;
		case 2:
			insert_beg();
			break;
		case 3:
			del_beg();
			break;
		case 4:
			print();
			break;
		case 5:
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
void insert_beg()
{
	struct node *ptr,*temp=start;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr!=NULL)
	{
		printf("\nEnter value to be inserted:");
		scanf("%d",&ptr->data);
		if(temp==NULL)
			{
			start=ptr;
			start->next=NULL;
			}
		else
			{
			ptr->next=start;
			start=ptr;
			}
	}
printf("\nUpdated list is:\n");
print();
}
void del_beg()
{
struct node *temp=start;
if(temp==NULL)
	{
	printf("\nLinked list is empty.");
	printf("\nEnter any key to return to main menu.");
	getch();
	}
else
	{
	printf("\nDeleted value from link list is:%d.",start->data);
	start=start->next;
	free(temp);
	printf("\nUpdated list is:\n");
	print();
	}
}