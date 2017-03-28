#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int 
#define mod %1000000007

ll fast(ll a, ll n)
{
    ll ret=1;
    ll b=a;
    while(n)
    {
        if(n&1)ret=(ret*b)mod;	
        b=(b*b)mod;		
        n/=2; 			// n/=2
    }
    return (ll)ret;
}
int main()
{
ll a,b;
cin>>a>>b;
cout<<fast(a,b);
}

