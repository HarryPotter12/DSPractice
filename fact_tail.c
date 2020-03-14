#include<stdio.h>
#include<conio.h>
int fact(int ,int );
int main()
{
int a,f;
printf("Enter the number: ");
scanf("%d",&a);
f=fact(a,1);
printf("\nThe factorial is: %d",f);
return 0;
}
int fact(int n,int r)
{
if(n==1 || n==0)
return r;
else
return fact((n-1),(n*r));
}

