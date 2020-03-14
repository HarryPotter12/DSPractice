#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node *head;
node *append(node *);
void display(node *);
int count_node(node *);
void insert_start(node *);
void insert_before(node * , int );
void insert_after(node * , int );
void insert_last(node *);
void del_start(node *);
void del_mid(node *, int );
void del_last(node *);
int srch_val(node *, int );
void srch_pos(node *, int );
node *rev(node *);
int main()
{
	int pos, i, val;
	node *d, *h;
	char ch = 'y', j;
	int count;
	head = NULL;
	d = head;
	/*clrscr();*/
	printf("\n*-*-*-*-*-*-*-*-*-* SINGLY LINKED LIST *-*-*-*-*-*-*-*-*-*\n\n");
	while (ch == 'y' || ch == 'Y')
	{
		d = append(d);
		printf("Do you want to create another node? (y/n) ");
		fflush(stdin);
		ch = getchar();
	}
	do
	{
		printf("\n\n1.display\n2.count no. of nodes\n3.insertion at the beginning\n4.insertion at the middle(before a node)\n5.insertion at the middle(after a node)\n6.insertion at the end\n7.deletion at the beginning\n8.deletion at the middle\n9.deletion at the end\n10.search a node with value\n11.search a node with position\n12.reverse\n\n");
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
		case 3:
			insert_start(head);
			display(head);
			break;
		case 4:
			val = 0;
			printf("\nEnter the node data before which you want to enter: ");
			scanf("%d", &val);
			insert_before(head, val);
			display(head);
			break;
		case 5:
			val = 0;
			printf("\nEnter the node data after which you want to enter: ");
			scanf("%d", &val);
			insert_after(head, val);
			display(head);
			break;
		case 6:
			insert_last(head);
			display(head);
			break;
		case 7:
			del_start(head);
			display(head);
			break;
		case 8:
			val = 0;
			printf("\nEnter the node data which you want to delete: ");
			scanf("%d", &val);
			del_mid(head, val);
			display(head);
			break;
		case 9:
			del_last(head);
			display(head);
			break;
		case 10:
			val = 0;
			printf("\nEnter the node data which you want to search for: ");
			scanf("%d", &val);
			pos = srch_val(head, val);
			if (pos == -1)
				printf("\nElement not found");
			else
				printf("\nThe position of the node is: %d", pos);
			break;
		case 11:
			val = 0;
			printf("\nEnter the position of the node which you want to search for: ");
			scanf("%d", &val);
			srch_pos(head, val);
			break;
		case 12:
			h = rev(head);
			display(h);
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
node *append(node *d)
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
int count_node(node *l)
{
	int c = 0;
	if (l == NULL)
	{
		printf("\nEmpty link list");
		return 0;
	}
	else
	{
		while (l != NULL)
		{
			c++;
			l = l->link;
		}
	}
	return c;
}
void insert_start(node *l)
{
	node *t;
	t = (node *)malloc(sizeof(node));
	if (l == NULL)
		printf("\nEmpty link list");
	else
	{
		printf("\nEnter node data: ");
		scanf("%d", &t->data);
		t->link = head;
		head = t;
	}
}
void insert_before(node *l, int v)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	if (l == NULL)
		printf("\nEmpty link list");
	else
	{
		while (l != NULL)
		{
			if (l->link->data == v)
				break;
			else
				l = l->link;
		}
		if (l == NULL)
			printf("\nElement not found");
		else
		{
			printf("\nEnter node data: ");
			scanf("%d", &temp->data);
			temp->link = l->link;
			l->link = temp;
		}
	}
}
void insert_after(node *l, int v)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	if (l == NULL)
		printf("\nEmpty link list");
	else
	{
		while (l != NULL)
		{
			if (l->data == v)
				break;
			else
				l = l->link;
		}
	}
	if (l == NULL)
		printf("\nElement not found");
	else
	{
		printf("\nEnter node data: ");
		scanf("%d", &temp->data);
		temp->link = l->link;
		l->link = temp;
	}
}
void insert_last(node *l)
{
	node *t;
	t = (node *)malloc(sizeof(node));
	printf("\nEnter node data: ");
	scanf("%d", &t->data);
	while (l->link != NULL)
		l = l->link;
	l->link = t;
	t->link = NULL;
}
void del_start(node *l)
{
	node *temp;
	if (l == NULL)
		printf("\n Empty link list");
	else
	{
		temp = head;
		head = head->link;
		free(temp);
	}
}
void del_mid(node *l, int val)
{
	node *temp;
	if (l == NULL)
		printf("\n Empty link list");
	else
	{
		while (l != NULL)
		{
			if (l->link->data == val)
			{
				temp = l->link;
				l->link = temp->link;
				free(temp);
				break;
			}
			else
				l = l->link;
		}
	}
	if (l == NULL)
		printf("\n Element not found");
}
void del_last(node *l)
{
	node *temp;
	if (l == NULL)
		printf("\nEmpty link list");
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
int srch_val(node *l, int val)
{
	int c = 0;
	if (l == NULL)
	{
		printf("\nEmpty Linked list\n");
		return 0;
	}
	else
	{
		while (l != NULL)
		{
			c++;
			if (l->data == val)
				return c;
			else
				l = l->link;
		}
		return (-1);
	}
}
void srch_pos(node *l, int pos)
{
	int c = 0;
	if (l == NULL)
		printf("\n Empty Link list");
	else
	{
		while (l != NULL)
		{
			c++;
			if (c == pos)
			{
				printf("\n value at position %d = %d", pos, l->data);
				break;
			}
			else
				l = l->link;
		}
	}
}
node *rev(node *l)
{
	node *p, *q, *r;
	/*	  printf("firstly:\np=%u\tq=%u\tr=%u\tl=%u\tp->link=%u\tq->link=%u\n",p,q,r,l,p->link,q->link);*/
	p = l;
	/*	  printf("after p=l\np=%u\tl=%u\n",p,l);*/
	q = NULL;
	/*printf("after q=NULL\np=%u\tq=%u\tl=%u\n",p,q,l);*/
	while (p != NULL)
	{
		/*	  printf("inside while:\np=%u\tq=%u\tr=%u\tl=%u\tp->link=%u\tq->link=%u\n",p,q,r,l,p->link,q->link);*/
		r = q;
		/*	  printf("inside:\nafter r=q\np=%u\tq=%u\tr=%u\tl=%u\n",p,q,r,l);*/
		q = p;
		/*printf("after q=p\np=%u\tq=%u\tr=%u\tl=%u\n",p,q,r,l);*/
		p = p->link;
		/*printf("after p=p->link\np=%u\tq=%u\tr=%u\tl=%u\tp->link=%u\n",p,q,r,l,p->link);*/
		q->link = r;
		/*printf("after q->link=r\np=%u\tq=%u\tr=%u\tl=%u\tp->link=%u\tq->link=%u\n",p,q,r,l,p->link,q->link);*/
	}
	/*printf("outside while:\np=%u\tq=%u\tr=%u\tl=%u\tp->link=%u\tq->link=%u\n",p,q,r,l,p->link,q->link);*/
	l = q;
	/*printf("after l=q\np=%u\tq=%u\tr=%u\tl=%u\tp->link=%u\tq->link=%u\n",p,q,r,l,p->link,q->link);*/
	return (l);
}

