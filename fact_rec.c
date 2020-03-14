#include<stdio.h>
#include<conio.h>
int fact(int );
int main()
{
int a,f;
printf("Enter the number: ");
scanf("%d",&a);
f=fact(a);
printf("\nThe factorial is: %d",f);
return 0;
}
int fact(int n)
{
if(n==1 || n==0)
return 1;
else
return (n*fact(n-1));
}

