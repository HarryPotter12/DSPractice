#include<stdio.h>
#include<conio.h>

void merge(int [], int , int , int );
void msort(int [], int , int );
void display(int [], int );

int main()
{
	int arr[20];
	int n, i;
	/* clrscr();*/
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements in the array: \n");
	for (i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	printf("\n\nBefore Bubble Sort: \n");
	display(arr, n);
	msort(arr, 0, n - 1);
	printf("\n\nAfter Bubble Sort: \n");
	display(arr, n);
	getch();
	return 0;
}

void display(int arr[], int n)
{
	int i;
	printf("");
	for (i = 0;i < n;i++)
		printf("%d ", arr[i]);
}

void merge(int arr[], int low, int mid, int high)
{
	int i, j, k, l, b[20];
	l = low;
	i = low;
	j = mid + 1;
	while ((l <= mid) && (j <= high))
	{
		if (arr[l] <= arr[j])
		{
			b[i] = arr[l];
			l++;
		}
		else
		{
			b[i] = arr[j];
			j++;
		}
		i++;
	}
	if (l > mid)
	{
		for (k = j;k <= high;k++)
		{
			b[i] = arr[k];
			i++;
		}
	}
	else
	{
		for (k = l;k <= mid;k++)
		{
			b[i] = arr[k];
			i++;
		}
	}
	for (k = low;k <= high;k++)
	{
		arr[k] = b[k];
	}
}

void msort(int arr[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		msort(arr, low, mid);
		msort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

