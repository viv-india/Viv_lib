/*************What doesn't kills you makes you stronger************************/  
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ull unsigned long long 
#define ll long long 
#define mod 10000007
#define f(i,n) for( ll (i)= 0;(i)<(n);(i)++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lp pair<ll,ll> 
#define maxn 100001
//ll gcd(ll a ,ll b)  {return(a==0?b:gcd(b%a,a))

void modinv(ll a,ll b,ll *x,ll *y)
{
if(a==0)
{*x=0;*y=1;
return;}
ll x1,y1;
modinv(b%a,a,&x1,&y1);
*y=x1;
*x=y1-(b/a)*x1;
}
ll fast(ll a)
{ll x,y;
modinv(a,mod,&x,&y);
return (x%mod+mod)%mod;
}
int main()
{faster;
ll n,r;
cin>>n>>r;
if(r>n)
cout<<-1;
else
{n=n-r;
ll f[200];
f[0]=1;
for(ll i=1;i<200;i++)
f[i]=(f[i-1]*i)%mod;
for(ll i=1;i<100;i++)
{cout<<i<<" "<<fast(i)<<" "<<(i*fast(i))%mod<<endl;

}
cout<<(((f[n+r-1]*fast(f[r-1]))%mod)*fast(f[n]))%mod<<endl;

}
}
