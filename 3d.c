#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ***a, x, y, z, i, j, k;
	printf("Enter the no of 2D arrays: ");
	scanf("%d", &x);
	printf("Enter the no of rows: ");
	scanf("%d", &y);
	printf("Enter the no of columns: ");
	scanf("%d", &z);
	a = (int ***)malloc(x * sizeof(int **));
	for (i = 0;i < x;i++)
	{
		a[i] = (int **)malloc(y * sizeof(int *));
		for (j = 0;j < y;j++)
			a[i][j] = (int *)malloc(z * sizeof(int));
	}
	printf("\nEnter the elements: \n");
	for (i = 0;i < x;i++)
	{
		for (j = 0;j < y;j++)
		{
			for (k = 0;k < z;k++)
			{
				printf("a[%d][%d][%d] = ", i, j, k);
				scanf("%d", &a[i][j][k]);
			}
		}
	}
	printf("\nThe array is: \n");
	for (i = 0;i < x;i++)
	{
		for (j = 0;j < y;j++)
		{
			for (k = 0;k < z;k++)
				printf(" %6d ", a[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

