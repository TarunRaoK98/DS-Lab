#include <stdio.h>
#include <stdlib.h>

// BST

typedef struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
} Node;

Node* newNode (int);
Node* search (Node*, int);
Node* insert (Node*, int);
Node* delete (Node*, int);
void inOrder (Node*);
void preOrder (Node*);
void postOrder (Node*);
void reverseOrder (Node*);

int main (void)
{
	Node* root=NULL;
	
	root = insert(root,25);
	root = insert(root,35);
	root = insert(root,5);
	root = insert(root,15);
	
	inOrder(root);	printf("\n");
	
	root = delete(root,15);
	inOrder(root);	printf("\n");

	root = delete(root,5);
	inOrder(root);	printf("\n");

	root = delete(root,35);
	inOrder(root);	printf("\n");

	root = delete(root,25);
	inOrder(root);	printf("\n");
	
	return 0;
}

Node* newNode(int key)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->key   = key;
	node->left   = NULL;
	node->right  = NULL;
	return(node);
}

Node* min(Node* node)
{
	if(node->left)
		node= min(node->left);
	return node;
}

Node* search (Node* node, int key)
{
	if(node == NULL)
		return (NULL);
	if(key < node->key)
		return search(node->left, key);
	else if (key > node->key)
		return search(node->right, key);
	else
		return (node);
}

Node* insert (Node* node, int key)
{
	if(node == NULL)
		return (newNode(key));
	if(key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);
	else
		return (node);	
}

Node* delete (Node* node, int key)
{
	if(node == NULL)
		return (NULL);
	if(key < node->key)
		node->left = delete(node->left, key);
	else if(key > node->key)
		node->right = delete(node->right, key);
	else
	{
		if(node->right==NULL){
			Node* n = node->left;
			free(node);
			return (n);
		}
		else if(node->left==NULL){
			Node*n = node->right;
			free(node);
			return (n);
		}
		else
		{
			Node* successor = min(node->right);
			node->key=successor->key;
			node->right=delete(node->right,successor->key);
		}
		return (node);
	}
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
