/**********        CONVERTION  INFIX  TO  POSTFIX  FORM          ***********/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

char stack[50];
int top=-1;
void in_to_post(char infix[]);
void push(char);
char pop();
int preced(char);

int main()
{
	char infix[50];
/*	  clrscr();*/
	printf("\nEnter the infix expression: ");
	gets(infix);
	in_to_post(infix);
	getch();
	return 0;
}

void push(char symb)
{
	if(top>=49)
	{
		printf("\nStack overflow");
		return;
	}
	else
	{
		top=top+1;
		stack[top]=symb;
	}
}

char pop()
{
	char iteam;
	if(top==-1)
	{
		printf("\nStack empty");
		return(0);
	}
	else
	{
		iteam=stack[top];
		top--;
		return(iteam);
	}
}

int isp(char ch)
{
	if(ch=='^')
		return(3);
	else if(ch=='/' || ch=='*')
		return 2;
	else if(ch=='+' || ch=='-')
		return 1;
	else
		return 0;
}
int icp(char ch)
{
	if(ch=='^')
		return 4;
	else if(ch=='/' || ch=='*')
		return 2;
	else if(ch=='+' || ch=='-')
		return 1;
	else
		return 4;
}

void in_to_post(char infix[])
{
	int len;
	static int index=0,pos=0;
	char symb,temp;
	char postfix[40];
	len=strlen(infix);
	while(index<len)
	{
		symb=infix[index];
		switch(symb)
		{
			case '(':
				push(symb);
				break;
			case ')':
				temp=pop();
				while(temp!='(')
				{
					postfix[pos]=temp;
					pos++;
					temp=pop();
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			/*case '$':*/
				while(isp(stack[top])>=icp(symb))
				{
					temp=pop();
					postfix[pos]=temp;
					pos++;
				}
				push(symb);
				break;
			default:
				postfix[pos++]=symb;
				break;
		}
		index++;
	}
	while(top>=0)
	{
		temp=pop();
		postfix[pos++]=temp;
	}
	postfix[pos++]='\0';
	printf("\nThe postfix expression is: ");	
	puts(postfix);
	return;
}

