#include<stdio.h>
#include<conio.h>
#define size 100
int a[size];
int IS(int , int , int );
int main()
{
	int n, i, val = 0, p, low = 0, high;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	high = n - 1;
	printf("Enter the elements in the array: \n");
	for (i = 0;i < n;i++)
		scanf("%d", &a[i]);
	printf("Enter the data to be searched: ");
	scanf("%d", &val);
	p = IS(low, high, val);
	if (p == -1)
		printf("Not found");
	else
		printf("Found at %d th position", p + 1);
	getch();
	return 0;
}
int IS(int low, int high, int key)
{
	int mid;
	if (low > high)
		return -1;
	else
	{
		mid = low + ((key - a[low]) * (high - low)) / (a[high] - a[low]);
		if (a[mid] < key)
			return IS(mid + 1, high, key);
		else if (a[mid] > key)
			return IS(low, mid - 1, key);
		else
			return mid;
	}
}

