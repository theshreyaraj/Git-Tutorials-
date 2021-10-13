#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
}tree;

int main()
{
	int data;
	tree *TREE=NULL;
	tree *inserttree(int data,tree *p);
	tree *printtree(tree *TREE,int level);
	
	while(1)
	{
		printf("\nKEY TO INSERT:");
		scanf("%d",&data);
		if(data==0)
			break;
		TREE=inserttree(data,TREE);
		printf("\nDisplay Tree\n");
		printtree(TREE,1);
	}
	return 0;
}


tree *inserttree(int data,tree *p)
{
	if(!p)
	{
		p=(tree*)malloc(sizeof(tree));
		p->data=data;
		p->left=NULL;
		p->right=NULL;
		return(p);
	}
	if(data < p->data)
		p->left=inserttree(data,p->left);
	else if(data > p->data)
		p->right=inserttree(data,p->right);
	    return(p);
}

tree *printtree(tree *TREE,int level)
{
	int i;
	if(TREE)
	{
		printtree(TREE->right,level+1);
		printf("\n");
		for(i=0;i<level;i++)
			printf(" ");
		printf("%d",TREE->data);
		printtree(TREE->left,level+1);
	}
	return(NULL);
}