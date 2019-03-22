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
typedef complex<double> base;
int rev[MAXN] ;// Repositioning array
base wlen_pw[MAXN] ;//nth root of omega

void fft(base a[] , int n, bool invert) 
{
	for(int i=0;i<n;++i)
		if(i<rev[i])
			swap(a[i],a[rev[i]]) ;//Array rearranged
 
	for ( int len = 2 ; len <= n ; len <<= 1 ) {
		double ang = 2 * PI / len * ( invert ? - 1 : + 1 ) ;
		int len2 = len >> 1 ;
 		base wlen ( cos (ang) , sin (ang) ) ;
		wlen_pw[0]=base(1,0) ;
		for (int i=1;i<len2;++i)
			wlen_pw[i]=wlen_pw[i-1]*wlen ;
 
		for (int i=0;i<n;i+=len)
		{
				 base t,
				*pu=a+i,
				*pv=a+i+len2, 
				*pu_end=a+i+len2,
				*pw=wlen_pw;
			for (;pu!=pu_end;++pu,++pv,++pw) 
			{
				t =*pv * *pw;
				*pv=*pu-t;
				*pu+=t;
			}
		}
	}
 
	if ( invert )
		for ( int i = 0 ; i < n ; ++ i )
			a [ i ] / = n ;
}
void calc_rev(int n,int log_n) //This function calculates the new position of elements to avoid recursive odd even division
{
	for(int i=0;i<n;++i) 
	{
			rev[i] = 0 ;	
			for (int j=0; j<log_n ; ++j )
				if ( i & ( 1 << j ) )	// if it becomes odd after j divisons in 2 equal parts 
					rev[i] | = 1 << (log_n-1-j);	// creating position for ith element 
	}
} 

int main()
{
	faster;
	


}
