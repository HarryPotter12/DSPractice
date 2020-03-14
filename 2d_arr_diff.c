#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a, r, c[10], i, j;
	printf("Enter the no of rows: ");
	scanf("%d", &r);
	a = (int **)malloc(r * sizeof(int *));
	for (i = 0;i < r;i++)
	{
		printf("\nEnter the no of columns of the %d th row: ", i);
		scanf("%d", &c[i]);
		a[i] = (int*)malloc(c[i] * sizeof(int));
	}
	printf("\nEnter the elements: \n");
	for (i = 0;i < r;i++)
		for (j = 0;j < c[i];j++)
		{
			printf("a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	printf("\nThe array is: \n");
	for (i = 0;i < r;i++)
	{
		for (j = 0;j < c[i];j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

