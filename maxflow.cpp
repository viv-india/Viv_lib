/*STEADY_BUNNY
CHEAT_SHEET*/
#include<bits/stdc++.h>
using namespace std;
#define mod %1000000007
#define faster ios_base::sync_with_stdio(false)
#define tiee cin.tie(0); cout.tie(0)
#define ms make_pair
#define setr(a) memset(a,-1,sizeof(a))
#define pq priority_queue<pa, vector<pa>,greater<pa> >
#define ll long long 
#define pa pair<int,int>;
#define it1 ::iterator 
/**************************MAX-FLOW*********************************/
map<ll,ll> m;
ll flow;
bool f;

ll v[1000][1000];
ll n,s,g;
void bfs()
{m.clear();
bool seen[n+1]={};
queue<ll> q;
q.push(s);
ll i;
while(!q.empty())
{i=q.front();q.pop();
for(ll j=1;j<=n;j++)
if(v[i][j]>0&&!seen[j])
{m[j]=i;
seen[j]=1;

q.push(j);
if(j==g)
{q=queue <ll> ();
return;
}
}


}
f=0;
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
cin>>s;//starting index
cin>>g;//sink
ll maxflow=0;
f=1;
ll x=g;
while(f)
{x=g;
//cout<<f;
flow=10000000;
bfs();
if(f==0)
break;
while(m.find(x)!=m.end())
{flow=min(flow,v[m[x]][x]);
x=m[x];
}
x=g;
maxflow+=flow;
while(m.find(x)!=m.end())
{v[m[x]][x]-=flow;
v[x][m[x]]+=flow;
x=m[x];}
//cout<<maxflow<<"|\n";
}
cout<<maxflow;

}
