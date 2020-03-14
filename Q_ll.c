#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *link;
}node;

node *head;
int val;

node *enqueue(node *);
void dequeue(node *);
void display(node *);

int main()
{
	int i, val, p;
	node *d;
	char j;
	printf("\n*-*-*-*-*-*-*-*-*-* QUEUE USING LINKED LIST *-*-*-*-*-*-*-*-*-*\n\n");
	do
	{
		printf("1.display\n2.insertion\n3.deletion\n");
		printf("\nEnter the choice: ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			display(head);
			break;
		case 2:
			d=enqueue(d);
			display(head);
			break;
		case 3:
			dequeue(head);
			display(head);
			break;
		default:
			printf("\nYou have entered a wrong choice");
		}
		printf("\nWant to do again? (y/n) ");
		fflush(stdin);
		scanf("%c", &j);
	}
	while (j == 'y' || j == 'Y');
	getch();
	return 0;
}

node *enqueue(node *d)
{
node *temp;
temp=(node *)malloc(sizeof(node));
printf("\nEnter queue data: ");
scanf("%d",&temp->data);
temp->link=NULL;
if(head==NULL)
{
head=temp;
d=head;
}
else
{
d->link=temp;
d=temp;
}
return(d);
}

void dequeue(node *l)
{
node *t;
if(l==NULL)
printf("\nEmpty queue");
else
{
t=head;
head=head->link;
free(t);
}
}

void display(node *l)
{
while(l!=NULL)
{
printf(" %u -> ",l->data);
l=l->link;
}
printf("END");
}

