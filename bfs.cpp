#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/*
travese the first array of list
*/

void bfs(vector <int> a[],int i,bool f[])
{
vector <int> ::iterator it;
queue <int> q;
q.push(i);
while(!q.empty())
{
int u=q.front();
q.pop();
cout<<u<<" ";
for(it=a[u].begin();it!=a[u].end();it++)
if(!f[*it])
{f[*it]=true;
q.push(*it);
}}}

int main()
{int v=5,e=5;
bool f[5];
for(int i=0;i<v;i++)
f[i]=false;
vector <int> a[5];
a[0].push_back(1);
a[0].push_back(3);
a[2].push_back(3);
a[3].push_back(4);
a[4].push_back(1);
bfs(a,0,f);
}

