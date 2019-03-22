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
#define mp make_pair
#define mt make_tuple
#define M_H priority_queue<lp ,vector<lp >,greater<lp > >
#define red 1;
#define black 0;
#define rep(i,j,n) for( ll (i)= j;(i)<(n);(i)++)
#define maxn 1000000
#define maxc 5000000
ll source,sink;
vector<ll> gr[1000000];
ll d[1000000];

struct edge
{
	ll b;//destination or y from (x to y)
	ll cap;//capacity
	ll flow;//flow
};

edge e[1000000];//edge array
ll ed_sz=0;//size of edge array

void add_edge(ll x,ll y,ll c)
{
    e[ed_sz]={y,c,0};//new edge inserted
    gr[x].push_back(ed_sz++);//edge added in graph
	e[ed_sz]={x,c,c};//back edge added
	gr[y].push_back(ed_sz++);//back edge added
}

bool bfs()//finds augumented path
{
	queue<ll> q;
	q.push(source);
	memset(d,-1,sizeof(d));//flush previous values 
	d[source]=0;//given level zero to source
	while((!q.empty())&&d[sink]==-1)//untill sink is not found and there is a possiblity
	{
		ll v=q.front();
		q.pop();
		
		for(auto it:gr[v])
		{
			ll to=e[it].b;
			if(d[to]==-1 && e[it].flow<e[it].cap )
			{
				d[to]=d[v]+1;// declare "to" on next level
				q.push(to);
			}
			
		}
	}
	return (d[sink]!=-1);
}

ll dfs(ll v,ll flow)//find flow
{
	if(v==sink||flow==0)//if flow diminishes or sink is reached return back
		 return flow;
	
	for(auto it:gr[v])
	{
		ll to=e[it].b;
		if(d[to]!=d[v]+1) continue;// if it is noton the next level

		if(ll push=dfs(to,min(flow,e[it].cap-e[it].flow)))//if path found
		{
			e[it].flow+=push;
			e[ it^1 ].flow-=push;
			return push;
		}
	}
	return 0;
}
ll findflow()
{
	ll ans=0;
	while(bfs())// if there is an augumenting path
	{
		while(ll fl=dfs(source,LONG_MAX))//untill we are able to find a +ve flow
		ans+=fl;// kepp incrementing flow
	}
	return ans;
}

int main() 
{
	faster;
	ll Q,n,m,k,x,y;
	cin>>Q;
	while(Q--)
	{
		ed_sz=0;
		cin>>n>>k>>m;
		for(ll i=0;i<500;i++)
		gr[i].clear();
		
		while(m--)
		{
			cin>>x>>y;
			x--;
			y--;
			add_edge(x,y+100,1);
			add_edge(y,x+100,1);
			
		}
		f(i,n)
		{
		add_edge(333,i,k);
		add_edge(i+100,444,1);
		
		}
		source=333;
		sink=444;
		cout<<findflow()<<endl;
	}
}
