#include <bits/stdc++.h>
using namespace std;
#define ll long long  int
#define mod %1000000007
#define md 1000000007

ll fact[600000];
ll invfact[600000];

ll mul(ll a,ll b) {  return (long long) a*b mod; }

long countSubs(string s){long int sz=s.size();
map<char,int> m;
                         m['a']=0;m['b']=0;m['c']=0;m['d']=0;
                         for(long int i=0;i<sz;i++)
                            m[s[i]]++;
                        return (( (  (fact[m['a']+m['b']]mod)*invfact[m['a']] mod ) *invfact[m['b']] mod )*( (  (fact[m['c']+m['d']]mod)*invfact[m['c']] mod ) *invfact[m['d']] mod )-1)mod; 
                        }
ll pow(ll a, ll b)
{ll res=1;
    //cout<<"C";
 
 while(b>0)
     {
     if(b&1)
     res=mul(res,a);
  a=mul(a,a);    
     b=b/2;
     cout<<res<<"\n";
 }
    return res;
    
}   
ll inv(ll x)
    {
    return pow(x,md-2);
}

int main() {
    fact[0]=1;
    invfact[0]=1;
    for(ll i=1;i<500001;i++)
    {fact[i]=mul(fact[i-1],i);
    cout<<inv(fact[i])<<" ";
    }int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        long result = countSubs(s);
        cout << result << endl;
    }
    return 0;
}

