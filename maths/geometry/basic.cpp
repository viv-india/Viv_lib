/*
	Boundary is a myth  
	
	Code by:Vivek Singh
	College: NIT,Patna
	Batch: 2K15
	Handles:viv_nitp(codechef) & Steady_Bunny(hackerrank,codeforces)
									
*/
#include<bits/stdc++.h>
using namespace std;
#define ld long double    
#define ull unsigned long long     
#define ll long long
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
#define NUM 314159
class Vector
{
	public:
	ld x,y,z;
	ld dot(Vector b)
	{
		return (this->x)*(b.x)+(this->y)*(b.y)+(this->z)*(b.z);
	}
	 Vector cross(Vector b)
	{
		Vector c;
		c.x=(this->y)*(b.z)-(this->z)*(b.y);
		c.y=(this->z)*(b.x)-(this->x)*(b.z);
		c.z=(this->x)*(b.y)-(this->y)*(b.x);
		return c;
	}
	ld MOD()
	{
		return sqrt((this->x)*(this->x)+(this->y)*(this->y)+(this->z)*(this->z));
	}
	void print()
	{
		cout<<this->x<<"i +"<<this->y<<"j +"<<this->z<<"k \n"; 
	}
};

int main()
{	faster;
	ll T,r1,r2,x1,x2,y1,y2,z1,z2,ax1,ax2,ay1,ay2,az1,az2;
	cin>>T;
	while(T--)
	{
		cin>>r1>>r2>>x1>>y1>>z1>>ax1>>ay1>>az1>>x2>>y2>>z2>>ax2>>ay2>>az2;
		Vector AB,AC;
		AB.x=ax1-ax2;
		AB.y=ay1-ay2;
		AB.z=az1-az2;
		
	//	AB.print();
		AC.x=x2-x1;
		AC.y=y2-y1;
		AC.z=z2-z1;
		
	//	AC.print();
		ld dis;
		
		if(AB.dot(AC)<=0)
			{
				dis=AC.MOD();				
			}
		else
			{
				Vector ZZ;
				ZZ=AB.cross(AC);
				dis=ZZ.MOD();
				dis/=AB.MOD();
			}
		//	cout<<"D="<<dis<<" ";
		if(dis<=r1+r2)
		cout<<"YES\n";
		else
		cout<<"NO\n";		
		
	
	}	

}	
