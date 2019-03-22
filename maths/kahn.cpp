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
/********this algorithm calculates topological sort ************/

int main()
{faster;
//freopen("input.txt","r",stdin);
ll n,m,x,y;
cin>>n>>m;
ll ind[n+1]={};
vector<ll> gr[n+1];
while(m--)
{cin>>x>>y;
gr[x].push_back(y);
ind[y]++;
}
set <ll> q;
f(i,n)
if(ind[i+1]==0)
q.insert(i+1);

ll cnt=0;
vector<ll > ans; 
while(!q.empty())
{ll i=*q.begin();q.erase(q.begin());
ans.push_back(i);
for(auto x:gr[i])
{ind[x]--;
if(ind[x]==0)
q.insert(x);
}
cnt++;
}
if(cnt!=n)
cout<<"Sandro fails.";
else
for(auto x:ans)
cout<<x<<" ";
}
