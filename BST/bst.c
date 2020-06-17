#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node *newNode(int data) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

struct node* insert(struct node* node, int data) 
{ 
    if (node == NULL) 
		return newNode(data); 
  
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else
        node->right = insert(node->right, data); 
  
    return node; 
} 

void preorder( struct node * t)
{
	if(t != NULL){
		printf("%d -> ", t-> data);
		preorder(t-> left);
		preorder( t-> right);
	}
}

void inorder( struct node * t)
{
	if(t != NULL){
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

struct node * FindMin(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

struct node* deleteNode(struct node* root, int data) 
{ 
    if (root == NULL) return root; 
  
    if (data < root->data) 
        root->left = deleteNode(root->left, data); 
  
    else if (data > root->data) 
        root->right = deleteNode(root->right, data); 
  
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        struct node* temp = FindMin(root->right); 
  
        root->data = temp->data; 
  
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 

int main()
{
	struct node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 6);
	root = insert(root, 13);
	root = insert(root, 8);
	root = insert(root, 15);
	root = insert(root, 4);
	root = insert(root, 19);
	
	printf("\nprinting inorder.....\n");
	inorder(root);

	deleteNode(root, 13);

	printf("\nprinting inorder.....\n");
	inorder(root);

	return 0;
}