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


ll b_s(vector <ll> a,ll x,ll n)
{
ll hi=n-1,lo=0;
while(hi>=lo)
{
ll mid=lo+(hi-lo)/2;
if(A[mid]==x)
return mid;
if(A[mid]>x)
lo=mid+1;
else
hi=mid-1;
}
return  min(lo,hi);
}

int main()
{faster;
ll q;
cin>>q;
while(q--)
{ll n,k,count=0;
cin>>n>>k;
vector <ll> a(n);
f(i,n)
cin>>a[i];
sort(a.begin(),a.end());
cout<<b_s(a,k,n);
}}
