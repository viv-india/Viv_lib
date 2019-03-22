#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000
#define maxk 100000
ll tree[maxk];
ll A[maxn];
/*
void built(ll node ,ll start,ll end)
{
if(start==end) {tree[node]=A[start]; return;}
ll mid=(start+end)/2;
built(2*node,start,mid);
built(2*node+1,mid+1,end);
tree[node]=tree[node*2]+tree[node*2+1];
}
void update(ll node,ll start,ll end,ll idx,ll val)
{if(start==end)
{A[idx]+=val;
tree[node]+=val;
}
else
{int mid= (start+end)/2;
 if(start<=idx && idx<=mid)
  update(2*node,start ,mid,idx,val);
 else
  update(2*node+1,mid+1,end,idx,val);
 tree[node]=tree[node*2]+tree[node*2+1];
}
}
ll query(ll node,ll start,ll end,ll l, ll r)
{
if(r<start || end<l)
return 0;
if(l<=start && end<=r)
return tree[node];
int mid=(start+end)/2;
return (query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r));}*/
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];
void built() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];}

void update(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}


int main()
{int n;
cout<<"enter number of elements\n";
cin>>n;
for(int i=0;i<n;i++)
cin>>t[i+n];
built();
int q;
cout<<"Enter number of operations :\n";
cin>>q;
while(q--)
{
char p;
cout<<"enter q for query and u for update\n";
cin>>p;
ll x,y;
cin>>x>>y;
if(p=='u')
update(x,y);
if(p=='q')
cout<<query(x,y);
}
}
