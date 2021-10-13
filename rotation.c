#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

int max(int a,int b);

int height(struct Node *N)
{
	if(N==NULL)
		return 0;
	return N->height;
}

int max(int a,int b)
{
	return (a>b)?a:b;
}

struct Node *newnode(int key)
{
	struct Node *node=(struct Node *)malloc(sizeof(struct Node));
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return(node);
}

struct Node *rightrotate(struct Node *y)
{
	struct Node *x=y->left;
	struct Node *T2=x->right;
	
	x->right=y;
	y->left=T2;
	
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
}

struct Node *leftrotate(struct Node *x)
{
	struct Node *y=x->right;
	struct Node *T2=y->right;
	
	y->left=x;
	x->right=T2;
	
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	
	return y;
}

int getBalance(struct Node *N)
{
	if(N==NULL)
		return 0;
	return height(N->left)-height(N->right);
}

struct Node *insertnode(struct Node *node,int key)
{
	if(node==NULL)
		return(newnode(key));
		
	if(key < node->key)
		node->left=insertnode(node->left,key);
	else if(key > node->key)
		node->right=insertnode(node->right,key);
	else
		return node;
		
	node->height=1+max(height(node->left),height(node->right));
	
	int balance=getBalance(node);
	if(balance<1&&key<node->right->key)
		return rightrotate(node);
	
	if(balance<-1&&key>node->right->key)
		return leftrotate(node);
		
	if(balance>1&&key>node->left->key)
	{
		node->left=leftrotate(node->left);
		return rightrotate(node);
	}
	
	if(balance<-1&&key<node->right->key)
	{
		node->right=rightrotate(node->right);
		return leftrotate(node);
	}
	return node;
}

struct Node *minvaluenode(struct Node *node)
{
	struct Node *current=node;
	while(current->left != NULL)
		current=current->left;
	return current;
}

struct Node *deletenode(struct Node *root,int key)
{
	if(root==NULL)
		return root;
		
	if(key<root->key)
		root->left=deletenode(root->left,key);
		
	else if(key<root->key)
		root->right=deletenode(root->right,key);
		
	else
	{
		if((root->left==NULL)||(root->right==NULL))
		{
			struct Node *temp=root->left ? root->left:root->right;
			
			if(temp==NULL)
			{
				temp=root;
				root=NULL;
			}
			else
			*root=*temp;
			free(temp);
		}
		else
		{
			struct Node *temp=minvaluenode(root->right);
			
			root->key=temp->key;
			
			root->right=deletenode(root->right,temp->key);
		}
	}
	
	if(root==NULL)
		return root;
		
	root->height=1+max(height(root->left),height(root->right));
	
	int balance=getBalance(root);
	
	if(balance>1 && getBalance(root->left)>=0)
		return rightrotate(root);
		
	if(balance >1 &&getBalance(root->left)<0)
	{
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	
	if(balance <- 1 && getBalance(root->right)<=0)
		return leftrotate(root);
	
	if(balance < -1 && getBalance(root->right)>0)
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
}

void printpreorder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d\t",root->key);
		printpreorder(root->left);
		printpreorder(root->right);
	}
}

int main()
{
	struct Node *root=NULL;
	root=insertnode(root,2);
	root=insertnode(root,1);
	root=insertnode(root,7);
	root=insertnode(root,4);
	root=insertnode(root,5);
	root=insertnode(root,3);
	root=insertnode(root,8);
	
	printpreorder(root);
	
	root=deletenode(root,3);
	
	printf("\nAfter Deletion:\n");
	printpreorder(root);
	
	return 0;
}