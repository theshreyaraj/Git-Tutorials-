#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *tree;
void create_tree(struct node *);
struct node *insertelement(struct node *,int);
void preorder(struct node *);
void postorder(struct node *);
void inorder(struct node *);
struct node *smallestelement(struct node *);
struct node *largestelement(struct node *);
struct node *deleteelement(struct node *,int);
struct node *mirrorimage(struct node *);
int total_nodes(struct node *);
int total_external_nodes(struct node *);
int total_internal_nodes(struct node *);
int height(struct node *);
struct node *deletetree(struct node *);

int main()
{
	int option,val;
	struct node *ptr;
	create_tree(tree);
	do
	{
		printf("\n*************MAIN MENU****************\n");
		printf("1.Insert Element\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Smallest Element\n6.Largest element\n7.Delete Element\n8.Total number of nodes\n9.Total number of external nodes\n10.Total number of internal nodes\n11.Height of tree\n12.Mirror Image of tree\n13.Delete Tree\n14.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the value of the new node :");
				scanf("%d",&val);
				tree=insertelement(tree,val);
				break;
			case 2:
				printf("\nIn Preorder Traversal,the elements of the tree are:\n");
				preorder(tree);
				break;
			case 3:
				printf("\nIn Inorder Traversal,the elements of the tree are:\n");
				inorder(tree);
				break;
			case 4:
				printf("\nIn Postorder Traversal,the elements of the tree are:\n");
				postorder(tree);
				break;
			case 5:
				ptr=smallestelement(tree);
				printf("\nSmallest Element in the tree:%d",ptr->data);
				break;
			case 6:
				ptr=largestelement(tree);
				printf("\nLargest Element in the tree:%d",ptr->data);
			case 7:
				printf("\nEnter the element to be deleted:");
				scanf("%d",&val);
				tree=deleteelement(tree,val);
				break;
			case 8:
				printf("\nTotal number of nodes:%d",total_nodes(tree));
				break;
			case 9:
				printf("\nTotal number of external nodes:%d",total_external_nodes(tree));
				break;
			case 10:
				printf("\nTotal number of internal nodes:%d",total_internal_nodes(tree));
				break;
			case 11:
				printf("\nThe height of the tree:%d",height(tree));
				break;
			case 12:
				tree=mirrorimage(tree);
				break;
			case 13:
				tree=deletetree(tree);
				break;
		}
	}while(option != 14);
	return 0;
}

void create_tree(struct node *tree)
{
	tree=NULL;
}

struct node *insertelement(struct node *tree,int val)
{
	struct node *ptr,*nodeptr,*parentptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	if(tree==NULL)
	{
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parentptr=nodeptr;
			if(val < nodeptr->data)
					nodeptr=nodeptr->left;
			else
					nodeptr=nodeptr->right;
		}
		if(val < parentptr->data)
				parentptr->left=ptr;
		else
				parentptr->right=ptr;
	}
	return tree;
}

void preorder(struct node *tree)
{
	if(tree != NULL)
	{
		printf("%d\t",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(struct node *tree)
{
	if(tree != NULL)
	{
		inorder(tree->left);
		printf("%d\t",tree->data);
		inorder(tree->right);
	}
}

void postorder(struct node *tree)
{
	if(tree != NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d\t",tree->data);
	}
}

struct node *smallestelement(struct node *tree)
{
	if((tree == NULL)||(tree->left==NULL))
			return tree;
	else
			return smallestelement(tree->left);
}

struct node *largestelement(struct node *tree)
{
	if((tree != NULL)||(tree->right==NULL))
			return tree;
	else
			return largestelement(tree->right);
}

struct node *deleteelement(struct node *tree,int val)
{
	struct node *cur,*parent,*suc,*psuc,*ptr;
	if(tree->left==NULL)
	{
		printf("\nThe tree is empty ");
		return(tree);
	}
	parent=tree;
	cur=tree->left;
	while(cur != NULL && val != cur->data)
	{
		parent=cur;
		cur=(val<cur->data)?cur->left:cur->right;
	}
	if(cur==NULL)
	{
		printf("\nThe value to be deleted is not present in the tree");
		return(tree);
	}
	if(cur->left==NULL)
			ptr=cur->right;
	else if(cur->right==NULL)
			ptr=cur->left;
	else
	{
		psuc=cur;
		cur=cur->left;
		while(suc->left != NULL)
		{
			psuc=suc;
			suc=suc->left;
		}
		if(cur==psuc)
		{
			suc->left=cur->right;
		}
		else
		{
			suc->left=cur->left;
			psuc->left=suc->right;
			suc->right=cur->right;
		}
		ptr=suc;
	}
	if(parent->left==cur)
			parent->left=ptr;
	else
			parent->right=ptr;
	free(cur);
	return tree;
}

int total_nodes(struct node *tree)
{
	if(tree==NULL)
			return 0;
	else
			return(total_nodes(tree->left)+total_nodes(tree->right)+1);
}

int total_external_nodes(struct node *tree)
{
	if(tree==NULL)
			return 0;
	else if((tree->left==NULL)&&(tree->right==NULL))
			return 1;
	else
			return (total_external_nodes(tree->left)+total_external_nodes(tree->right));
}

int total_internal_nodes(struct node *tree)
{
	if((tree==NULL)||((tree->left==NULL)&&(tree->right==NULL)))
			return 0;
	else
			return(total_internal_nodes(tree->left)+total_internal_nodes(tree->right)+1);
}

int height(struct node *tree)
{
	int leftheight,rightheight;
	if(tree==NULL)
			return 0;
	else
	{
		leftheight=height(tree->left);
		rightheight=height(tree->right);
		if(leftheight>rightheight)
				return (leftheight+1);
		else
				return (rightheight+1);
	}
}

struct node *mirrorimage(struct node *tree)
{
	struct node *ptr;
	if(tree != NULL)
	{
		mirrorimage(tree->left);
		mirrorimage(tree->right);
		ptr=tree->left;
		ptr->left=ptr->right;
		tree->right=ptr;
	}
}

struct node *deletetree(struct node *tree)
{
	if(tree != NULL)
	{
		deletetree(tree->left);
		deletetree(tree->right);
		free(tree);
	}
}