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
ll a[maxn];
ll fun(ll x)
{return 2*x*x-12*x+7;}


ll T_s(ll l,ll r)
{
if(l<=r)
{
ll mid1=l+(r-l)/3,mid2=r-(r-l)/3;

if(fun(mid1)==fun(mid2)) return T_s(mid1,mid2);
else if(fun(mid1)<fun(mid2))
return T_s(mid1,r);
else
return T_s(l,mid1);
}
return l;
}

int main()
{faster;
ll n;
cin>>n;
while(n--)
{
ll a,b;
cin>>a>>b;
cout<<T_s(a,b)<<endl;

}
}
