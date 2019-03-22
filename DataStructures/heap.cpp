/*
=============================================================================
    Life is a bunch of unexpected events ! 
    
    Code by:Vivek Singh
    College: NIT,Patna
    Batch: 2K15
    Handles:viv_nitp(codechef) & Steady_Bunny(hackerrank,codeforces)
    243470CB    
=============================================================================                                   
*/
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ull unsigned long long     
#define ll long long
#define mod 1000000007
#define mod2 1000000009L    
#define f(i,n) for( ll (i)= 0;(i)<(n);(i)++)    
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)   
#define lp pair<ll,ll> 
#define mp make_pair
#define mt make_tuple
#define M_H priority_queue<ll ,vector<ll >,greater<ll > >   
#define red 1;
#define black 0;
#define rep(i,j,n) for( ll (i)= j;(i)<(n);(i)++)
#define maxc 5000000
#define F first
#define S second
#define NUM 314159
#define maxn 150000
#define PI 3.1415926535 
#define inf 1000000000
#define LOG_WALA_FACTOR 100
#define ACTUAL_SIZE 10000
/****************MAX - HEAP****************************/
ll a[maxn],len=0;
void flow_up(ll i)
{
	ll p=i/2;
	if(i==1) return;

	if(a[i]>a[p])
		{
			swap(a[i],a[p]);
		    flow_up(p);
		}	
}
ll rmv( ll i)
{
	ll left=i*2;
	ll right=i*2+1;
	ll lar=i;
	if(left<=len && a[i]<a[left])
		lar=left;
	if(right<=len && a[lar]<a[right])
		lar=right;
	if(lar!=i)
	{
		swap(a[lar],a[i]);
		return rmv(lar);
	}
	return i;
}
void pop_top()
{
	a[1]=INT_MIN;
	ll x=rmv(1);
	a[x]=a[len];
	len--;
	flow_up(x);
}
void add(ll x)
{
	len++;
	a[len]=x;
	flow_up(len);
}	

int main()
{   
	faster;
	ll n,x;
	cin>>n;
	f(i,n)
	{cin >> x;
		add(x);
	}
	f(i,n)
	{
		cout<<a[1]<<endl;
		pop_top();
	}


}


