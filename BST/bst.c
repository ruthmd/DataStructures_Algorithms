#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

void insert( struct node **, int);
void preorder( struct node *);
void inorder( struct node *);
void postorder( struct node *);


void insert ( struct node ** t, int x)
{
	struct node * temp, *prev, *curr;
	temp = (struct node*) malloc( sizeof(struct node));
	temp-> data = x;
	temp -> left = NULL;
	temp -> right = NULL;
	if (*t == NULL)
		*t = temp;
	else
	{
		prev = NULL;
		curr = *t;
		while (curr != NULL)
		{
			prev = curr;
			if (x<= curr -> data)
				curr = curr -> left;
			else 
				curr = curr -> right;
		}
		if (x<= prev -> data)
			prev -> left = temp;
		else 
			prev -> right = temp;
	}
}

void preorder( struct node * t)
{
	if(t != NULL)
	{
		printf("%d -> ", t-> data);
		preorder(t-> left);
		preorder( t-> right);
	}
}

void inorder( struct node * t)
{
	if(t != NULL)
	{
		inorder(t-> left);
		printf("%d -> ", t-> data);	
		inorder( t-> right);
	}
}

void postorder( struct node * t)
{
	if(t != NULL){
		postorder(t-> left);
		postorder(t-> right);
		printf("%d -> ", t-> data);
	}
} 

int main()
{
	struct node *root = NULL;
	
	return 0;
}