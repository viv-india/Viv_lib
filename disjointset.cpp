#include<bits/stdc++.h>
using namespace std;
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
{public:
t1 *parent ;	//an array containing index of parent
t1 *rank ;	//an array for rank of each node


disjoint_set(t1 v)	//constructor for allocating memory to both variables and initialising thier values 
{
 parent=new t1[v];
 rank=new t1[v];

 for(t1 i=0;i<v;i++)
     {
	rank[i]=1;
        parent[i]=i;
  	}
}
t1 find(t1 i);
void merge(t1 x,t1 y);
};

template <class t1>
t1 disjoint_set<t1> :: find(t1 i)
{
if(parent[i]!=i)
parent[i]=find(parent[i]);
return parent[i];
}


template <class t1>
void disjoint_set<t1> :: merge(t1 x,t1 y)
{t1 px=find(x);
t1 py=find(y);
if(px==py)
cout<<"\nAlready in same set\n";
else//set with more rank becomes parent
{if(rank[px]>rank[py])
{parent[py]=px;
rank[px]+=rank[py];
}else{parent[px]=py;
rank[py]+=rank[px];//one merger with equal rank set increases rank by one
}}}


int main()
{long long  v;
cout<<"Enter number of different individual sets";
cin>>v;
disjoint_set <long long  > d(v);
cout<<"Enter number of queries\n";
int q;cin>>q;
cout<<"for merging (M x y) and for finding parent(P x)";
while(q--)
{char c;
int x,y;
cin>>c;
if(c=='M')
{cin>>x>>y;
d.merge(x,y);
}
if(c=='P')
{
cin>>x;
cout<<d.find(x)<<endl;
}
}


}
