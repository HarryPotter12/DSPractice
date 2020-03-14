#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int **a, **b, r1, c1;
void create_VM(int );
int main()
{
	int i, j, c = 0;
	/*clrscr();*/
	printf("\n*-*-*-*-*-*-*-*-*-* SHORTCUT REPRESENTATION OF SPARSE MATRIX *-*-*-*-*-*-*-*-*-*\n\n");
	printf("Enter the no. of rows of the SM: ");
	scanf("%d", &r1);
	printf("Enter the no. of columns of the SM: ");
	scanf("%d", &c1);
	a = (int **)malloc(r1 * sizeof(int *));
	for (i = 0;i < r1;i++)
		a[i] = (int *)malloc(c1 * sizeof(int));
	printf("\n\nEnter the elements: ");
	for (i = 0;i < r1;i++)
		for (j = 0;j < c1;j++)
			scanf("%d", &a[i][j]);
	printf("\n\nThe SM is: \n\n");
	for (i = 0;i < r1;i++)
	{
		for (j = 0;j < c1;j++)
		{
			printf("%5d", a[i][j]);
			if (a[i][j] != 0)
				c++;
		}
		printf("\n");
	}
	create_VM(c);
	return 0;
}
void create_VM(int r2)
{
	int c2 = 3, p = 1, i, j;
	r2 = r2 + 1;
	b = (int **)malloc(r2 * sizeof(int *));
	for (i = 0;i < r2;i++)
		b[i] = (int *)malloc(c2 * sizeof(int));
	for (i = 0;i < r1;i++)
	{
		for (j = 0;j < c1;j++)
			if (a[i][j] != 0)
			{
				b[p][0] = i;
				b[p][1] = j;
				b[p][2] = a[i][j];
				p++;
			}
	}
	b[0][0] = r1;
	b[0][1] = c1;
	b[0][2] = r2 - 1;
	printf("\n\nThe VM is: \n\n");
	for (i = 0;i < r2;i++)
	{
		for (j = 0;j < c2;j++)
			printf("%5d", b[i][j]);
		printf("\n");
	}
}

