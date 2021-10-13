#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

int isBSTUtil(struct node *node,int min,int max);

int isBST(struct node *node)
{
	return(isBSTUtil(node,INT_MIN,INT_MAX));
}

int isBSTUtil(struct node *node,int min,int max)
{
	if(node == NULL)
		return 1;
	if(node->data < min || node->data > max)
		return 0;
	return
		isBSTUtil(node->left,min,node->data-1)&&
		isBSTUtil(node->right,node->data+1,max);
}

struct node *newnode(int data)
{
	struct node *node=(struct node *)malloc(sizeof(struct node));
	
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	
	return(node);
}

int main()
{
	struct node *root=newnode(5);
	root->left=newnode(3);
	root->right=newnode(6);
	root->left->left=newnode(1);
	root->left->right=newnode(4);
	
	if(isBST(root))
		printf("BINARY TREE IS BINARY SEARCH TREE\n");
	else
		printf("BINARY TREE IS NOT BINARY SEARCH TREE\n");
	getchar();
	return 0;
}