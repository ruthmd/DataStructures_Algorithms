#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data) { 
    Node *temp =  new Node();
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void BFS(Node *root) {
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		Node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<"-> ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}

void inorder_it(Node *root) {
    stack<Node*> S;
	unordered_map<Node*, int> cnt;

    S.push(root);
    while(!S.empty()){
        Node* cur = S.top();
        if(cur == NULL) { 
			S.pop(); 
			continue; 
		}
        if (cnt[cur] == 0) S.push(cur->left);
        else if(cnt[cur] == 1) cout<<cur->data<<"-> ";
        else if (cnt[cur] == 2) S.push(cur->right);
        else S.pop();
        cnt[cur]++;
    }
}

void postorder_it(Node *root) {
    stack<Node*> S;
	unordered_map<Node*, int> cnt;

    S.push(root);
    while(!S.empty()){
        Node* cur = S.top();
        if(cur == NULL) { 
			S.pop(); 
			continue; 
		}
        if (cnt[cur] == 0) S.push(cur->left);
        else if(cnt[cur] == 1) S.push(cur->right);
        else if (cnt[cur] == 2) cout<<cur->data<<"-> ";
        else S.pop();
        cnt[cur]++;
    }
}

void preorder_it(Node *root) {
    stack<Node*> S;
	unordered_map<Node*, int> cnt;

    S.push(root);
    while(!S.empty()){
        Node* cur = S.top();
        if(cur == NULL) { 
			S.pop(); 
			continue; 
		}
        if (cnt[cur] == 0) cout<<cur->data<<"-> ";
        else if(cnt[cur] == 1) S.push(cur->left);
        else if (cnt[cur] == 2) S.push(cur->right);
        else S.pop();
        cnt[cur]++;
    }
}

void inorder(Node *temp){
	if(temp!=NULL){
		inorder(temp->left);
		cout<<temp->data<<"-> ";
		inorder(temp->right);
	}
}

void preorder(Node *temp){
	if(temp!=NULL){
		cout<<temp->data<<"-> ";
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder(Node *temp){
	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<"-> ";
	}
}

Node* Insert(Node* root, int data) { 
    if (root == NULL)
		return newNode(data);
    if (data < root->data) 
        root->left  = Insert(root->left, data); 
    else
        root->right = Insert(root->right, data); 
    return root; 
} 


void invert(struct Node* node)  { 
    if (node == NULL)  
        return;  
    else{ 
        struct Node* temp; 
        /* do the subtrees */
        invert(node->left);  
        invert(node->right); 
      
        /* swap the pointers in this node */
		temp     = node->left; 
        node->left = node->right; 
        node->right = temp;
    } 
}  

int FindMin(Node* node) { 
    Node* current = node; 
    if (current==NULL)
        return -1;

    while (current->left != NULL) 
        current = current->left; 
  
    return current->data; 
} 

int FindMax(Node* node) { 
    Node* current = node; 
    if (current==NULL)
        return -1;
  
    while (current && current->right != NULL) 
        current = current->right; 
  
    return current->data; 
}

Node* deleteNode(Node* root, int data) { 
    if (root == NULL) return root; 
  
    if (data < root->data) 
        root->left = deleteNode(root->left, data); 
  
    else if (data > root->data) 
        root->right = deleteNode(root->right, data); 
  
    else{ 
        // node with only one child or no child 
        if (root->left == NULL) { 
        	Node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) { 
            Node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        int min = FindMin(root->right);
        root->data =  min;
        root->right = deleteNode(root->right, min); 
    } 
    return root; 
}

Node* insertIter(Node* root, int key){
    // Create a new Node containing
    // the new element
    Node* newnode = newNode(key);
 
    // Pointer to start traversing from root and
    // traverses downward path to search
    // where the new node to be inserted
    Node* x = root;
 
    // Pointer y maintains the trailing
    // pointer of x
    Node* y = NULL;
 
    while (x != NULL) {
        y = x;
        if (key < x->data)
            x = x->left;
        else
            x = x->right;
    }
 
    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (y == NULL)
        y = newnode;
 
    // If the new key is less then the leaf node key
    // Assign the new node to be its left child
    else if (key < y->data)
        y->left = newnode;
 
    // else assign the new node its right child
    else
        y->right = newnode;
 
    // Returns the pointer where the
    // new node is inserted
    return y;
}

int main() {
	Node* root = NULL;
	root = Insert(root, 7);
	root = Insert(root, 3);
	root = Insert(root, 10);
	root = Insert(root, 8);
	root = Insert(root, 12);
	root = Insert(root, 2);
	root = Insert(root, 4);
	cout<<"inorder iteratively"<<endl;
	inorder_it(root);	
	cout<<endl;
	cout<<"inorder recursively"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"preorder iteratively"<<endl;
	preorder_it(root);	
	cout<<endl;
	cout<<"preorder recursively"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"postorder iteratively"<<endl;
	preorder_it(root);	
	cout<<endl;
	cout<<"postorder recursively"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"Printing Level Order"<<endl;
	BFS(root);
	cout<<endl;
	cout<<"iverted tree"<<endl;
	invert(root);
	inorder(root);
	cout<<endl;
}