#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)1e8
ll n;
ll BIT[maxn];

void update(ll x,ll val)
{for(;x<=n+1;x+=x&(-x))//add right most bit of current index
BIT[x]+=val;}

ll query(ll x)
{ll sum=0;
for(;x>0;x-=x&(-x))//remove right most bit of current index
sum+=BIT[x];
return sum;
}

int main()
{
cin>>n;
for(int i=1;i<=n;i++)// initialisation
BIT[i]=0;
for(ll i=1;i<=n;i++)
{ll x;
cout<<"\n"<<i<<" :";
cin>>x;
int p=i;
update(p,x);
}

cout<<"Sum of first 3 numbers"<<query(3);
cout<<"\nSum of range 2-4"<<query(4)-query(1);

}
