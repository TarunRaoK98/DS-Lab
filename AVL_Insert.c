#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;
 
Node* newNode(int);
Node* insert(Node*, int);
Node *rightRotate(Node*);
Node *leftRotate(Node*);
int max(int, int);
int balanceFactor(Node*);
int height(Node*);
void inOrder (Node*);
void preOrder (Node*);
void postOrder (Node*);
void reverseOrder (Node*);

int main()
{
	Node *root = NULL;

	root = insert(root, 10);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 20);
	root = insert(root, 50);
	root = insert(root, 60);

	inOrder(root);	printf("\n");

	return 0;
}

Node* newNode(int key)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->key   = key;
	node->left   = NULL;
	node->right  = NULL;
	node->height = 1; 
	return(node);
}
 
Node* insert(Node* node, int key)
{
	if (node == NULL)
		return(newNode(key)); 
	if (key < node->key)
		node->left  = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

	node->height = 1 + max( height(node->left), height(node->right) );

	int balance = balanceFactor(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left =  leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

Node *rightRotate(Node* y)
{
	Node* x = y->left;
	Node* temp = x->right;

	x->right = y;
	y->left = temp;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	return x;
}

Node *leftRotate(Node* x)
{
	Node* y = x->right;
	Node* temp = y->left;

	y->left = x;
	x->right = temp;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	return y;
}

int balanceFactor(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}
 
void inOrder(Node *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%d ", root->key);
		inOrder(root->right);
	}
}

void preOrder(Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);		
		preOrder(root->right);
	}
}

void postOrder(Node *root)
{
	if(root != NULL)
	{
		postOrder(root->left);		
		postOrder(root->right);
		printf("%d ", root->key);
	}
}

void reverseOrder(Node *root)
{
	if(root != NULL)
	{
		reverseOrder(root->right);
		printf("%d ", root->key);
		reverseOrder(root->left);
	}
} 
