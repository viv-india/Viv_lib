/*************What doesn't kills you makes you stronger************************/  
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ull unsigned long long 
#define ll long long 
#define mod 1000000007
#define f(i,n) for( ll (i)= 0;(i)<(n);(i)++)
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lp pair<ll,ll> 
#define maxn 100001
#define mp make_pair
#define mt make_tuple 
#define M_H priority_queue<lp ,vector<lp >,greater<lp > >
//ll gcd(ll a ,ll b)  {return(a==0?b:gcd(b%a,a))
#define red 1;
#define black 0;
struct node
{bool color;//1 denotes red 0 denotes black
ll value;
node* left,right;
};

node* nn(ll val)
{node* t=new mode;
t->value=val;
t->color=red;
t->left=NULL;
t->right=NULL;
return t;
}

node* left_rotation(node* curr)
{node* temp=curr->right;
curr->right=curr->right->left;
temp->left=curr;
return temp;
}

node* right_rotation(node* curr)
{node* temp=curr->left;
curr->left=curr->left->right;
temp->right=curr;
return temp;
}


node* insert(node *cur,ll x)
{

if(cur==NULL) return nn(x);

if(cur->value>x)
cur->left=insert(cur->left,x)

else if(cur->value<x)
cur->right=insert(cur->right,x);

else
return cur
if(cur->color==red&&(cur->left->color==red||cur->right->color))

}

int main()
{faster;
ll n,x;
cin>>n;
node* leaf=nn();
if(n!=0)
{cin>>x;
head=nn(x);
head->color=black;
}

f(i,n-1)
{cin>>x;
head=insert(head,x);
}
}
