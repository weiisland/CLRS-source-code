#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

node* init_link()
{
	node* head;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	return head;
}

void create_link(node *head, int size)
{
	node* p;
	int i;
	for(i = 0; i < size; i++)
	{
		p = (node*)malloc(sizeof(node));
		scanf("%d", &(p->data));
		p->next = head->next;
		head->next = p;
	}
}

int search_link(node* head, int x)
{
	if(head == NULL)
	{
		return -1;
	}
	int n = 0;
	node *p;
	p = head->next;
	while(p != NULL)
	{
		n++;
		if(p->data == x)
		{
			return n;
		}		
		p = p->next;
	}	
}

void push(node *head, int x)
{
	node *p;
	p = (node*)malloc(sizeof(node));
	p->data = x;
	p->next = head->next;
	head->next = p;
}

void pop(node *head)
{
	node *p = head->next;
	head->next = p->next;
	free(p);
}

int main()
{
	node *head = init_link();
	create_link(head, 5);
	push(head, 6);
	pop(head);
	int n = search_link(head, 5);
	printf("%d\n", n);
	return 0;	
}
