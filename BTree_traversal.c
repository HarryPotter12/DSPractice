#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
};
typedef struct node node;
char ans;
node *makenode();
void maketree(node *);
int count_node(node*);
void inorder(node *);
void postorder(node *);
void preorder(node *);
int cnt = 0;
void main()
{
	node *root;
	int c;
	textbackground(RED);
	textcolor(WHITE);
	clrscr();
	root = makenode();
	maketree(root);
	while (1)
	{
		printf("\n\t\tPrees C for count the no. of nodes");
		printf("\n\t\tPrees I for inorder");
		printf("\n\t\tPrees O for postorder");
		printf("\n\t\tPrees E for preorder");
		printf("\n\t\tPrees X for exit");
		fflush(stdin);
		printf("\n\t\tEnter u r choise=");
		scanf("%s", &ans);
		if (toupper(ans) == 'C')
		{
			c = count_node(root);
			printf("\n\t\tTotal no.of nodes=%d", c);
		}
		if (toupper(ans) == 'I')
		{
			printf("\n\t\tThe inorder sequence is:\n\t\t");
			inorder(root);
		}
		if (toupper(ans) == 'O')
		{
			printf("\n\t\tThe postorder sequence is:\n\t\t");
			postorder(root);
		}
		if (toupper(ans) == 'E')
		{
			printf("\n\t\tThe preorder sequence is:\n\t\t");
			preorder(root);
		}
		if (toupper(ans) == 'X')
		{
			exit(0);
			break;
		}
	}
	getch();
}
node *makenode()
{
	node *nodeptr;
	int data;
	nodeptr = (node*)malloc(sizeof(node));
	printf("\n\t\tEnter the node data:");
	scanf("%d", &data);
	nodeptr->data = data;
	nodeptr->lchild = NULL;
	nodeptr->rchild = NULL;
	return(nodeptr);
}
void maketree(node *root)
{
	char ch;
	printf("\n\t\tDo u want 2 creat the left subtree(Y/N)");
	fflush(stdin);
	ch = getchar();
	if (toupper(ch) == 'Y' || toupper(ch) == 'y')
	{
		root->lchild = makenode();
		maketree(root->lchild);
	}
	printf("\n\t\tDo u want 2 creat the right subtree(Y/N)");
	fflush(stdin);
	ch = getchar();
	if (toupper(ch) == 'Y' || toupper(ch) == 'y')
	{
		root->rchild = makenode();
		maketree(root->rchild);
	}
}
void inorder(node *t)
{
	if (t != NULL)
	{
		inorder(t->lchild);
		printf("(%d)-->", t->data);
		inorder(t->rchild);
	}
}
void preorder(node *t)
{
	if (t != NULL)
	{
		printf("(%d)-->", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
void postorder(node *t)
{
	if (t != NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("(%d)-->", t->data);
	}
}
int count_node(node *t)
{
	if (t != NULL)
	{
		count_node(t->lchild);
		cnt++;
		count_node(t->rchild);
	}
	return(cnt);
}

