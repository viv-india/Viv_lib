//////////////////////////GCD////////////////////////////////
ll gcd(ll a, ll b){
    return b == 0 ? a: gcd(b, a % b);
}

//////////////////////////Sieve primes////////////////////////////////

vector<ll> primes;
bool isPrime[MAXN];
vector<ll> factors[MAXN];

void findAllPrimes() {
  f(i, MAXN)
    isPrime[i] = 1;

  for(ll i=2;i<MAXN;i++) 
    if(isPrime[i])  {
     for(ll j = 2;i*j < MAXN ; j++)
      isPrime[i*j] = 0;
      primes.push_back(i);
    }
 
}

//////////////////////////Factorisation////////////////////////////////

ll spf[MAXN];
void calculateSPF() {
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
        spf[i] = i;
 
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (ll i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

//////////////////////////Modular power////////////////////////////////

ll poww(ll a, ll b) {
    if(b==0)
        return 1;
  ll x = poww(a, b/2);
  return (((x * x)%mod)* ((b%2==1) ? a : 1))%mod;
}

ll p[100002];

//////////////////////////Segment Tree/////////////////////////
int tree[4000001];

int upd(ll target, ll a, ll b, ll i, ll val) {
    if(target<a || target>b) return tree[i];
    if(a==b) {
      //  cout<<a<<" "<<b<<" "<<val<<endl;
        return tree[i] = tree[i]+ val;}
    ll mid = a+(b-a)/2;
    ll left = upd(target, a, mid, 2*i, val);
    ll right = upd(target, mid+1, b, 2*i+1, val);
    return tree[i] = left+right;
}

int getVal(ll target, ll a, ll b, ll i) {
    if(a==b) return a;
    ll left = tree[2*i];
    ll mid = a+(b-a)/2;
    if(left>=target)
        return getVal(target, a, mid, 2*i);
    return getVal(target-left, mid+1, b, 2*i+1);
}

//////////////////////////Binary Lift////////////////////////////////
ll ancestors[200001][20]; // initialize with -1
ll level[200001];
void binaryLifiting(vector<ll> gr[], ll i, ll p,ll lvl) {
    level[i]  = lvl;
    ancestors[i][0] = p;    
    for(int j = 1;ancestors[i][j-1]!=-1;j++)
        ancestors[i][j] = ancestors[ancestors[i][j-1]][j-1];

    for(auto it: gr[i])
        if(it!=p)
            binaryLifiting(gr, it, i, lvl+1);
}

int getAncestor(int i, int lvl) {
    if(lvl<0) return -1;
    while(lvl) {
        int curr = (lvl&-lvl);
        lvl -= curr;
        i = ancestors[i][(int)log2(curr)];
        if(i==-1) return -1;
    }
    return i;
}


//////////////////////////Binary Lift With a twist////////////////////////////////


ll ancestors[200001][20]; // initialize with -1
ll maxEdge[200001][20]; // initialize with -1
ll level[200001];
void binaryLifiting(vector<vector<pair<ll, ll>>> &gr, ll i, ll p, ll lvl, ll wt) {
    level[i]  = lvl;
    ancestors[i][0] = p;    
    maxEdge[i][0] =  wt;
    for(int j = 1;ancestors[i][j-1]!=-1;j++) {
        maxEdge[i][j] = max(maxEdge[ancestors[i][j-1]][j-1],  maxEdge[i][j-1]);
        ancestors[i][j] = ancestors[ancestors[i][j-1]][j-1];
    }

    for(auto it: gr[i])
        if(it.first!=p)
            binaryLifiting(gr, it.first, i, lvl+1, it.second);
}

int getAncestor(int i, int lvl) {
    if(lvl<0) return -1;
    while(lvl) {
        int curr = (lvl&-lvl);
        lvl -= curr;
        i = ancestors[i][(int)log2(curr)];
        if(i==-1) return -1;
    }
    return i;
}

int getMaxEdge(int i, int lvl) {
    if(lvl<0) return 0;
    ll ans = 0;
    while(lvl) {
        int curr = (lvl&-lvl);
        lvl -= curr;
        ans =  max(maxEdge[i][(int)log2(curr)], ans);
        i = ancestors[i][(int)log2(curr)];
      //  cout<<"\n"<<i<<" "<<curr<<" "<<maxEdge[i][(int)log2(curr)]<<"$$"<<endl;
        if(i==-1) return 0;
    }
    return ans;
}


ll getLCALevel(ll x, ll y) {
    ll level1 = level[x];
    ll level2 = level[y];
    if(level2<level1) {
        swap(x,y);
        swap(level1, level2);
    }
 
    ll lo = 0, hi = level1;
    while(hi>lo) {
        ll mid = lo + (hi-lo)/2;
        ll anc1 = getAncestor(x, mid);
        ll mid2 = level2 - (level1-mid);
        ll anc2 = getAncestor(y, mid2);
        if(anc1==anc2) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    return level1 - lo;
}

//////////////////////////BIT////////////////////////////////







//////////////////////////Make graph////////////////////////////////
vector<vector<ll>> makeGraph(ll n) {
    ll x, y;
    vector<vector<ll>> gr(n+1);
    f(i, n-1) {
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);

    }
    return gr;
}
//////////////////////////Find Dia////////////////////////////////

pair<ll, ll> findDiameter(ll i, ll p, vector<vector<ll>> &tree) {
    ll dia = 1;
    ll maxDis = 0;
    for(auto it: tree[i])
        if(it!=p) {
            auto [x, d] =findDiameter(it, i, tree);
            dia = max(dia, maxDis + x);
            dia = max(dia, d);
            maxDis = max(maxDis, x);
        }
    return {maxDis+1, dia};    
}


////////////////////////// Z Function////////////////////////////////
vector<ll> z_function(string s) {
    ll n = s.size();
    vector<ll> z(n, 0); 
    for(ll i = 1, l = 0, r = 0;i<n;i++) {
        if(i<=r)
         z[i] = min(z[i-l], r-i+1);

        while(i+z[i]<n  && s[z[i]] == s[i+z[i]]) 
            z[i]++;
        
        if(i+z[i]-1>r)
            l = i, r = i+z[i]-1;
   }
   return z;
}

////////////////////////// Kruskal ////////////////////////////////
void kruskal(vector<pair<ll, ll>> gr[], vector<ll> &dis, ll n) {
    priority_queue<pair<ll, ll> , vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    for(int i=1;i<=n;i++) 
        if(dis[i]!=1e16) 
            pq.push({dis[i], i});

    while(pq.size()) {
        pair <ll, ll> pr = pq.top();
        ll d = pr.first;
        ll i = pr.second;
        if(dis[i]>=d) {
            for(auto &[it, currDis] : gr[i]) {
                if(dis[it] > currDis + d) {
                    dis[it] = currDis + d;
                    pq.push({dis[it], it});
                }
            }
        }
        pq.pop();
    }
}

////////////////////////// MST ////////////////////////////////

ll parent[200001];

ll getParent(ll x) {
    if(parent[x]!=x) parent[x]  = getParent(parent[x]);
    return parent[x];
}

void merge(ll x, ll y) {
    x = getParent(x);
    y = getParent(y);
    parent[x] = y;
}

vector<vector<pair<ll, ll>>> getMST(vector<pair<ll,pair<ll,ll>>> edges, ll n) {
    sort(edges.begin(), edges.end());
    vector<vector<pair<ll,ll>>> mst(n+1);
    for(int i=0;i<edges.size();i++) {
        ll val = edges[i].first;
        ll x = edges[i].second.first;
        ll y = edges[i].second.second;
        if(getParent(x)!=getParent(y)) {
            mst[x].push_back({y, val});
            mst[y].push_back({x, val});
            merge(x,y);
        }
    }
    return mst;
}



////////////////////////// is Cycle with topological sort ////////////////////////////////

bool IsCycle(vector<ll> gr[], ll i , stack<ll> &topological, ll seen[]) {
    seen[i] = 1;
    ll ans = 1;
    for(auto it: gr[i]) {
        if(seen[it]==1) 
            return 1;

        if(seen[it]==0) 
            if(IsCycle(gr, it, topological, seen))
                return 1;
    }
    seen[i] = 2;
    topological.push(i);
    return 0;
}

