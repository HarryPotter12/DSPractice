#include<stdio.h>
#include<conio.h>
#define size 100
int a[size];
int IS(int , int );
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
	p = IS(val, n);
	if (p == -1)
		printf("Not found");
	else
		printf("Found at %d th position", p + 1);
	getch();
	return 0;
}
int IS(int key, int n)
{
	int low = 0, high = n - 1, mid;
	while (a[low] < key && a[high] >= key)
	{
		mid = low + ((key - a[low]) * (high - low)) / (a[high] - a[low]);
		if (a[mid] < key)
			low = mid + 1;
		else if (a[mid] > key)
			high = mid - 1;
		else
			return mid;
	}
	if (a[low] == key)
		return low;
	else
		return -1;
}

