#include<stdio.h>

typedef enum{FALSE,TRUE} bool;

struct node
{
	int val;
	int balance;
	struct node *left;
	struct node *right;
};

struct node *search(struct node *ptr,int data)
{
	if(ptr!=NULL)
			if(data < ptr->val)
					ptr=search(ptr->left,data);
			else if(data > ptr->val)
					ptr=search(ptr->right,data);
	return ptr;
}

struct node *insert(int data,struct node *ptr,int *ht_inc)
{
	struct node *aptr;
	struct node *bptr;
	if(ptr==NULL)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		ptr->val=data;
		ptr->left=NULL;
		ptr->right=NULL;
		ptr->balance=0;
		*ht_inc=TRUE;
		return(ptr);
	}
	if(data < ptr->val)
	{
		ptr->left=insert(data,ptr->left,ht_inc);
		if(*ht_inc==TRUE)
		{
			switch(ptr->balance)
			{
				case -1://right heavy
					ptr->balance=0;
					*ht_inc=FALSE;
					break;
				case 0://balanced
					ptr->balance=1;
					break;
				case 1://left heavy
					aptr=ptr->left;
					if(aptr->balance==1)
					{
						printf("Left to Left Rotation\n");
						ptr->left=aptr->right;
						aptr->right=ptr;
						ptr->balance=0;
						aptr->balance=0;
						ptr=aptr;	
					}
					else
					{
						printf("Left to Right Rotation\n");
						bptr=aptr->right;
						aptr->right=bptr->left;
						bptr->left=aptr;
						ptr->left=bptr->right;
						bptr->right=ptr;
						if(bptr->balance==1)
							ptr->balance=0;
						else
							ptr->balance=0;
						if(bptr->balance==-1)
							aptr->balance=1;
						else
							aptr->balance=0;
						bptr->balance=0;
						ptr=bptr;
					}
					*ht_inc=FALSE;
				
			}
		}
	}
	if(data > ptr->val)
	{
		ptr->right=insert(int info,ptr->right,ht_inc);
		if(*ht_inc==TRUE)
		{
			switch(ptr->balance)
			{
				case 1://left heavy
					ptr->balance=0;
					*ht_inc=FALSE;
					break;
				case 0://balanced
					ptr->balance=-1;
					break;
				case -1://right heavy
					aptr=ptr->right;
					if(aptr->balance==-1)
					{
						printf("Right to Right Rotation\n");
						ptr->right=aptr->left;
						aptr->left=ptr;
						ptr->balance=0;
						aptr->balance=0;
						ptr=aptr;
					}
					else
					{
						printf("Right to Left Rotation\n");
						bptr=aptr->left;
						aptr->left=bptr->right;
						bptr->right=aptr;
						ptr->right=bptr->left;
						bptr->left=bptr;
						if(bptr->balance==-1)
							ptr->balance=1;
						else
							ptr->balance=0;
						if(bptr->balance==1)
							aptr->balance=-1;
						else
							aptr->balance=0;
						bptr->balance=0;
						ptr=bptr;
						
					}
					*ht_inc=FALSE;
			}
		}
		
	
	}
	return(ptr);
}

void display(struct node *ptr,int level)
{
	int i;
	if(ptr != NULL)
	{
		display(ptr->right,level+1);
		printf("\n");
		for(i=0;i<level;i++)
			printf(" ");
		printf("%d",ptr->val);
		display(ptr->left,level+1);
	}
}

void inorder(struct node *ptr)
{
	if(ptr !=NULL)
	{
		inorder(ptr->left);
		printf("%d",ptr->val);
		inorder(ptr->right);
	}
}

int main()
{
	bool ht_inc;
	int data;
	int option;
	struct node *root=(struct node *)malloc(sizeof(struct node));
	root=NULL;
	while(1)
	{
		printf("1.Insert\n2.Display\n3.Quit\n");
		printf("Enter your option:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				printf("Enter the value to be inserted:");
				scanf("%d",&data);
					if(search(root,data)==NULL)
						root=insert(data,root,&ht_inc);
						else
						printf("Duplicate value ignored\n");
					break;
			case 2:
				if(root==NULL)
				{
					printf("Tree is empty\n");
					continue;
				}
				printf("Tree is :\n");
				display(root,1);
				printf("\n\n");
				printf("Inorder Traversal is:");
				inorder(root);
				printf("\n");
				break;
		    case 3:
		    	exit(1);
		    	default:
		    		printf("Wrong option!\n");
		}
	}
}

