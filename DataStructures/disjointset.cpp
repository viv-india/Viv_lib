#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
ll p[maxn];
ll rnk[maxn];

ll find(ll x)
{
  if(p[x]!=x) 
     p[x]=find(p[x]);

  return p[x];
}



void merge(ll x,ll y)
{
  x=find(x);
  y=find(y);
  
  if(x!=y)
  {
	  if(rnk[x]>rnk[y])
	    p[y]=x;

          else if(rnk[y]>rnk[x])
            p[x]=y;

          else 
          {
            p[x]=y;
            rnk[y]++;
          }   
  } 

}



int main()
{long long  v;

}
