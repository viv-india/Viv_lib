#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void sieve(ll n)
{bool f[n+1];
memset(f,true,sizeof(f));
for(ll i=2;i<=sqrt(n)+1;i++)
if(f[i])
{
for(ll j=2*i;j<=n;j+=i)
f[j]=false;
}
for(ll i=0;i<n;i++)
if(f[i])
cout<<i<<" ";
}
int main()
{ll x;
cin>>x;
sieve(x);

}
