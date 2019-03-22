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

ll T_s(ll l,ll r,ll x)
{
if(l<=r)
{
ll mid1=l+(r-l)/3,mid2=r-(r-l)/3;
if(a[mid1]==x) return mid1;
if(a[mid2]==x) return mid2;
if(x<a[mid1])
return T_s(l,mid1-1,x);
else if(x>mid2)
return T_s(mid2+1,r,x);
else
return T_s(mid1+1,mid2-1,x);

}
return -1;
}

int main()
{faster;
ll n,x;
cin>>n;
f(i,n)
cin>>a[i];
cin>>x;
ll res=T_s(0,n-1,x);
if(res!=-1)
cout<<res;
else
cout<<"Not found";
}
