#include<bits/stdc++.h>
using namespace std;
typedef  pair<int ,int> pa;
#define ms make_pair
#define setr(a) memset(a,-1,sizeof(a))
#define type vector <pa >
#define pq priority_queue<pa, vector<pa>,greater<pa> >
void prim(type a[],int key[],int parent[],int src,int v)
{bool mst[v];
 memset(mst,false,sizeof(mst));
 key[src]=0;
 parent[src]=src;
 type ::iterator it;
 pq q;

//for(int i=0;i<v;i++)
//for(it=a[i].begin();it!=a[i].end();it++)
//cout<<i<<" "<<(it->first)<<" "<<(it->second)<<"\n";


q.push(ms(0,src));
//cout<<"C"<<"\t"<<"k\n";
//for(int i=0;i<v;i++)
//cout<<i<<"\t"<<key[i]<<"\n";


		while(!q.empty())
		{int u=q.top().second;
		q.pop();
		mst[u]=true;
			for(it=a[u].begin();it!=a[u].end();it++)
			{int v=it->second;
			int wt=it->first;
        			if(!mst[v]&&key[v]>wt+key[u])
				{key[v]=wt+key[u];
				q.push(ms(wt,v));
				parent[v]=u;}
			}
		}

/*Printing press*/
//cout<<"C"<<"\t"<<"k\n";
for(int i=0;i<v;i++)
cout<<i<<"\t"<<key[i]<<"\n";
}

int main()
{int e,v,x,y,wt;
	cout<<"Enter number of vertices and eges\n";
	cin>>v>>e;
	type a[v];
		for(int i=0;i<e;i++)
		{ cin>>x>>y>>wt;
			x--,y--;
		  a[x].push_back(ms(wt,y));
   	          a[y].push_back(ms(wt,y));
			}
type :: iterator it;
int parent[v],key[v];
for(int i=0;i<v;i++)
key[i]=INT_MAX;
setr(parent);
prim(a,key,parent,0,v);
}
