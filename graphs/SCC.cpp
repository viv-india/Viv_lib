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
stack <ll> st;
void fill(vector<ll >  gr[],bool seen[] , ll i)
{seen[i]=1;
for(auto x:gr[i])
if(!seen[x])
fill(gr,seen,x);
st.push(i);
}
void dfs(vector<ll> gr[],bool seen[],ll i)
{cout<<i<<" ";
seen[i]=1;
for(auto x: gr[i])
if(!seen[x]) dfs(gr,seen,x);
}

int main()
{faster;
//freopen("input.txt","r",stdin);
ll n,m,x,y,z;
cin>>n>>m;
vector<ll >  gr[n+1],gr2[n+1];
f(i,m)
{cin>>x>>y;
gr[x].push_back(y);
gr2[y].push_back(x);
}
bool seen[n+1]={};
for(ll i=1;i<=n;i++)
if(!seen[i])
fill(gr,seen,i);
memset(seen,0,sizeof(seen));
ll k=1;
while(!st.empty())
{ll t=st.top();
st.pop();

if(!seen[t])
{cout<<"SCC  "<<k++<<" :";
dfs(gr2,seen,t);
cout<<endl;
}}

}

