#include <stdlib.h>
#include <stdio.h>

typedef int data;
typedef struct node
{
	data value;
	struct node* next;
} node;

typedef struct list
{
	node* head;
} list;

list* create_list();
void print_list(list*);
int delete_node(list*,data);
void insert_node(list*,data);

int main (void)
{
	list* list1 ;
	int choice;
	data val;
	while(1)
	{
		printf("Single Linked List Prompt\n");
		printf("1. Create New List\n2. Insert Element\n3. Delete Element\n4. Print List\n5. exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: list1 = create_list();
				break;

			case 2: printf("Enter value : \n");
				scanf("%d",&val);
				insert_node(list1,val);
				break;

			case 3: printf("Enter value : \n");
				scanf("%d",&val);
				if(delete_node(list1,val)==-1)
					printf("Element not found\n");
				break;

			case 4: print_list(list1);
				break;

			case 5: exit(0);
		}
	}
	return 0;
}

list* create_list()
{
	data val;
	list* l = malloc(sizeof(list));
	node* p = malloc(sizeof(node));

	printf("Enter elements one by one, enter -1 to end \n");
	printf("Enter value : ");
	scanf("%d",&val);
	p->value = val;
	p->next=NULL;
	l->head=p;

	while(1)
	{
		printf("Enter value : ");
		scanf("%d",&val);
		if(val==-1)
			break;
		insert_node(l,val);
	}
	return l;
}

void print_list(list* l)
{
	if(l==NULL)
		{printf("Print : List not found \n");exit(0);}
	node* pointer = l->head;
	printf("List Elements : ");
	while(pointer)
	{
		printf("%d ",pointer->value);
		pointer = pointer->next;
	}
	printf("\n");
}

void insert_node(list* l,data val)
{
	node* p = malloc(sizeof(node));
	node* n = l->head;
	p->value=val;
	if(val < n->value)
	{
		p->next=l->head;
		l->head=p;
	}
	else
	{
		while(n->next!=NULL && (n->next->value < p->value))
			n=n->next;
		p->next=n->next;
		n->next=p;
	}
}

int delete_node(list* l,data val)
{
	node* n = l->head;
	if(n->value==val)
		l->head = l->head->next;
	else
		while(n->next != NULL)
		{
			if(n->next->value == val)
				{n->next=n->next->next; return 0;}
			n=n->next;
		}
	return -1;
}
