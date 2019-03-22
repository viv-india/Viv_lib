/*
	Boundary is a myth  
	
	Code by:Vivek Singh
	College: NIT,Patna
	Batch: 2K15
	handles:viv_nitp(codechef,codeforces) & steady_bunny(hackerrank)
									
*/
#include<bits/stdc++.h>
using namespace std;
#define ld long double    
#define ull unsigned long long     
#define ll 	 long long
#define mod 1000000007    
#define f(i,n) for( ll (i)= 0;(i)<(n);(i)++)    
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)   
#define lp pair<ll,ll> 
#define mp make_pair
#define mt make_tuple
#define M_H priority_queue<ll ,vector<ll >,greater<ll > >
#define red 1;
#define black 0;
#define rep(i,j,n) for( ll (i)= j;(i)<(n);(i)++)
#define maxn 100000
#define maxc 5000000
#define F first
#define S second

int main()
{	faster;
	ll n;
	cin>>n;
	ll a[n+1];
	a[0]=0;
	a[1]=1;
	a[2]=2;
	rep(i,3,n+1)
	a[i]=i+a[i-2];
	cout<<a[n];
}	
