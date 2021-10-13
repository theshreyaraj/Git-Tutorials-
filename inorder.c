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

void inorder(struct node *node)
{
	if(node==NULL)
		return;
	inorder(node->left);
	printf("%d->",node->data);
	inorder(node->right);
	
}

int main()
{
	struct node *root=newnode(4);
	root->left=newnode(1);
	root->right=newnode(6);
	root->left->left=newnode(5);
	root->left->right=newnode(2);

	printf("\nInorder Traversal of the Binary Tree is\n");
	inorder(root);
	return 0;
}