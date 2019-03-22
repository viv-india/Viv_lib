#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod %1000000007
#define f(i,n) for( int (i)= 0;(i)<(n);(i)++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//ll gcd(ll a ,ll b)  {return(a==0?b:gcd(b%a,a));}

int main()
{
//int start=clock();
int q;
cin>>q;
while(q--)
{ll n,m;
cin>>n>>m;
ll s1[m],s2[m];
f(i,m)
cin>>s1[i];
f(i,n)
cin>>s2[i];

ll dp[m+1][n+1];
for(int i=0;i<=m;i++)
{dp[i][0]=0;
}
for(int i=0;i<=n;i++)
dp[0][i]=0;

for(int i=1;i<=m;i++)
for(int j=1;j<=n;j++)
{if(s1[i-1]==s2[j-1])
dp[i][j]=dp[i-1][j-1]+1;
else
dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
}
ll vi[dp[m-1][n-1]],index=dp[m-1][n-1]-1;
ll i=m-1,j=n-1;
while(i>0&&j>0)
{if(s1[i]==s2[j])
{vi[index--]=s1[i];
i--;j--;
}
else if(dp[i][j-1]>d[i-1][j])
j--;
else
i--;

}
for(int i=0;i<dp[m-1][n-1];i++)
cout<<vi[i];

}

}
//int stop=clock();
//cout<<"time:"<<(stop-start)/double(CLOCKS_PER_SEC)*1000<<endl;
}

