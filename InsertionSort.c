#include<stdio.h>
#include<conio.h>
#define size 100
int data[size];
void IS(int );
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
	printf("\n\nBefore Insertion Sort: \n");
	display(n);
	IS(n);
	printf("\n\nAfter Insertion Sort: \n");
	display(n);
	getch();
	return 0;
}
void IS(int n)
{
	int i, k, y;
	for (i = 1;i < n;i++)
	{
		y = data[i];
		for (k = i - 1;k >= 0 && y < data[k];k--)
			data[k+1] = data[k];
		data[k+1] = y;
	}
}
void display(int n)
{
	int i;
	for (i = 0;i < n;i++)
		printf("%5d", data[i]);
}

