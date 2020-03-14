#include<stdio.h>
#include<stdlib.h>
int vm1[100][3], vm2[100][3], vm3[199][3], r1, r2;
void add_VM();
void check_VM();
int main()
{
	int i, j;
	printf("Enter the no. of rows of 1st VM: ");
	scanf("%d", &r1);
	printf("\nEnter the no. of rows of 2nd VM: ");
	scanf("%d", &r2);
	printf("\n\nEnter the elements of 1st VM: ");
	for (i = 0;i < r1;i++)
		for (j = 0;j < 3;j++)
			scanf("%d", &vm1[i][j]);
	printf("\n\nEnter the elements of 2nd VM: ");
	for (i = 0;i < r2;i++)
		for (j = 0;j < 3;j++)
			scanf("%d", &vm2[i][j]);
	printf("\n\nThe 1st VM is: \n");
	for (i = 0;i < r1;i++)
	{
		for (j = 0;j < 3;j++)
			printf("%5d", vm1[i][j]);
		printf("\n");
	}
	printf("\n\nThe 2nd VM is: \n");
	for (i = 0;i < r2;i++)
	{
		for (j = 0;j < 3;j++)
			printf("%5d", vm2[i][j]);
		printf("\n");
	}
	check_VM();
	return 0;
}
void check_VM()
{
	if (vm1[0][0] == vm2[0][0] && vm1[0][1] == vm2[0][1])
		add_VM();
	else
	{
		printf("\n\nAddition not possible.\n\n");
		exit(0);
	}
}
void add_VM()
{
	int i, m, j, k = 1, p = 1;
	for (i = 1;i < r1;i++)
	{
		for (j = 1;j < r2;j++)
			if (vm1[i][0] == vm2[j][0] && vm1[i][1] == vm2[j][1])
			{
				vm3[k][0] = vm1[i][0];
				vm3[k][1] = vm1[i][1];
				vm3[k][2] = vm1[i][2] + vm2[j][2];
				k++;
			}
	}
	m = k;
	for (i = 1;i < r1;i++)
	{
		for (j = 1;j < m;j++)
			if (vm1[i][0] == vm3[j][0] && vm1[i][1] == vm3[j][1])
			{
				p++;
				break;
			}
		if (p == 1)
		{
			vm3[k][0] = vm1[i][0];
			vm3[k][1] = vm1[i][1];
			vm3[k][2] = vm1[i][2];
			k++;
		}
		p = 1;
	}
	m = k;
	for (i = 1;i < r2;i++)
	{
		for (j = 1;j < m;j++)
			if (vm2[i][0] == vm3[j][0] && vm2[i][1] == vm3[j][1])
			{
				p++;
				break;
			}
		if (p == 1)
		{
			vm3[k][0] = vm2[i][0];
			vm3[k][1] = vm2[i][1];
			vm3[k][2] = vm2[i][2];
			k++;
		}
		p = 1;
	}
	vm3[0][0] = vm1[0][0];
	vm3[0][1] = vm1[0][1];
	vm3[0][2] = k - 1;
	printf("\n\nThe result is: \n\n");
	for (i = 0;i < k;i++)
	{
		for (j = 0;j < 3;j++)
			printf("%5d", vm3[i][j]);
		printf("\n");
	}
}

