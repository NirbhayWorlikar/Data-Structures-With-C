// Binary Tree

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};
typedef struct node Node;

void preorder(Node *);
void inorder(Node *);
void postorder(Node *);
void create(Node *p);
int is_lchild(Node *p);
int is_rchild(Node *p);

Node *r;



void main()
{
	clrscr();
	printf("Creation of Binary Tree\n");
	r=(Node *)malloc(sizeof(Node));
	printf("Enter data\n");
	scanf("%d",&r->data);
	create(r);
	printf("\nPreorder Traversal is\n");
	preorder(r);
	printf("\nInorder Traversal is\n");
	inorder(r);
	printf("\nPostorder Traversal is\n");
	postorder(r);
	getch();
}

void create(Node *p)
{
	Node *q;
	if(is_lchild(p))
	{
		q=(Node *)malloc(sizeof(Node));
		printf("Enter data\n");
		scanf("%d",&q->data);
		p->left=q;
		create(q);
	}
	else
	{
		p->left=NULL;
	}
	if(is_rchild(p))
	{
		q=(Node *)malloc(sizeof(Node));
		printf("Enter data\n");
		scanf("%d",&q->data);
		p->right=q;
		create(q);
	}
	else
	{
		p->right=NULL;
	}
}


int is_lchild(Node *p)
{
	  int ch;
	  printf("Do u wish to add Left child of %d (1/0)",p->data);
	  scanf("%d",&ch);
	  if(ch==1)
		return 1;
	  else
		return 0;
}

int is_rchild(Node *p)
{
	  int ch;
	  printf("Do u wish to add Right child of %d (1/0)",p->data);
	  scanf("%d",&ch);
	  if(ch==1)
		return 1;
	  else
		return 0;
}



void inorder(Node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d ",p->data);
		inorder(p->right);
	}
}

void preorder(Node *p)
{
	if(p!=NULL)
	{
		printf("%d ",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void postorder(Node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ",p->data);
	}
}

/*
Output

Creation of Binary Tree
Enter data
10
Do u wish to add Left child of 10 (1/0)1
Enter data
20
Do u wish to add Left child of 20 (1/0)0
Do u wish to add Right child of 20 (1/0)0
Do u wish to add Right child of 10 (1/0)1
Enter data
30
Do u wish to add Left child of 30 (1/0)0
Do u wish to add Right child of 30 (1/0)0

Preorder Traversal is
10 20 30
Inorder Traversal is
20 10 30
Postorder Traversal is
20 30 10
*/


