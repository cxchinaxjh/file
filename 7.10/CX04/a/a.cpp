#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=2e6+5;
ll a[N],b[N];
ll n,k,x,c,len,i,lent,alian,blian,ansa,ansb,sb,sa,ro,re;
char ch,cht;
void doa()
{
	if (c==0)
	{
		cht=ch;
	}
	if (ch!='a') 
	{
		if (c==0)
		{
			c=1;
			lent=len;
		}
		ch='a';	
		len=1;
		
	} else len++;
	if (len>=x)
	{
		alian++;	
	} 
}
void dob()
{
	if (c==0)
	{
		cht=ch;
	}
	if (ch!='b') 
	{
		if (c==0)
		{
			c=1;
			lent=len;
		}
		ch='b';	
		len=1;
		
	} else len++;
	if (len>=x)
	{
		blian++;	
	} 
}
void eq()
{
	if (c==0)
	{
		cht=ch;
	}
	if (ch!='0')
	{
		if (c==0)
		{
			c=1;
			lent=len;
		}
		ch='0';
    	len=0;
    	
	}
}
void doax()
{
	if (ch!='a') 
	{
		ch='a';	
		len=1;
	} else len++;
	if (len>=x)
	{
		ansa++;	
	} 
}
void dobx()
{
	if (ch!='b') 
	{
		ch='b';	
		len=1;
	} else len++;
	if (len>=x)
	{
		ansb++;	
	} 
}
int main()
{
	//freopen("a.in","r",stdin); freopen("a.out","w",stdout);
	cin>>n>>k>>x;
	ro=k/n;
	re=k%n;
	ch='-';
	fori(i,1,n) scanf("%lld",&a[i]);
	fori(i,1,n) scanf("%lld",&b[i]);
	fori(i,1,n)
	{
		if (a[i]==0)
		{
			if (b[i]==1) 
			{
				sa++;
				doa();
			}
			if (b[i]==2) 
			{
				sb++;
				dob();
			}
			if (b[i]==0)
			{
				eq();
			}
		}
		if (a[i]==1)
		{
			if (b[i]==0) {
				sb++;
				dob();
			}
			if (b[i]==2) {
				sa++;
				doa();
			}
			if (b[i]==1)
			{
				eq();
			}
		}
		if (a[i]==2)
		{
			if (b[i]==0) {
				sa++;
				doa();
			}
			if (b[i]==1) {
				sb++;
				dob();
			}
			if (b[i]==2)
			{
				eq();
			}
		}
		//cout<<sa<<' '<<sb<<' '<<len<<endl;
	}
	
	if (c==0)
	{
		lent=len;
	}
	//cout<<lent<<endl;
	if (cht!=ch||(cht=='0'&&ch=='0'))
	{
		ansa=(sa+alian)*ro;
		ansb=(sb+blian)*ro;
		ch='0';
		len=0;
		fori(i,1,re)
    	{
	    	if (a[i]==0)
	    	{
	    		if (b[i]==1) 
	     		{
	    			sa++;
	     			doax();
	    		}
	    		if (b[i]==2) 
	    		{
	    			sb++;
	     			dobx();
	    		}
	    		if (b[i]==0)
		    	{
			    	eq();
			    }
	    	}
	    	if (a[i]==1)
	    	{
	     		if (b[i]==0) {
	    			sb++;
	     			dobx();
	    		}
	     		if (b[i]==2) {
	    			sa++;
	     			doax();
	    		}
	    		if (b[i]==1)
		    	{
			    	eq();
			    }
	    	}
	    	if (a[i]==2)
	    	{
		    	if (b[i]==0) {
	    			sa++;
	     			doax();
	    		}
		    	if (b[i]==1) {
	    			sb++;
	     			dobx();
	    		}
	    		if (b[i]==2)
		    	{
			    	eq();
			    }
	    	}
        }
        cout<<ansa<<' '<<ansb<<endl;
	} else {
		if (ch=='a')
		{
			if (len+lent>=x)
			{
				if (lent>=x)
				{
					if (len<x) ansa=(sa+alian)*ro+(ro-1)*len;
					if (len>=x) ansa=(sa+alian)*ro+(ro-1)*(x-1);
				}
				else {
					if (len<x) 
					{
						if (x-len<=lent) ansa=(sa+alian)*ro+(ro-1)*(lent-(x-len)+1);
						else ansa=(sa+alian)*ro;
					}
					if (len>=x) ansa=(sa+alian)*ro+(ro-1)*lent;
				}
			}	
			ansb=(sb+blian)*ro;
		}
		if (ch=='b')
		{
			if (len+lent>=x)
			{
				if (lent>=x)
				{
					if (len<x) ansb=(sb+blian)*ro+(ro-1)*len;
					if (len>=x) ansb=(sb+blian)*ro+(ro-1)*(x-1);
				}
				else {
					if (len<x) 
					{
						if (x-len<=lent) ansb=(sb+blian)*ro+(ro-1)*(lent-(x-len)+1);
						else ansb=(sb+blian)*ro;
					}
					if (len>=x) ansb=(sb+blian)*ro+(ro-1)*lent;
				}
			}
			ansa=(sa+alian)*ro;
			//cout<<ansa<<' '<<ansb<<endl;
		}
		fori(i,1,re)
    	{
	    	if (a[i]==0)
	    	{
	    		if (b[i]==1) 
	     		{
	    			ansa++;
	     			doax();
	    		}
	    		if (b[i]==2) 
	    		{
	    			ansb++;
	     			dobx();
	    		}
	    		if (b[i]==0)
		    	{
			    	eq();
			    }
	    	}
	    	if (a[i]==1)
	    	{
	     		if (b[i]==0) {
	    			ansb++;
	     			dobx();
	    		}
	     		if (b[i]==2) {
	    			ansa++;
	     			doax();
	    		}
	    		if (b[i]==1)
		    	{
			    	eq();
			    }
	    	}
	    	if (a[i]==2)
	    	{
		    	if (b[i]==0) {
	    			ansa++;
	     			doax();
	    		}
		    	if (b[i]==1) {
	    			ansb++;
	     			dobx();
	    		}
	    		if (b[i]==2)
		    	{
			    	eq();
			    }
	    	}
        }
        cout<<ansa<<' '<<ansb<<endl;
	}
}
