#include<bits/stdc++.h>
using namespace std;
#define ll  long long int 
/*
to calculate lcm a*b/gcd(a,b)
*/


ll gcd(ll a, ll b)	//hcf
{return b?gcd(b,a%b):a;}




int main()
{ll a=125,b=25;
ll g=gcd(125,25);
cout<<a/g<<" "<<b/g;}
