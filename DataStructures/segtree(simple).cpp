/*************What doesn't kill you makes you stronger************************/  
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
#define M_H priority_queue<ll ,vector<ll >,greater<ll > >
#define red 1;
#define black 0;
#define rep(i,j,n) for( ll (i)= j;(i)<(n);(i)++)
#define maxn 100000
#define maxc 5000000
#define F first
#define S second
ll tree[1000000],a[1000000];

ll merge(ll x,ll y) {return x+y;}
void mktree(ll node,ll s,ll e)
{
	if(s==e){tree[node]=a[s];return;}
	mktree(2*node,s,(s+e)/2);
	mktree(2*node+1,(s+e)/2+1,e);
	tree[node]=merge(tree[2*node],tree[2*node+1]);
}
void upd(ll node,ll s,ll e,ll val,ll idx)
{

	if(e<s||e<idx||idx<s) return ;
	if(s==e)
	{tree[node]=val;return;}
	
	if(idx<=(s+e)/2)
	 upd(2*node,s,(s+e)/2,val,idx);
	else
	 upd(2*node+1,(s+e)/2+1,e,val,idx);
	tree[node]=merge(tree[node*2],tree[node*2+1]);
}

ll qry(ll node,ll s,ll e,ll l,ll r)
{
	if(e<s||l>e||r<s) return 0;
	if(s>=l&&r>=e) return tree[node];
	return qry(2*node,s,(s+e)/2,l,r)+qry(2*node+1,(s+e)/2+1,e,l,r);
}
int main() 
{
	faster;
	ll n,x,y,t;
	cin>>n;
	f(i,n)
	cin>>a[i+1];
	mktree(1,1,n);
	rep(i,1,2*n)
	cout<<tree[i]<<" ";
	cout<<endl;
	while(1)
	{
	
	cin>>t>>x>>y;
	if(t==1)
	cout<<qry(1,1,n,x,y)<<endl;
	else
	upd(1,1,n,y,x);
	}
}

