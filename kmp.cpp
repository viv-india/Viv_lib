#include<bits/stdc++.h>
using namespace std;

void calc(int lsp[],int M,string text)
{int j=0,i=1;
	lsp[0]=0;
	while(i<M)
	{
		if(text[i]==text[j])
		{	lsp[i]=j+1;
			j++;
			i++;
		}	
		else if(j!=0)
			j=lsp[j-1];
		else
			lsp[i++]=0;
	}
}

void kmp(string text,string pat)
{	int M=text.size();
	int N=pat.size();
	int lsp[M];
	calc(lsp,N,pat);
	int i=0,j=0;
	while(i<M)
		{
		if(pat[j]==text[i])
			{
			i++;j++;
			}
		if(j==N)
			{
			cout<<" found at"<<i-j<<"\n";
			j=lsp[j-1];
			}
		else if(i<M&&pat[j]!=text[i])
			{
			if(j!=0)
			j=lsp[j-1];
			else
			i++;
			}
		}
}
int main()
{kmp("AABAACAABAA","AA");
}

