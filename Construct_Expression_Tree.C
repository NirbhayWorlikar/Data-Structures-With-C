/* C program to implement postfix expression tree and calculating its value */

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
#include<string.h>
struct tree
{
    char data;
    struct tree *left,*right;
};
int top=-1;
struct tree *stack[20];
struct tree *node;

void push(struct tree* node)
{
    stack[++top]=node;
}

struct tree * pop()
{
    return(stack[top--]);
}
void inorder(struct tree *node)
{
    if(node!=NULL)
    {
    inorder(node->left);
    printf("%c",node->data);
    inorder(node->right);
    }
}
int check(char ch)
{
if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
return 2;
else
return 1;
}
void operand(char b)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=b;
    node->left=NULL;
    node->right=NULL;
    push(node);
}
void operators(char a)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=a;
    node->right=pop();
    node->left=pop();
    push(node);
}
void main()
{
    int i,p,ans;
    char s[20];
    clrscr();
    printf("Enter the expression in postfix form \n");
    fflush(stdin);
    gets(s);
    for(i=0;s[i]!='\0';i++)
	{
	    p=check(s[i]);
	    if(p==1)
	    operand(s[i]);
	    else if(p==2)
	    operators(s[i]);
	}
    printf("\nThe inorder traversal of the tree is \n");
    inorder(stack[top]);
    getch();
}