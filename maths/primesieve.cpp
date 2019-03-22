#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll > x;
void sieve(ll n)
{bitset<10000000> f;
f.set();
for(ll i=2;i<=sqrt(n)+1;i++)
if(f[i])
{
for(ll j=2*i;j<=n;j+=i)
f[j]=false;
}
for(ll i=0;i<n;i++)
if(f[i])
x.push_back(i);
}

int main()
{ll n;
cin>>n;
sieve(n);
cout<<x.size();

}
