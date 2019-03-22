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
ll low[maxn];//time its oldest ancesstor was discovered
ll disc[maxn];//discovery time
ll p[maxn];
bool ap[maxn];
void ARC(vector<ll> gr[], ll x)
{static int tme=0;
low[x]=disc[x]=++tme;
ll child=0;
//cout<<x<<" ";
for(auto i: gr[x])
{
if(disc[i]==-1)//found for the first time
{child++;
p[i]=x;

ARC(gr,i);//DFS
low[x]=min(low[x],low[i]);//finding oldest ancestor
if(child>1&&p[x]==-1)
ap[x]=1;//either a root with >1 child 
if(p[x]!=-1&&low[i]>=disc[x])
ap[x]=1;

}
else if(i!=p[x])// if already found
low[x]=min(disc[i],low[x]);}}


int main()
{faster;
//freopen("input.txt","r",stdin);
ll n,m,x,y;
while(cin>>n>>m)
{if(n==0&&m==0) break;
vector<ll> gr[n+1];
f(i,m)
{cin>>x>>y;
gr[x].push_back(y);
gr[y].push_back(x);}

f(i,n+1)
{low[i]=-1;
disc[i]=-1;
ap[i]=0;
p[i]=-1;}
f(i,n)
if(disc[i+1]==-1)
ARC(gr,i+1);
ll count=0;
f(i,n)
{
if(ap[i+1])
count++;
//cout<<i+1<<" :"<<disc[i+1]<<endl;
}
cout<<count;
}
}
