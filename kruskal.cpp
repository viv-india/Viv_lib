#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
/*****************************************************disjoint set starts here************************************************************/
/*
#three operations	
1.Create set
"A new memory chunk where parent pointer goes to itself and rank is zero" 

2.Merge sets
"it consists of 2 cases
1.equal ranks -> make parent any one and increase its rank by one
2.unequal rank-> make parent to that one which is having the higher rank  
"

3.Findset
"it is a two pass method which checks if parent and child  points to same location then return else
recursively call the method again for its parent updating the value of parent"


#two heuristics
1.union by rank
to check for rank to decide the parent

2.path compression
to remove the need of traversing the nodes again and again to find the parent
*/



template<class t1>
class disjoint_set
{
t1 *parent ;	//an array containing index of parent
t1 *rank ;	//an array for rank of each node
public:

disjoint_set(t1 v)	//constructor for allocating memory to both variables and initialising thier values 
{
 parent=new t1[v];
 rank=new t1[v];

 for(t1 i=0;i<v;i++)
     {
	rank[i]=0;
        parent[i]=i;
  	}
}
t1 find_set(t1 i);
void merge_set(t1 x,t1 y);
bool check_cycle(t1 x,t1 y);
};
template <class t1>
t1 disjoint_set<t1> :: find_set(t1 i)
{
if(parent[i]!=i)
parent[i]=find_set(parent[i]);
return parent[i];
}
template <class t1>
void disjoint_set<t1> :: merge_set(t1 x,t1 y)
{
t1 px=find_set(x);
t1 py=find_set(y);

if(px==py)
cout<<"\nAlready in same set\n";
else
{if(rank[px]>rank[py])
parent[py]=px;
else if(rank[px]>rank[py])
parent[px]=py;
else if(rank[px]==rank[py])
{parent[px]=py;
rank[py]++;
}}}
template <class t1>
bool disjoint_set<t1> ::check_cycle(t1 x,t1 y)// function to check for cyclce formation
{if(find_set(x)==find_set(y))
return true; 
return false;
}
/*************************************************disjoint set ends here************************************************************/


int main()
{int v,e;
cout<<"enter number of verices then edges";
cin>>v>>e;
vector<pair<int,p> > A;
vector<pair<int,p> > ::iterator it;

cout<<"Enter edges and their weight";
for(int i=0;i<e;i++)
{int x,y,wt;
cin>>x>>y>>wt;
A.push_back({wt,{x,y}});
A.push_back({wt,{y,x}});
}
cout<<"wt"<<"\t"<<"x "<<"Y\n";
sort(A.begin(),A.end());
//for(it=A.begin();it!=A.end();it++)
//cout<<(it->first)<<"\t"<<it->second.first<<" "<<it->second.second<<"\n";
/**************************************************graph created and sorted*********************************************************/
disjoint_set <int> d(v);
vector<pair<int,p> > MST;
for(it=A.begin();it!=A.end();it++)
if(!d.check_cycle(it->second.first,it->second.second))
{d.merge_set(it->second.first,it->second.second);
MST.push_back({it->first,{it->second.first,it->second.second}});

}
for(it=MST.begin();it!=MST.end();it++)
cout<<(it->first)<<"\t"<<it->second.first<<" "<<it->second.second<<"\n";

}
