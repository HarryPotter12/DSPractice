#include<stdio.h>
#include<conio.h>
#define size 100
int a[size];
void shellsort(int [], int );
void display(int );
int main()
{
	int n, i;
	/*	  clrscr();*/
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements in the array: \n");
	for (i = 0;i < n;i++)
		scanf("%d", &a[i]);
	printf("\n\nBefore Shell Sort: \n");
	display(n);
	shellsort(a, n);
	printf("\n\nAfter Shell Sort: \n");
	display(n);
	getch();
	return 0;
}
void display(int n)
{
	int i;
	for (i = 0;i < n;i++)
		printf("%5d", a[i]);
}
void shellsort(int a[], int n)
{
	int j, i, k, m, mid;
	for (m = n / 2;m > 0;m /= 2)
	{
		for (j = m;j < n;j++)
		{
			for (i = j - m;i >= 0;i -= m)
			{
				if (a[i+m] >= a[i])
					break;
				else
				{
					mid = a[i];
					a[i] = a[i+m];
					a[i+m] = mid;
				}
			}
		}
	}
}

