#include<stdio.h>
#include<conio.h>
#define size 100
int data[size];
int BS(int , int , int );
int main()
{
	int n, i, beg = 0, end, val = 0, p;
	/*	  clrscr();*/
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements in the array (in ascending order): \n");
	for (i = 0;i < n;i++)
		scanf("%d", &data[i]);
	printf("Enter the data to be searched: ");
	scanf("%d", &val);
	end = n - 1;
	p = BS(beg, end, val);
	if (p == -1)
		printf("Not found");
	else
		printf("Found at %d th  position", p + 1);
	getch();
	return 0;
}
int BS(int beg, int end, int item)
{
	int mid;
	if (beg > end)
		return -1;
	else
	{
		mid = (beg + end) / 2;
		if (data[mid] == item)
			return mid;
		else if (data[mid] > item)
				return BS(beg, mid - 1, item);
			else
				return BS(mid + 1, end, item);
	}
}

