/*
	Boundary is a myth  
	
	Code by:Vivek Singh
	College: NIT,Patna
	Batch: 2K15
	Handles:viv_nitp(codechef) & Steady_Bunny(hackerrank,codeforces)
									
*/
#include<bits/stdc++.h>
using namespace std;
#define ld long double    
#define ull unsigned long long     
#define ll  long long
#define mod 1000000007    
#define f(i,n) for( ll (i)= 0;(i)<(n);(i)++)    
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)   
#define lp pair<ll,ll> 
#define mp make_pair
#define mt make_tuple
#define M_H priority_queue<ll ,vector<ll >,greater<ll > >
#define red 1;
#define black 0;
#define rep(i,j,n) for( ll (i)= j;(i)<(n);(i)++)
#define maxn 100001
#define maxc 5000000
#define F first
#define S second
#define NUM 314159
vector<ll> V[100001];
ll timer=0,n,ele=0;
ll dp[100001],low[100001],start[100001],val[1000001];
bool app[100001];
ll seen[1000001];
bool seen2[1000001];
ll st,ini,ma;

inline void dfs(ll node){
    bool flag=0;
    ll child=0;
    ele++;
    seen[node]=1;
    start[node] = ++timer;
    low[node] = start[node];
    for(auto it:V[node])
    {
        if(!start[it])
        {
            dfs(it);
            ++child;
            low[node] = min(low[node],low[it]);
            if (low[it] >= start[node])
                flag = true;
        }
        else
            low[node] = min(low[node],start[it]);
    }
    if((node==st && child > 1) || (node != st && flag))
        app[node]=1; 
}
void ddfs(ll i)
{
	seen2[i]=1;
	for(auto it:V[i])
		if(seen2[it]==0)
			{ddfs(it);
			if(app[it]==0&&app[i]==0)
			merge(it,i);
			}
}
ll count_ele(ll node)
{
	ll ans=0;
	vector<ll> cc;
	ll k=0,x;
	for(auto it: V[node])
		{
			
		        if(seen[find(it)]!=ini)
		        {
		        	seen[find(it)]=ini;
		        	cc.push_back(val[x]);
			}
		}

		ll ttt=0;
		f(i,cc.size())
			ans+=cc[i]*(n-1-cc[i]);
		f(i,cc.size())
			ttt+=cc[i]*(ma-1-cc[i]);
		ans-=ttt/2;
		return ans;
}

int main()
{	faster;
	ll m,q,x,y;
	cin>>n>>m;
	f(i,n+1)
	{
		p[i]=i;
		rnk[i]=0;
		val[i]=1;
	}
	f(i,m)
	{
		cin>>x>>y;
		V[y].push_back(x);
		V[x].push_back(y);
	}
	ll ans=0;
	rep(i,1,n+1)
	if(seen[i]==0)
	{
		ele=0;
		st=i;
		dfs(i);
	}
	rep(i,1,n+1)
	cout<<low[i]<<" "<<
	
	rep(i,1,n+1)
	if(seen2[i]==0)
	{	
		ddfs(i);
	}
	ans=ans/2;
	cin>>q;
	rep(i,1,n+1)
	cout<<val[i]<< " !"<<endl;
	f(i,q)
	{
		cin>>x;
		if(app[x])
		{
			f(i,n+1)
				seen[i]=0;
				
			ini=x;
			ma=val[find(x)];
			cout<<ans-(val[find(x)]*(n-val[find(x)]))+count_ele(x)<<"\n";
		}
		else
			cout<<ans-(val[find(x)]*(n-val[find(x)]))<<"\n";	
	}	
}	 	
