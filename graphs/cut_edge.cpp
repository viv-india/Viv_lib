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
/********this algorithm calculates topological sort**************/
ll dis[1000];
ll p[1000];
vector<lp > ans;
ll low[1000];
void ARC(vector<ll> gr[],ll x)
{static ll time=0;
dis[x]=low[x]=++time;
for(auto i: g[x])
{
if(dis[i]==-1)
{p[i]=x;
ARC(gr,i);
low[x]=min(low[x],low[i]);
if(disc[x]<low[i]&&gr[x].size()>1&&gr[i].size()>1)
ans.push_back({x,i});
}
else if(i!=p[x])
low[x]=min(low[x],dis[i]);

}


}
int main()
{faster;
//freopen("input.txt","r",stdin);
ll Q,n,m,x,y,TT=1;
cin>>Q;
while(Q--)
{cout<<"Cas1 #"<<TT++<<"\n"
cin>>n>>m;
vector<ll > gr[n+1];
while(m--)
{cin>>x>>y;
gr[x].push_back(y);
gr[y].push_back(x);
}ans.clear();
f(i,n+1)
{dis[i]=-1;low[i]=-1;p[i]=i;
}
f(i,n)
if(disc[i+1]==-1)
ARC(gr,i+1)
if(ans.size()==0)
cout<<"No cut edges";
else
{sort(ans.begin(),ans.end());
cout<<ans.size()<<endl;
for(auto x:ans)
cout<<x.first<<" "<<x.second<<endl;


}

}

}
