
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
#define ll   long long 
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
#define MAXN 1000001

void modinv(ll a,ll b,ll *x,ll *y)
{
	if(a==0)
	{
		*x=0;*y=1;
		return;
	}
	
	ll x1,y1;
	modinv(b%a,a,&x1,&y1);
	*y=x1;
	*x=y1-(b/a)*x1;
}

ll fast(ll a,ll m)
{
	ll x,y;
	modinv(a,m,&x,&y);
	return (x%m+m)%m;
}
/*
	P=p[0]*p[1]...*p[n-1];
	x%p[i] =a[i];	
	CRT returns x%p; 
*/

ll C[51][51][51];
vector<ll> pp;

ll ncr(ll n,ll r,ll p){
//	cout<<n<<" "<<r<<" "<<p<<endl;
	if(r>n) return 0;
	if(n==0||r==0) return 1;
	if(C[n][r][p]!=-1) return C[n][r][p];
		
	C[n][r][p]=(ncr(n-1,r-1,p)+ncr(n-1,r,p))%p;
//	cout<<n<<" "<<r<<" "<<p<<" "<<C[n][r][p]<< " \n";
    return C[n][r][p];
}
ll ncr_big(ll n,ll r,ll p){//LUCAS
	ll ans=1;
	if(n<r) return 0;
	while(n||r){		
		if(r<=n)																							
		ans=(ans*ncr(n%p,r%p,p))%p;
	//	cout<<ans<<"@"<<endl;
		n/=p; 
		r/=p;
	}
	return ans;
}	

void generatepp(ll n){
	pp.clear();
	ll N=n;

	while (n%2 == 0)
    {
        pp.push_back(2);
        n = n/2;
    }
 	for (int i = 3; i <= sqrt(N); i = i+2)
    {
        while (n%i == 0)
        {
        	pp.push_back(i);
            n = n/i;
        }
    }
 	if (n > 2)	
        pp.push_back(n);
   // cout<<N<<" ";
   // for(auto it: pp)
    //		cout<<it<<":";
}


ll CRT(ll n,ll r,ll p){
	//cout<<p<<"!!";
	generatepp(p);
	ll ans=0;
	for(ll i=0;i<pp.size();i++){
		ll a=ncr_big(n,r,pp[i]);
		ll inv=fast(p/pp[i],pp[i]);
		ans=(ans+ (((((p/pp[i])%p)*inv)%p)*a)%p )%p;
	}
	return ans;
}



int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    #endif


	f(i,51)
		f(j,51)
			f(k,51)
				C[i][j][k]=-1;
	ll T;
	cin>>T;
	while(T--){
		ll n,r,m;
		cin>>n>>r>>m;
		cout<<CRT(n,r,m)<<"\n";
	}

	return 0;
}