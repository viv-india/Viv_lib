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

//////////////////////////BIT////////////////////////////////


