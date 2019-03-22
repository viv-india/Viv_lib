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
ll par[10001];
ll rnk[10001];

ll find(ll x)
{if(par[x]!=x) par[x]=find(par[x]);
return par[x];
}
void merge(ll x, ll y)
{x=find(x);
y=find(y);
if(x!=y)
{if(rnk[x]>rnk[y]) {par[y]=x; }
else if(rnk[y]>rnk[x]){par[x]=y;}
else
{par[y]=x;
rnk[x]++;
}
}
}
ll krus(vector <pair<ll,lp > > gr,ll n)
{sort(gr.begin(),gr.end());
ll ans=0;
f(i,gr.size())
if(find(gr[i].second.first)!=find(gr[i].second.second))
{merge(gr[i].second.first,gr[i].second.second);
ans+=gr[i].first;
}
return ans;
}

int main()
{faster;
//create graph yourself man!!! 
}
