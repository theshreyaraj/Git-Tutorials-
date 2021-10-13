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

void postorder(struct node *node)
{
	if(node==NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	printf("%d->",node->data);
}

int main()
{
	struct node *root=newnode(4);
	root->left=newnode(1);
	root->right=newnode(6);
	root->left->left=newnode(5);
	root->left->right=newnode(2);

	printf("\nPostorder Traversal of the Binary Tree is\n");
	postorder(root);
	return 0;
}