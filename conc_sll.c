#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head1, *head2;
node *append1(node *);
node *append2(node *);
void display(node *);
void conc(node *);
int main()
{
	int c;
	char ch;
	node *d1, *d2;
	head1 = NULL;
	d1 = head1;
	head2 = NULL;
	d2 = head2;
	printf("Enter 1st Linked List: \n");
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		d1 = append1(d1);
		printf("Do you want to create another node? (y/n) ");
		fflush(stdin);
		ch = getchar();
	}
	printf("\nThe first linked list: \n");
	display(head1);
	printf("\nEnter 2nd Linked List: \n");
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		d2 = append2(d2);
		printf("Do you want to create another node? (y/n) ");
		fflush(stdin);
		ch = getchar();
	}
	printf("\nThe second linked list: \n");
	display(head2);
	conc(head1);
	printf("\n\nLinked list after concatenation: \n");
	display(head1);
	return 0;
}
node *append1(node *d1)
{
	node *temp1;
	temp1 = (node *)malloc(sizeof(node));
	printf("\nEnter node data: ");
	scanf("%d", &temp1->data);
	temp1->link = NULL;
	if (head1 == NULL)
	{
		head1 = temp1;
		d1 = head1;
	}
	else
	{
		d1->link = temp1;
		d1 = temp1;
	}
	return(d1);
}
node *append2(node *d2)
{
	node *temp2;
	temp2 = (node *)malloc(sizeof(node));
	printf("\nEnter node data: ");
	scanf("%d", &temp2->data);
	temp2->link = NULL;
	if (head2 == NULL)
	{
		head2 = temp2;
		d2 = head2;
	}
	else
	{
		d2->link = temp2;
		d2 = temp2;
	}
	return(d2);
}
void conc(node *l)
{
	while (l->link != NULL)
		l = l->link;
	l->link = head2;
}
void display(node *l)
{
	printf("( %u ) -> ", l);
	while (l != NULL)
	{
		printf("( %u | %d ) -> ", l->data, l->link);
		l = l->link;
	}
	printf("NULL\n");
}

