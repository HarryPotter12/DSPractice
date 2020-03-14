#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct cll
{
	int data;
	struct cll *link;
}cll;

cll *head;

cll *append(cll *);
void display(cll *);
int count_node(cll *);

int main()
{
	int n, count, i;
	char j;
	cll *d;
	char ch = 'y';
	d = head;
	/*clrscr();*/
	while (ch == 'y' || ch == 'Y')
	{
		d = append(d);
		printf("Do you want to create another node? (y/n) ");
		fflush(stdin);
		ch = getchar();
	}
	do
	{
		printf("\n\n1.display\n2.count no. of nodes\n\n");
		printf("\n\nEnter the choice: ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			display(head);
			break;
		case 2:
			count = count_node(head);
			printf("\n\nThe no. of nodes: %d", count);
			break;
		default:
			printf("\nYou have entered a wrong choice");
		}
		printf("\nWant to do again? (y/n) ");
		fflush(stdin);
		scanf("%c", &j);
	}
	while (j == 'y' || j == 'Y');
	return 0;
}

cll *append(cll *d)
{
	cll *x;
	x = (cll *)malloc(sizeof(cll));
	printf("\nEnter node data: ");
	scanf("%d", &x->data);
	if (head == NULL)
	{
		head = x;
		d = head;
	}
	else
	{
		d->link = x;
		d = x;
	}
	d->link = head;
	return d;
}

void display(cll *l)
{
	printf("[ %u ] -> ", l);
	do
	{
		printf("[ %d | %u ] -> ", l->data, l->link);
		l = l->link;
	}
	while (l != head);
	printf(" HEAD ");
}

int count_node(cll *l)
{
	int c = 0;
	if (l == NULL)
	{
		printf("\nEmpty linked list");
		return 0;
	}
	else
	{
		do
		{
			c++;
			l = l->link;
		}
		while (l != head);
	}
	return c;
}

