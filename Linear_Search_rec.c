#include<stdio.h>
#include<conio.h>
#define size 100
int a[size];
int LS(int , int );
int main()
{
	int n, i, val = 0, p;
	/*	  clrscr();*/
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements in the array: \n");
	for (i = 0;i < n;i++)
		scanf("%d", &a[i]);
	printf("Enter the data to be searched: ");
	scanf("%d", &val);
	p = LS(n, val);
	if (p == -1)
		printf("Not found");
	else
		printf("Found at %d position", p + 1);
	getch();
	return 0;
}
int LS(int n, int val)
{
	if (n == 0)
		return (-1);
	else if (a[n-1] == val)
		return (n-1);
	else
		return LS((n-1), val);
}

