/*************What doesn't kills you makes you stronger************************/  
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ull unsigned long long 
#define ll long long 
#define mod 1000000007
#define f(i,n) for( ll (i)= 0;(i)<(n);(i)++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lp pair<ll,ll> 
#define maxn 100001
#define mp make_pair
#define mt make_tuple 
#define M_H priority_queue<lp ,vector<lp >,greater<lp > >
//ll gcd(ll a ,ll b)  {return(a==0?b:gcd(b%a,a))
ll l[maxn];
void lcs(string s)
{
ll n=s.size(),i=1,len=0;
l[0]=0;
while(i<n)
{
if(s[i]==s[len])
l[i++]=++len;
else if(len==0)
l[i++]=0;
else
len=l[len-1];
}
}

ll kmp(string s,string pat)
{lcs(pat);
ll i=0,j=0,n=s.size(),T=pat.size();

while(i<n)
{
{
if(s[i]==pat[j])
{i++;j++;}
else if(j==0) i++;
else j=l[j-1];
if(j==T)
{cout<<i-j<<endl;
j=l[j-1];
}
}
}
}

int main()
{faster;
freopen("input.txt","r",stdin);
ll n;
while(cin>>n)
{
string s,pat;
cin>>s>>pat;
kmp(s,pat);
cout<<endl;
}
}
