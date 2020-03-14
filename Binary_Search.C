#include<stdio.h>
#include<conio.h>
#define size 100
int data[size];
int BS(int , int );
int main()
{
	int n, i, val = 0, p;
/*	  clrscr();*/
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements in the array (in ascending order): \n");
	for (i = 0;i < n;i++)
		scanf("%d", &data[i]);
	printf("Enter the data to be searched: ");
	scanf("%d", &val);
	p = BS(val, n);
	if (p == -1)
		printf("Not found");
	else
		printf("Found at %d th  position", p + 1);
	getch();
	return 0;
}
int BS(int item, int n)
{
	int beg, end, mid;
	beg = 0;
	end = n - 1;
	mid = (beg + end) / 2;
	while ((data[mid] != item) && (beg <= end))
	{
		if (data[mid] > item)
			end = mid - 1;
		else
			beg = mid + 1;
		mid = (beg + end) / 2;
	}
	if (data[mid] != item)
		return -1;
	else
		return mid;
}

