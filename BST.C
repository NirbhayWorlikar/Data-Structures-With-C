#include<stdio.h>
#include<conio.h>
struct bin_tree
{
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;
void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
	temp = (node *)malloc(sizeof(node));
	temp->left = temp->right = NULL;
	temp->data = val;
	*tree = temp;
	return;
    }
    if(val < (*tree)->data)
    {
	insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
	insert(&(*tree)->right, val);
    }
}
void print_preorder(node * tree)
{
    if (tree)
    {
	printf("%d\t",tree->data);
	print_preorder(tree->left);
	print_preorder(tree->right);
    }
}
void print_inorder(node * tree)
{
    if (tree)
    {
	print_inorder(tree->left);
	printf("%d\t",tree->data);
	print_inorder(tree->right);
    }
}
void print_postorder(node * tree)
{
    if (tree)
    {
	print_postorder(tree->left);
	print_postorder(tree->right);
	printf("%d\n",tree->data);
    }
}
void main()
{
    node *root;
    node *tmp;
    int choice,num;
    root = NULL;
    clrscr();
	while(1)
	{
	printf("\n --------MENU------------\n");
	printf("1\tInsert\n");
	printf("2\tPreorder\n");
	printf("3\tInorder\n");
	printf("4\tPostorder\n");
	printf("5\tExit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
		{
		case 1:
			printf("Enter your number:");
			scanf("%d",&num);
			insert(&root,num);
			break;;
		case 2:
			printf("Pre Order Display\n");
			print_preorder(root);
			break;;
		case 3:
			printf("In Order Display\n");
			print_inorder(root);
			break;;
		case 4:
			printf("Post Order Display\n");
			print_postorder(root);
			break;;
		case 5:
			exit(0);
		default:
			printf("\nSorry!!! Wrong Option!!!\n");
			break;
		}
	}
}