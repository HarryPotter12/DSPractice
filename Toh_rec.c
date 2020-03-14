#include<stdio.h>
#include<conio.h>
int move = 0;
void toh(int , char , char , char );
int main()
{
	int n;
	printf("Enter the no. of discs: ");
	scanf("%d", &n);
	toh(n, 'a', 'b', 'c');
	printf("\n\nTotal no. of moves: %d\n", move);
	return 0;
}
void toh(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("\nMove disc 1 from peg %c to peg %c", A, C);
		move++;
	}
	else
	{
		toh(n - 1, A, C, B);
		toh(1, A, B, C);
		toh(n - 1, B, A, C);
	}
}

