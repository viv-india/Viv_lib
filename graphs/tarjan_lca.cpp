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
ll p[maxn];
ll rnk[maxn];
ll find(ll x)
{if(p[x]!=x)
p[x]=find(p[x]);
return p[x];
}
void merge(ll x,ll y)
{x=find(x);
y=find(y);
if(x!=y)
{if(rnk[x]>rnk[y]) p[y]=x;
else if(rnk[x]<rnk[y]) p[x]=y;
else
{p[x]=y;
rnk[y]++;} 
}
}

LCA(ll u)
{find[u]



}

int main()
{faster;
//freopeng("input.txt","r",stdin);
ll n,m,x,y,T=1;
ll Q;
cin>>Q;
while(Q--)
{cout<<"Case "<<T++<<":\n";
cin>>n;
vector<ll> gr[n+1];
ll p[n];
p[1]=-1;
f(i,n)
{cin>>m;
f(j,m)
{cin>>x;
gr[i+1].push_back(x);
gr[x].push_back(i+1);
p[x]=i+1;
}
}
ll g;
cin>>g;
while(g--)
{cin>>x>>y;

}

}

}
