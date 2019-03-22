/*STEADY_BUNNY
CHEAT_SHEET*/
#include<bits/stdc++.h>
using namespace std;
#define mod %1000000007
#define faster ios_base::sync_with_stdio(false)
#define tiee cin.tie(0); cout.tie(0)
#define ms make_pair
#define ms make_pair
#define pq priority_queue<pa, vector<pa>,greater<pa> >
#define ll long long 
#define pa pair<int,int>;
#define it1 ::iterator 
/**************************MAX-FLOW*********************************/
map<ll,ll> m;// map to store parents
ll flow;
ll v[1000][1000];
ll n,s,g;
bool bfs()
{m.clear();
bool seen[n+1]={};
queue<ll> q;
q.push(s);
ll i;
while(!q.empty())
  { 
  i=q.front();q.pop(); 
  for(ll j=1;j<=n;j++)
    if(v[i][j]>0&&!seen[j])
	{m[j]=i;
	seen[j]=1;
	q.push(j);
	if(j==g)//reached sink
		{q=queue <ll> ();
		return 0;
		}
	}
  }
return 1;//never reached sink
}	

int main()
{
faster ;
tiee;
ll M;
cin>>n>>M;//no of vertices 
for(int i=1;i<n;i++)
for(int j=1;j<n;j++)
v[i][j]=-1;
for(int i=0;i<M;i++)
{
	ll x,y,wt;
	cin>>x>>y>>wt;
	v[x][y]=wt;
	v[y][x]=0;
}
cin>>s;//source
cin>>g;//sink
ll maxflow=0;
ll x=g;
while(1)
{	x=g;
	flow=10000000;
	if(bfs()) break;
	while(m.find(x)!=m.end())
	{	flow=min(flow,v[m[x]][x]);
		x=m[x];
	}
	x=g;
	maxflow+=flow;
	while(m.find(x)!=m.end())
	{	v[m[x]][x]-=flow;
		v[x][m[x]]+=flow;//add flow in anti parallel direction
		x=m[x];
	}
}
cout<<maxflow;

}
