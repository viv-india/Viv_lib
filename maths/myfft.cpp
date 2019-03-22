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
#define root2 1.41421356237
#define inf 1000000000
#define LOG_WALA_FACTOR 100
#define ACTUAL_SIZE 10000
#define MAXN 16000001 

const ld PI=acos(-1);
using cd = complex<ld> ;

int reverse(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n)
        lg_n++;

    for (int i = 0; i < n; i++) {
        if (i < reverse(i, lg_n))
            swap(a[i], a[reverse(i, lg_n)]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}


int main() 
{
	faster;
	vector<ll> a,b;
	//a.push_back(0);
	a.push_back(2);
	a.push_back(3);

	//b.push_back(0);
	b.push_back(5);
	b.push_back(6);

	vector<cd> fa(a.begin(),a.end()),fb(b.begin(),b.end());

	ll n=1;
	while(n<a.size()+b.size())
		n<<=1;
	
	fa.resize(n);
	fb.resize(n);
	fft(fa,0);
	fft(fb,0);
	//fft(fb,1);
	



	f(i,n)
		fa[i]*=fb[i];
	
	fft(fa,1);

		vector<ll> result(n);
	f(i,n)
		result[i]=round(fa[i].real());



	f(i,n)
	cout<<result[i]<< " ";	

}	