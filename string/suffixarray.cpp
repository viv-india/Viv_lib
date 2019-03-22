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
#define ll  long long
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
#define maxn 300001
#define PI 3.1415926535 
#define inf 1000000000
#define LOG_WALA_FACTOR 100
#define ACTUAL_SIZE 10000
struct some
{
    ll c[2];
    ll ind;
}L[ ACTUAL_SIZE ];

ll DP[ LOG_WALA_FACTOR ][ ACTUAL_SIZE ],endd,len;

ll lcp(ll x, ll y)
{
    ll k, ret = 0; if (x == y) return len - x;
    for (k = endd - 1; k >= 0 && x < len && y < len; k --)
    if (DP[k][x] == DP[k][y])
    x += 1 << k, y += 1 << k, ret += 1 << k; return ret;
}

bool cmp(some x1,some x2)
{
    return ((x1.c[0]==x2.c[0]) ? (x1.c[1]<x2.c[1])  : x1.c[0]<x2.c[0] );
}

int main()
{   
    string s;
    cin>>s;
    len=s.size();
    for(ll i=0;i<len;i++)
       if(s[i]>='0'&&s[i]<='9')
        DP[0][i]=s[i]-'0';
       else if(s[i]>='A'&&s[i]<='Z')
        DP[0][i]=s[i]+10-'A';
        else
        DP[0][i]=s[i];


    for(ll pass=1,cnt=1;cnt<=len;pass++,cnt<<=1LL)
    {
        for(ll i=0;i<len;i++)
        {
            L[i].c[0]=DP[pass-1][i];
            L[i].c[1]=(((i+cnt)<len)?DP[pass-1][i+cnt]:-1);
            L[i].ind=i;
        } 
        sort(L,L+len,cmp);
        for(ll i=0;i<len;i++)
          DP[pass][L[i].ind]= (i>0 && L[i].c[0]==L[i-1].c[0] && L[i].c[1]==L[i-1].c[1])?(DP[pass][L[i-1].ind]):i;
        endd=pass;
    }
    for(ll i=0;i<len;i++)
        cout<<DP[endd][i]<<endl;
}

