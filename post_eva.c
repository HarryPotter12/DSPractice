/**********            EVALUATE  POSTFIX  EXPREATION            *************/

#include<stdio.h>
#include<conio.h>
#include<math.h>

float stack[10];
int top=-1;
void push(char);
float pop();
float eval(char[],float[]);

int main()
{
	int i=0;
	char suffix[20];
	float value[20],result;
/*	  clrscr();*/
	printf("PUT THE PARAMETERS POSTFIX EXPREATION : ");
	gets(suffix);
	while(suffix[i]!='\0')
	{
		if(isalpha(suffix[i]))
		{
			fflush(stdin);
			printf("\nPUT THE VALUE OF %c=",suffix[i]);
			scanf("%f",&value[i]);
		}
		i++;
	}
	result=eval(suffix,value);
	printf("\nTHE RESULT OF %s=%f",suffix,result);
	getch();
	return(0);
}

float eval(char suffix[],float data[])
{
	int i=0;
	float op1,op2,res;
	char ch;
	while(suffix[i]!='\0')
	{
		ch=suffix[i];
		if(isalpha(suffix[i]))
		{
			push(data[i]);
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '+':
					push(op1+op2);
					break;
				case '-':
					push(op1-op2);
					break;
				case '*':
					push(op1*op2);
					break;
				case '/':
					push(op1/op2);
					break;
				case '^':
				case '$':
					push(pow(op1,op2));
					break;
			}
		}
		i++;
	}
	res=pop();
	return(res);
}

void push(char num)
{
	top=top+1;
	stack[top]=num;
}

float pop()
{
	float num;
	num=stack[top];
	top--;
	return(num);
}

