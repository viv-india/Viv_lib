#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll gcd(ll a ,ll b)  {return(a==0?b:gcd(b%a,a));}
void extdgcd(ll a,ll b,ll *x,ll *y) 
{ 
 if(a==0)
{
*x=0;
*y=1;
return;
}
extdgcd(b%a,a,x,y);
ll x1=*x,y1=*y;
*x=y1-(b/a)*x1;
*y=x1;
}
int main()
{
ll x,y;
extdgcd(18,24,&x,&y);
cout<<x<<" "<<y;
}
