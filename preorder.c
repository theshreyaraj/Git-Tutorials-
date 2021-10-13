#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(int data)
{
	struct node *node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}

void preorder(struct node *node)
{
	if(node==NULL)
		return;
	printf("%d->",node->data);
	preorder(node->left);
	preorder(node->right);
	if(node->data==NULL)
	{
		printf("\n");
	}
}

int main()
{
	struct node *root=newnode(4);
	root->left=newnode(1);
	root->right=newnode(6);
	root->left->left=newnode(5);
	root->left->right=newnode(2);

	printf("\nPreorder Traversal of the Binary Tree is\n");
	preorder(root);
	return 0;
}