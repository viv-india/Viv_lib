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
#define maxn 1000001
#define PI 3.1415926535 
#define root2 1.41421356237
#define inf 1000000000
#define LOG_WALA_FACTOR 100
#define ACTUAL_SIZE 10000
/**
  for aaaa
  if will give
  1 2 2 1
  means palindrome to left
**/ 


vector<ll> manaodd(ll s[],ll n){
vector<ll> d1(n);
for (ll i = 0, l = 0, r = -1; i < n; i++) {
    ll k=(i>r)?1:min(d1[l+r-i],r-i);
    while((0<=(i-k)) && ((i+k)<n) && (s[i-k]==s[i+k])) 
        k++;
    d1[i]=k--;
    if(i+k>r) {
        l=i-k;
        r=i+k;
    }
}
return d1;
}
vector<ll> manaeven(ll b[],ll n){
  ll a[2*n+1];
  f(i,n){
     a[2*i]=-1;
     a[2*i+1]=b[i]; 
  }
  a[2*n]=-1;
  n=2*n+1;
return manaodd(a,n);
}


int main()
{
  faster;
  #ifndef ONLINE_JUDGE
     freopen("output.txt","w", stdout);
     freopen("input.txt", "r", stdin);
  #endif
  ll Q=1,n,m;
  cin>>Q;
  while(Q--){
    cin>>n;
    ll a[n];
    f(i,n)
      cin>>a[i];
    // f(i,n)
    //   cout<<(char)a[i]<<" ";  
    mana(a,n);
    f(i,n)
  //  if(i%2==0)
      cout<<odd[i]<<" ";
    cout<<endl;  
    f(j,2*n+1)
      if(j%2==0)
      cout<<even[j]<<" ";
    cout<<endl;  
  }
}       