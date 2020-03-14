#include<stdio.h>
#define SIZE 15
void radixsort(int *, int );
void print(int *, int );
int main()
{
	int arr[SIZE];
	int i, n;
	printf("Enter total number of elements (n < %d) : ", SIZE);
	scanf("%d", &n);
	printf("Enter %d Elements : ", n);
	for (i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	printf("\nBefore Radix Sort :  ");
	print(&arr[0], n);
	printf("\n");
	radixsort(&arr[0], n);
	printf("\n\nAfter Radix Sort :  ");
	print(&arr[0], n);
	printf("\n");
	return 0;
}

void print(int *a, int n)
{
	int i;
	for (i = 0;i < n;i++)
		printf("\t%5d", a[i]);
}
void radixsort(int *a, int n)
{
	int i, b[SIZE], m = 0, exp = 1;
	for (i = 0;i < n;i++)
	{
		if (a[i] > m)
			m = a[i];
	}
	while (m / exp > 0)
	{
		int bucket[10] = {0};
		for (i = 0;i < n;i++)
			bucket[a[i] / exp % 10]++;
		for (i = 1;i < 10;i++)
			bucket[i] += bucket[i-1];
		for (i = n - 1;i >= 0;i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (i = 0;i < n;i++)
			a[i] = b[i];
		exp *= 10;
		printf("\nPASS : \t\t");
		print(a, n);
	}
}

