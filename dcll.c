#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct dcll
{
	struct dcll *llink;
	int data;
	struct dcll *rlink;
}dcll;

dcll *head;

dcll *append(dcll *);
void display(dcll *);
int count_node(dcll *);

int main()
{
	int n, count, i;
	char j;
	dcll *d;
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

dcll *append(dcll *d)
{
	dcll *x;
	x = (dcll *)malloc(sizeof(dcll));
	printf("\nEnter node data: ");
	scanf("%d", &x->data);
	if (head == NULL)
	{
		head = x;
		d = head;
	}
	else
	{
		d->rlink = x;
		x->llink = d;
		x->rlink = head;
		head->llink = x;
		d = x;
	}
	/*d->link = head;*/
	return d;
}

void display(dcll *l)
{
	printf("[ %u ] -> ", l);
	do
	{
		printf("[ %u | %d | %u ] -> ", l->llink, l->data, l->rlink);
		l = l->rlink;
	}
	while (l != head);
	printf(" HEAD ");
}

int count_node(dcll *l)
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
			l = l->rlink;
		}
		while (l != head);
	}
	return c;
}

