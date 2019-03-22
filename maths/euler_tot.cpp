/*************What doesn't kills you makes you stronger************************/  
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ld long double
#define ll long long 
#define mod 1000000007
#define f(i,n) for( ll (i)= 0;(i)<(n);(i)++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lp pair<ll,ll> 
#define maxn 1000000
//ll gcd(ll a ,ll b)  {return(a==0?b:gcd(b%a,a));}

ll tot(ll n)
{ll ans=n;
if(n%2==0) ans=(n/2); 
while(n%2==0)
{n/=2;}
ll sq=sqrt(n);
for(ll i=3;i<=sq;i+=2)
{
if(n%i==0) ans=(ans/i)*(i-1);
while(n%i==0) {n/=i;}
}
if(n>1)
ans=(ans/n)*(n-1);
return ans;}


int main()
{faster;
ll n,x;
cin>>n;
while(n--)
{cin>>x;cout<<tot(x)<<endl;}


} 

