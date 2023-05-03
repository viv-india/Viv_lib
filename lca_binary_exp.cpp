
/*
 =============================================================================
 Life is a bunch of unexpected events !
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
#define maxn 1000001
#define PI 3.1415926535
#define root2 1.41421356237 
#define inf 1000000000
#define LOG_WALA_FACTOR 100
#define ACTUAL_SIZE 10000
ll inTime[maxn], outTime[maxn];
ll par[maxn][30];
ll level[maxn];
ll timer;

void dfs(vector<ll> gr[], ll i, ll p, ll lvl) {
  inTime[i] = timer++;

  level[i] = lvl;
  par[i][0] = p;
  ll x = p;
  for(int j = 1; p!=-1 && j<30;j++) {
    p = par[p][j-1];
    par[i][j] = p;
  }
    for(auto it: gr[i])
    if(it != x) {
      dfs(gr, it, i, lvl+1);
    }
  outTime[i] = timer++;
}

bool isParent(ll child, ll parent) {
  if(parent == -1) return true;
  return (inTime[parent] <= inTime[child]) && (outTime[parent] >= outTime[child]);
}

ll lca(ll u, ll v) {
  if(isParent(u, v)) return v;
  if(isParent(v, u)) return u;
  for(int i = 29;i>=0 ;i--) {
    if(!isParent(v, par[u][i]))
      u = par[u][i];
  }
  return par[u][0];
}

void preprocess(vector<ll> gr[], ll n) {
  timer = 1;
  f(i,n+1) {
    inTime[i] = -1;
    outTime[i] = -1;
    f(j,30) {
      par[i][j] = -1;
    }
  }
  dfs(gr, 1, -1, 0);
}

int main()
{
  faster;
  #ifndef ONLINE_JUDGE
     freopen("output.txt","w", stdout);
     freopen("input.txt", "r", stdin);
  #endif
  ll Q=1, n, k, m, q, u, v, a, x,ans;
 // cin>>Q;
  while(Q--) {
    cin>>n>>m>>q;
    vector<ll> gr[n+1];
    f(i,n-1) {
      cin>>v>>u;
      gr[v].push_back(u);
      gr[u].push_back(v);
    }
    preprocess(gr, n);
  }
}