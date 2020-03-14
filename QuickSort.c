#include<stdio.h>
#include<conio.h>
#define size 10
void quick_sort(int a[], int l, int h);
int l, h;
int main()
{
	int a[size], i, n;
	/*	  clrscr();*/
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements in the array: \n");
	for (i = 0;i < n;i++)
		scanf("%d", &a[i]);
	printf("\n\nBefore Quick Sort: \n");
	for (i = 0;i < n;i++)
		printf("%4d", a[i]);
	l = 0;
	h = n - 1;
	quick_sort(a, l, h);
	printf("\n\nAfter Quick Sort: \n");
	for (i = 0;i < n;i++)
		printf("%4d", a[i]);
	getch();
	return 0;
}
void quick_sort(int a[], int l, int h)
{
	int low, high, temp, key;
	low = l;
	high = h;
	key = a[(low+high)/2];
	do
	{
		while (key > a[low])
			low++;
		while (key < a[high])
			high--;
		if (low <= high)
		{
			temp = a[low];
			a[low++] = a[high];
			a[high--] = temp;
		}
	}
	while (low <= high);
	if (l < high)
		quick_sort(a, l, high);
	if (low < h)
		quick_sort(a, low, h);
}

