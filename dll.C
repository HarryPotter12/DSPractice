#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct dll
{
	struct dll *llink;
	int data;
	struct dll *rlink;
}dll;
dll *head;

dll *append(dll *);
void display(dll *);
int count_node(dll *);
void insert_start(dll *);
void insert_before(dll *, int );
void insert_after(dll *, int );
void insert_last(dll *);
void del_start(dll *);
void del_mid(dll *, int );
void del_last(dll *);
int srch_val(dll *, int );
void srch_pos(dll *, int );
/*void add_pos(dll *, int );*/

int main()
{
	int n, val, count, a, i, pos;
	char j;
	dll *d;
	char ch = 'y';
	d = head;
	/*clrscr();*/
	printf("\n*-*-*-*-*-*-*-*-*-* DOUBLY LINKED LIST *-*-*-*-*-*-*-*-*-*\n\n");
	while (ch == 'y' || ch == 'Y')
	{
		d = append(d);
		printf("Do you want to create another node? (y/n) ");
		fflush(stdin);
		ch = getchar();
	}
	do
	{
		printf("\n\n1.display\n2.count no. of nodes\n3.insertion at the beginning\n4.insertion at the middle(before a node)\n5.insertion at the middle(after a node)\n6.insertion at the end\n7.deletion at the beginning\n8.deletion at the middle\n9.deletion at the end\n10.search a node with value\n11.search a node with position\n\n");
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
			/*	  case 10:
					printf("Enter the position: ");
					scanf("%d", &a);
					add_pos(head, a);
					display(head);
					break;*/
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
		default:
			printf("\nYou have entered a wrong choice");
		}
		printf("\nWant to do again? (y/n) ");
		fflush(stdin);
		scanf("%c", &j);
	}
	while (j == 'y' || j == 'Y');
	/*	  getch();*/
	return 0;
}
dll *append(dll *d)
{
	dll *x;
	x = (dll *)malloc(sizeof(dll));
	printf("\nEnter node data: ");
	scanf("%d", &x->data);
	x->rlink = NULL;
	if (head == NULL)
	{
		x->llink = NULL;
		head = x;
		d = head;
	}
	else
	{
		d->rlink = x;
		x->llink = d;
		d = x;
	}
	return (d);
}
void display(dll *l)
{
	if (l == NULL)
		printf("\nLINKED LIST EMPTY");
	else
	{
		printf("\n");
		while (l != NULL)
		{
			printf(" [ %u | %d | %u ] -> ", l->llink, l->data, l->rlink);
			l = l->rlink;
		}
		printf(" NULL");
	}
}
int count_node(dll *l)
{
	int c = 0;
	if (l == NULL)
	{
		printf("\nEmpty linked list");
		return 0;
	}
	else
	{
		while (l != NULL)
		{
			c++;
			l = l->rlink;
		}
	}
	return c;
}
void insert_start(dll *l)
{
	dll *t;
	t = (dll *)malloc(sizeof(dll));
	if (l == NULL)
		printf("\nEmpty linked list");
	else
	{
		printf("\nEnter node data: ");
		scanf("%d", &t->data);
		t->llink = NULL;
		head->llink = t;
		t->rlink = head;
		head = t;
	}
}
void insert_before(dll *l, int v)
{
	dll *temp;
	temp = (dll *)malloc(sizeof(dll));
	if (l == NULL)
		printf("\nEmpty linked list");
	else
	{
		while (l != NULL)
		{
			if (l->data == v)
				break;
			else
				l = l->rlink;
		}
		if (l == NULL)
			printf("\nElement not found");
		else
		{
			printf("\nEnter node data: ");
			scanf("%d", &temp->data);
			l->llink->rlink = temp;
			temp->llink = l->llink;
			temp->rlink = l;
			l->llink = temp;
		}
	}
}
void insert_after(dll *l, int v)
{
	dll *temp;
	temp = (dll *)malloc(sizeof(dll));
	if (l == NULL)
		printf("\nEmpty linked list");
	else
	{
		while (l != NULL)
		{
			if (l->data == v)
				break;
			else
				l = l->rlink;
		}
		if (l == NULL)
			printf("\nElement not found");
		else
		{
			printf("\nEnter node data: ");
			scanf("%d", &temp->data);
			temp->rlink = l->rlink;
			l->rlink->llink = temp;
			l->rlink = temp;
			temp->llink = l;
		}
	}
}
void insert_last(dll *l)
{
	dll *t;
	t = (dll *)malloc(sizeof(dll));
	printf("\nEnter node data: ");
	scanf("%d", &t->data);
	while (l->rlink != NULL)
		l = l->rlink;
	t->llink = l;
	l->rlink = t;
	t->rlink = NULL;
}
void del_start(dll *l)
{
	dll *t;
	if (l == NULL)
		printf("\nEmpty linked list");
	else
	{
		t = head;
		head = head->rlink;
		head->llink = NULL;
		free(t);
	}
}
void del_mid(dll *l, int v)
{
	dll *p;
	p = l;
	if (l == NULL)
		printf("\nEmpty linked list");
	else
	{
		while (p != NULL)
		{
			if (p->data == v)
			{
				if (l == p)
				{
					l = l->rlink;
					l->llink = NULL;
				}
				else if (p->rlink == NULL)
					p->llink->rlink = NULL;
				else
				{
					p->llink->rlink = p->rlink;
					p->rlink->llink = p->llink;
				}
				free(p);
				return;
			}
			p = p->rlink;
		}
	}
	if (l == NULL)
		printf("\nElement not found");
}
void del_last(dll *l)
{
	dll *t;
	if (l == NULL)
		printf("\nEmpty linked list");
	else
	{
		while (l != NULL)
		{
			if (l->rlink->rlink == NULL)
			{
				t = l->rlink;
				l->rlink = NULL;
				free(t);
				break;
			}
			else
				l = l->rlink;
		}
	}
}
int srch_val(dll *l, int val)
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
				l = l->rlink;
		}
		return (-1);
	}
}
void srch_pos(dll *l, int pos)
{
	int c = 0;
	if (l == NULL)
		printf("\nEmpty Linked list\n");
	else
	{
		while (l != NULL)
		{
			c++;
			if (c == pos)
			{
				printf("\nValue at %d th position = %d", pos, l->data);
				return;
			}
			else
				l = l->rlink;
		}
		printf("\nNot found");
	}
}
/*void add_pos(dll *l, int val)
{
	dll *x, *p;
	int i = 0;
	x = (dll *)malloc(sizeof(dll));
	p = l;
	if (l == NULL)
		printf("\n LINK LIST empty");
	else
	{
		while (i != val)
		{
			p = p->rlink;
			if (p == NULL)
			{
				printf("\n Elements less");
				return;
			}
			i++;
		}
		if (p == NULL)
			printf("\nElement not found");
		else
		{
			p = p->llink;
			printf("\nEnter node data: ");
			scanf("%d", x->data);
			l->llink->rlink = x;
			x->llink = l->llink;
			x->rlink = l;
			l->llink = x;
		}
	}
}
*/

