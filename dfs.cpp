#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/*
travese the first array of list
*/

void dfs(vector <int> a[],int u,bool f[])
{cout<<u;
vector <int> ::iterator it;
for(it=a[u].begin();it!=a[u].end();it++)
if(!f[*it])
{f[*it]=true;
dfs(a,*it,f);
}}

int main()
{int v=5,e=5;
bool f[5];
for(int i=0;i<v;i++)
f[i]=false;
vector <int> a[5];
a[0].push_back(1);
a[0].push_back(3);
a[2].push_back(3);
a[1].push_back(4);
a[4].push_back(1);
dfs(a,0,f);
}

