#include<bits/stdc++.h>
using namespace std;
struct trie
{trie* child[26];
int count;
bool isleaf;
};

trie* nn()
{
trie *t=new trie;
for(int i=0;i<26;i++)
t->child[i]=NULL;
t->count=0;
t->isleaf=false;
return t;
}

	void insert(trie *node,string s)
	{int sz=s.size();
	trie *crawl=node;
	for(int i=0;i<sz;i++)
	{
	int index=s[i]-'a';
	if(!crawl->child[index])
	{crawl->child[index]=nn();
	
	}crawl=crawl->child[index];
	crawl->count++;
	}
	crawl->isleaf=true;	
	 }
		int search(trie *node,string s)
		{int sz=s.size();
		trie *crawl=node;
		for(int i=0;i<sz;i++)
		{
		int index=s[i]-'a';
		if(!crawl->child[index])
		return 0;
		crawl=crawl->child[index];
		}
		return crawl->count; 
		}
int main()
{
string s[3]={"vivek","vivekananda","viveksingh"};
trie *n=nn();
insert(n,s[0]);
insert(n,s[1]);
insert(n,s[2]);
string S;
cin>>S;
cout<<search(n,S);
}




