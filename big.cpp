ll xx,yy,x,carry;	
class big
{
	public:
	vector<ll> val;
	ll sz;
	big()
	{
		sz=0;
	}	

	big operator +(big c2)
	{
		big c3;
		c3.val.resize(max(c2.sz,sz)+1);
		carry=0;
		f(i,max(c2.sz,sz))
		{
			if(i>=sz)
				xx=0;
			else
				xx=val[i];
			if(i>=c2.sz)
				yy=0;
			else
				yy=c2.val[i];
			x=xx+yy+carry;
			c3.val[i]=(x%1000000);
			carry=x/1000000;
		}
		if(carry!=0)
			c3.val[max(c2.sz,sz)]=(carry);
		
		c3.sz=max(c2.sz,sz)+(carry!=0);
	
		return c3;
	}
	big operator *(big c2)
	{
		big c3;
		c3.val.resize(10000,0);
		c3.sz=c2.sz+sz +1;

	for(ll i=0;i<sz;i++)
		{
			for(ll j=0;j<c2.sz;j++)
				{

					c3.val[i+j]+=(val[i]*c2.val[j]);
					c3.val[i+j+1]+=c3.val[i+j]/1000000;
				
					c3.val[i+j]%=1000000;
				
				//		cout<<c3.val[i+j]<<" ";
				//	cout<<c3.val[i+j+1]<<" ";
				
				}				
		}
		if(c3.val[0]==0) 
		{
			f(i,c3.sz)
			c3.val[i]=c3.val[i+1];
			c3.val[c3.sz-1]=0;
		}

		return c3;	

	}
	void  assign (ll x)
	{
		ll i=0;
		val.resize(0);
		while(x!=0)	
		{
			val.push_back(x%1000000);
			x/=1000000;
			i++;
		}
		sz=i;
	}
	bool operator !=(big c2)
	{
		if(sz == c2.sz)
		{	
			f(i,sz)
			if(val[i]!=c2.val[i])
				return 1;
			return 0;
		}
		return 1;
	}
	void print()
	{
		
		ll k=sz-1;
		while(k!=0&&val[k]==0)
			k--;
		cout<<val[k--];
		for(ll i=k;i>=0;i--)
		{
			ll t=val[i],x=6;
			while(t)
				{t/=10;x--;}
			while(x--) cout<<0;

			cout<<(ll)val[i];
		}

	}
};
