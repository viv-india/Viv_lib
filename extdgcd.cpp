#include<bits/stdc++.h>
using namespace std;
/*This program implements extended version of gcd
i.e. it calaulates x and y such that
ax+by=gcd(a,b)
now at the end case when a=0 and b=gcd :-> we have x=0 and y=1
x=y1-b/a*x1;
y=x1;
*/
int gcdextd(int a,int b,int *x1,int *y1)
{
if(a==0)
{
*x1=0;
*y1=1;
return b;
}
int x,y;
int gcd=gcdextd(b%a,a,&x,&y);
*x1=y-b/a*x;
*y1=x;
return gcd;
}
int main()
{

int a=15,b=25,x,y;
cout<<gcdextd(b,a,&x,&y);
cout<<x<<" "<<y;
}
