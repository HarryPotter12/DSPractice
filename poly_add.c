#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct poly
{
	int coef;
	int exp;
	struct poly *link;
}poly;

poly *head1, *head2, *head3, *temp1, *temp2;

poly *create1(poly *);
poly *create2(poly *);
poly *poly_add(poly *);
void display_list(poly *);

int main()
{
	char ch;
	poly *d1, *d2, *d3;
	
	head1 = NULL;
	d1 = head1;
	ch = 'y';
	printf("Enter 1st polinomial:");
	while (ch == 'y' || ch == 'y')
	{
		d1 = create1(d1);
		/*d3->link = temp1;*/
		printf("Do you want to add another term? (Y/N) ");
		fflush(stdin);
		ch = getchar();
	}
	
	printf("\nEnter 2nd polinomial:");
	head2 = NULL;
	d2 = head2;
	ch = 'y';
	while (ch == 'y' || ch == 'y')
	{
		d2 = create2(d2);
		printf("Do you want to add another term? (Y/N) ");
		fflush(stdin);
		ch = getchar();
	}
	
	printf("\nThe polynomials are: \n\n");
	display_list(head1);
	display_list(head2);
	
	/*for add*/
	
	head3 = NULL;
	d3 = head3;
	temp1 = head1;
	temp2 = head2;
	while (temp1 != NULL && temp2 != NULL)
		d3 = poly_add(d3);
	if (temp1 == NULL)
		d3->link = temp2;
	else
		d3->link = temp1;
	
	printf("After addition\n");
	display_list(head3);
	return 0;
}

poly *create1(poly *d1)
{
	poly *x;
	x = (poly *)malloc(sizeof(poly));
	printf("\nCoefficient: ");
	scanf("%d", &x->coef);
	printf("Exponent: ");
	scanf("%d", &x->exp);
	x->link = NULL;
	if (head1 == NULL)
	{
		head1 = x;
		d1 = head1;
	}
	else
	{
		d1->link = x;
		d1 = x;
	}
	return(d1);
}

poly *create2(poly *d2)
{
	poly *x;
	x = (poly *)malloc(sizeof(poly));
	printf("\nCoefficient: ");
	scanf("%d", &x->coef);
	printf("Exponent: ");
	scanf("%d", &x->exp);
	x->link = NULL;
	if (head2 == NULL)
	{
		head2 = x;
		d2 = head2;
	}
	else
	{
		d2->link = x;
		d2 = x;
	}
	return(d2);
}


poly *poly_add(poly *d3)
{
	poly *x;
	x = (poly *)malloc(sizeof ( poly));
	x->link = NULL;
	if (temp1->exp == temp2->exp)
	{
		x->coef = temp1->coef + temp2->coef;
		x->exp = temp1->exp;
		temp1 = temp1->link;
		temp2 = temp2->link;
	}
	else if (temp1->exp > temp2->exp)
	{
		x->coef = temp1->coef;
		x->exp = temp1->exp;
		temp1 = temp1->link;
	}
	else
	{
		x->coef = temp2->coef;
		x->exp = temp2->exp;
		temp2 = temp2->link;
	}
	if (head3 == NULL)
	{
		head3 = x;
		d3 = head3;
	}
	else
	{
		d3->link = x;
		d3 = x;
	}
	return(d3);
}


void display_list(poly *l)
{
	while (l != NULL)
	{
		if(l->link==NULL)
		printf("[ %dx^%d ]\n\n", l->coef, l->exp);
		else
		printf("[ %dx^%d ] + ", l->coef, l->exp);
		l = l->link;
	}
}

