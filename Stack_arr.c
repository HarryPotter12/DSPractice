#include<stdio.h>
#include<conio.h>
#define SIZE 10

int top = -1, stack[SIZE];

void push(int);
int pop();
void display();

int main()
{
	int ch, y, num;
	char j;
	/*clrscr();*/
	printf("\n*-*-*-*-*-*-*-*-*-* STACK USING ARRAY *-*-*-*-*-*-*-*-*-*\n\n");
	do
	{
		printf("\n1.Push\n2.Pop\n3.Display\n\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nEnter the value to be pushed: ");
			scanf("%d", &num);
			push(num);
			break;
		case 2:
			y = pop();
			break;
		case 3:
			display();
			break;
		default:
			printf("\nYou have entered a wrong chice.");
		}
		printf("\nWant to do again? (y/n) ");
		fflush(stdin);
		scanf("%c", &j);
	}
	while (j == 'y' || j == 'Y');
	getch();
	return 0;
}

void push(int x)
{
	if (top == SIZE-1)
		printf("\nStack overflow.\n");
	else
		stack[++top] = x;
}

int pop()
{
	if (top == -1)
	{
		printf("\nStack underflow.\n");
		return -1;
	}
	else
	{
	printf("\nThe popped element is = %d", stack[top--]);
	return stack[top];
	}
}

void display()
{
	int i;
	printf("\nThe present stack is: \n");
	for (i = top;i >= 0;i--)
		printf("\n\t\t | %5d | \n\t\t |       | ", stack[i]);
	printf("\n\t\t |_______|\n\n");
}

