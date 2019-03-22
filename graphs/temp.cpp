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
#define maxn 1000001
#define maxc 5000000
#define F first
#define S second
vector<ll> v;
map<ll,ll> mapb;
map<lp > wt;
vector<ll> gr[400000];
ll seen[400000];
void sieve(ll n)
{
	bitset<100000> f;
	f.set();
	for(ll i=2;i<=sqrt(n)+1;i++)
	if(f[i])
	{	
		for(ll j=2*i;j<=n;j+=i)
			f[j]=false;
	}
	for(ll i=0;i<n;i++)
		if(f[i])
			v.push_back(i);
}
void flow(ll i)
{
	while(bfs(300001));
	
}

int main() 
{
	faster;
	ll n;
	cin>>n;
	sieve(100000);
	cout<<v.size();
	ll a[n],b[n];
	f(i,n)
	{cin>>a[i];
	}
	f(i,n)
	{cin>>b[i];
	mapb[b[i]]=i;
	}
	f(i,n)
	{
	for(auto it:v)
	{
		
		if(a[i]%it==0)
		{
			
			wt[{i,it+100000}]=1;
			wt[{it+100000,i}]=0;
			gr[i].push_back(it+100000);
			gr[it+100000].push_back(i);
			
			if(mapb[a[i]])
			{
			wt[{i,mapb[a[i]]+200000}]=1;
			wt[{mapb[a[i]]+200000,i}]=0;
			gr[i].push_back(mapb[a[i]]+200000);
			gr[mapb[a[i]]+200000].push_back(i);
			}
		}
		if(b[i]%it==0)
		{
			wt[{i+200000,it+100000}]=1;
			
			gr[i+200000].push_back(it+100000);
			gr[it+100000].push_back(i+200000);
		}	
	
	}
	}
	f(i,100000)
	{
		gr[300001].push_back(i);
		gr[i].push_back(300002);
		gr[300002].push_back(i+200000);
		gr[i+200000].push_back(300002);
	}
	
	ll ans=0;
	f(i,n)
	if(flow(i))
	ans++;
	cout<<ans;
}
