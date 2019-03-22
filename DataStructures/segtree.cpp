#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod %1000000007
#define f(i,n) for( int (i)= 0;(i)<(n);(i)++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//ll gcd(ll a ,ll b)  {return(a==0?b:gcd(b%a,a));}
#define maxn 1000000
#define maxc maxn*2
ll tree[maxc];
ll orig_array[maxn];
ll lazy[maxc]={};
void built(ll node,ll start ,ll end)
{ 
     if(start==end)  
      {
	tree[node]=orig_array[start];
	return;
       }

   ll mid=(start+end)>>1;
   built(node<<1,start,mid);
   built(node<<1+1,mid+1,end);
   tree[node]=tree[node<<1]+tree[node<<1+1];
}
void lazy_update(ll node,ll start,ll end,ll val)
{
	tree[node]+=(end-start+1)*val;
	if(start!=end)
	{
	 lazy[2*node]+=val;
	 lazy[2*node+1]+=val;
	}
	lazy[node]=0;
}


ll query(ll node,ll start,ll end,ll x, ll y)
{
   if(lazy[node])
     lazy_update(node,start,end);

   if(start>=x&&end<=y)
     return tree[node];

ll mid=(start+end)/2;
if(y<=mid) return query(node*2,start,mid,x,y);
else if(x>mid) return query(node*2+1,mid+1,end,x,y);
return query(node*2,start,mid,x,mid)+query(node*2+1,mid+1,end,mid+1,y);

}
void p_update(ll node,ll start,ll end,ll val,ll ind)
{

if(start==ind&&start==ind)
{tree[node]=tree[node]+val;return;}

ll mid=(start+end)/2;
if(ind<=mid&&ind>=start)
p_update(2*node,start,mid,val,ind);
if(ind>mid&&ind<=end)
p_update(2*node+1,mid+1,end,val,ind);
tree[node]=tree[node*2]+tree[node*2+1];
}
void r_update(ll node, ll start, ll end,ll val,ll x,ll y )
{
if(lazy[node]!=0)
{lazy_update(node,start,end,lazy[node]);
}

if(x>end||y<start||start>end)
return;


if(x<=start&&y>=end)
{tree[node]+=(end-start+1)*val;
if(start!=end)
{
lazy[2*node]+=val;
lazy[2*node+1]+=val;
}
return;
}
ll mid=(start+end)/2;
r_update(2*node,start,mid,val,x,y);
r_update(2*node+1,mid+1,end,val,x,y);
tree[node]=tree[node*2]+tree[node*2+1];
}
int main()
{faster;
freopen("input.txt","r",stdin);
ll N;
cin>>N;
for(int i=0;i<N;i++)
cin>>orig_array[i];
built(1,0,N-1);
ll t,q,x,y;
cin>>q;
while(q--)
{
cin>>t>>x>>y;
if(t==1)
cout<<query(1,0,N-1,x,y)<<"\n";
else if(t==2)
p_update(1,0,N-1,x,y);
else if(t==3)
{ll v;
cin>>v;
r_update(1,0,N-1,v,x,y);
}
}for(int i=0;i<4*N;i++)
cout<<tree[i]<<" ";
}
