#include<stdio.h>
#include<conio.h>
#define size 100
int data[size];
int BS(int );
void display(int );
int main()
{
	int n, i;
	/*	  clrscr();*/
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements in the array: \n");
	for (i = 0;i < n;i++)
		scanf("%d", &data[i]);
	printf("\n\nBefore Bubble Sort: \n");
	display(n);
	BS(n);
	printf("\n\nAfter Bubble Sort: \n");
	display(n);
	getch();
	return 0;
}
int BS(int n)
{
	int i, j, t;
	for (i = 0;i < n - 1;i++)
	{
		for (j = 0;j < n - i - 1;j++)
		{
			if (data[j] > data[j+1])
			{
				t = data[j];
				data[j] = data[j+1];
				data[j+1] = t;
			}
			/*printf("\ni=%d\tj=%d\n", i, j);
			display(n);*/
		}
	}
}
void display(int n)
{
	int i;
	for (i = 0;i < n;i++)
		printf("%5d", data[i]);
}

