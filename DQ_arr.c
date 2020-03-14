#include<stdio.h>
#include<conio.h>

#define size 10
int dq[size], front = 0, rear = -1;

void insert_front(int );
void insert_rear(int );
int del_front();
int del_rear();
void display();

int main()
{
	int i, val, p;
	char j;
	do
	{
		printf("1.display\n2.insertion at front\n3.insertion at end\n4.deletion from front\n5.deletion from end\n");
		printf("\nEnter the choice: ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			display();
			break;
		case 2:
			if (front == 0)
				printf("\nQueue overflow.");
			else
			{
				printf("\nEnter the value to be entered: ");
				scanf("%d", &val);
				insert_front(val);
				display();
			}
			break;
		case 3:
			if (rear == (size-1))
				printf("\nQueue overflow.");
			else
			{
				printf("\nEnter the value to be entered: ");
				scanf("%d", &val);
				insert_rear(val);
				display();
			}
			break;
		case 4:
			if (front == rear)
				printf("\nQueue underflow.");
			else
			{
				p = del_front();
				printf("\nThe item deleted is: %d", p);
				display();
			}
			break;
		case 5:
			if (front > rear)
				printf("\nQueue underflow.");
			else
			{
				p=del_rear();
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

void insert_front(int val)
{
	dq[--front] = val;
}

void insert_rear(int val)
{
	dq[++rear] = val;
}

int del_front()
{
	int no;
	no=dq[front];
	front++;
	return no;
}

int del_rear()
{
	int no;
	no=dq[rear];
	rear--;
	return no;
}

void display()
{
	int i;
	if(front<=rear)
	{
	printf("\nThe queue is: \n");
	for (i = front;i <= rear;i++)
		printf("%d\t", dq[i]);
	}
	else
	printf("Queue empty");
}

