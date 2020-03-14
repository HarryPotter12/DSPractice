#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int r, c, i, j;
	int **a;
	printf("Enter the no of rows: ");
	scanf("%d", &r);
	a = (int **)malloc(r * sizeof(int *));
	printf("Enter the no of columns: ");
	scanf("%d", &c);
	for (i = 0;i < r;i++)
	{
		a[i] = (int *)malloc(sizeof(int) * c);
	}
	printf("Enter the elements: \n");
	for (i = 0;i < r;i++)
		for (j = 0;j < c;j++)
		{
			printf("a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	printf("The array is: \n");
	for (i = 0;i < r;i++)
	{
		for (j = 0;j < c;j++)
			printf(" %6d ", a[i][j]);
		printf("\n");
	}
	return 0;
}

