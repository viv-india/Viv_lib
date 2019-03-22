#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1001
vector <ll> v[maxn];
bool seen[maxn];
int p[maxn];
int low[maxn];
int tym[maxn];
bool is_cut[maxn];
void dfs(ll vertex)
{seen[vertex]=1;
static int c=1;
int child=0;
low[vertex]=tym[vertex]=c++;
vector <ll> ::iterator i;
for(i=v[vertex].begin();i!=v[vertex].end();i++)
{   if(!seen[*i])
{    child++;
    p[*i]=vertex;
    dfs(*i);
   
    low[vertex]=min(low[vertex],low[*i]);
 //   cout<<p[vertex]<<" "<<low[*i]<<" "<<tym[vertex]<<"\n";
    if((child>1&&p[vertex]==-1)||(p[vertex]!=-1&&low[*i]>=tym[vertex]))
    is_cut[vertex]=1;
}
 else
 low[vertex]=min(low[vertex],tym[*i]);
    
    
}
}

int main()
{
 ll n,m;
 cin>>n>>m;
 while(m--)
 {int x,y;
     cin>>x>>y;
     v[x].push_back(y);
     v[y].push_back(x);   
 }
 memset(seen,0,sizeof(seen));
 memset(p,-1,sizeof(p));
 memset(is_cut,0,sizeof(is_cut));
 dfs(1);
for(int i=1;i<=n;i++)
{//cout<<i<<" "<<low[i]<<" "<<tym[i]<<"\n";
if(is_cut[i])
cout<<"Satisfied "<<i<<"\n";
else
cout<<"Not Satisfied \n";
} return 0;
}

