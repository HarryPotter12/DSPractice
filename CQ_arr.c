#include<stdio.h>
#include<conio.h>

#define size 10
int q[size], front = 0, rear = 0;

void insert(int );
int del();
void display();

int main()
{
	int i, val, p;
	char j;
	do
	{
		printf("1.display\n2.insertion\n3.deletion\n");
		printf("\nEnter the choice: ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			display();
			break;
		case 2:
			if ((rear+1)%size==front)
				printf("\nThe queue is full");
			else
			{
				printf("\nEnter the value to be entered: ");
				scanf("%d", &val);
				insert(val);
				display();
			}
			break;
		case 3:
			if ((rear+1)%size==front)
				printf("\nThe queue is empty.");
			else
			{
				p = del();
				printf("\nThe item deleted is: %d", p);
				display();
			}
			break;
		default:
			printf("\nYou have entered a wrong choice");
		}
		printf("\nWant to do again? (y/n) ");
		fflush(stdin);
		scanf("%c", &j);
	}
	while (j == 'y' || j == 'Y');
	getch();
	return 0;
}

void insert(int val)
{
	q[rear++] = val;
	rear%=size;
}

int del()
{
	int p;
	p=q[front++];
	front%=size;
	return p;
}

void display()
{
	int i;
	printf("\nThe queue is: \n");
	for (i = front;i < rear;i++)
		printf("%d\t", q[i]);
}

