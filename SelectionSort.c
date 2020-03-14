#include<stdio.h>
#include<conio.h>
#define size 100
int data[size];
int SS(int );
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
	printf("\n\nBefore Selection Sort: \n");
	display(n);
	SS(n);
	printf("\n\nAfter Selection Sort: \n");
	display(n);
	getch();
	return 0;
}
int SS(int n)
{
	int min, loc, i, j, t;
	for (i = 0;i < n-1;i++)
	{
		min = data[i];
		loc = i;
		for (j = i + 1;j < n;j++)
		{
			if (data[j] < min)
			{
				min = data[j];
				loc = j;
			}
		}
		if (loc != i)
		{
			t = data[i];
			data[i] = data[loc];
			data[loc] = t;
		}
	}
}
void display(int n)
{
	int i;
	for (i = 0;i < n;i++)
		printf("%5d", data[i]);
}

