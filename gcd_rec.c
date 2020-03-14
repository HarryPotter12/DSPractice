#include<stdio.h>
#include<conio.h>
int gcd(int ,int );
int main()
{
int a,b,r;
printf("Enter the two numbers: ");
scanf("%d%d",&a,&b);
r=gcd(a,b);
printf("\nThe G.C.D. is: %d\n",r);
return 0;
}
int gcd(int m,int n)
{
if(m<=n && n%m==0)
return m;
else if(m>n)
return gcd(n,m);
else
return gcd(m,n%m);
}

