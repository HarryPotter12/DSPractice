#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}node;

node *head;

node *push(node *);
void pop(node *);
void display(node *);

int main()
{
	int ch, y, num;
	char j;
	node *d;
	head = NULL;
	d = head;
	/*clrscr();*/
	printf("\n*-*-*-*-*-*-*-*-*-* STACK USING LINKED LIST *-*-*-*-*-*-*-*-*-*\n\n");
	do
	{
		printf("\n1.Push\n2.Pop\n3.Display\n\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			d = push(d);
			display(head);
			break;
		case 2:
			pop(head);
			display(head);
			break;
		case 3:
			display(head);
			break;
		default:
			printf("\nYou have entered a wrong chice.");
		}
		printf("\nWant to do again? (y/n) ");
		fflush(stdin);
		scanf("%c", &j);
	}
	while (j == 'y' || j == 'Y');
	getch();
	return 0;
}

node *push(node *d)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	printf("\nEnter node data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	if (head == NULL)
	{
		head = temp;
		d = head;
	}
	else
	{
		d->link = temp;
		d = temp;
	}
	return(d);
}

void pop(node *l)
{
	node *temp;
	if (l == NULL)
		printf("\nStack underflow.\n");
	else if (l->link == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		while (l != NULL)
		{
			if (l->link->link == NULL)
			{
				temp = l->link;
				l->link = NULL;
				free(temp);
				break;
			}
			else
				l = l->link;
		}
	}
}

void display(node *l)
{
	printf("( %u ) -> ", l);
	while (l != NULL)
	{
		printf("( %u | %d ) -> ", l->data, l->link);
		l = l->link;
	}
	printf("NULL");
}

