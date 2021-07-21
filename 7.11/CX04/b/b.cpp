#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
ll t,n,m,w,nummin,a,b;
int main()
{
    freopen("b.in","r",stdin); freopen("b.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
		w=m-m/b*b;
		nummin=m/b;
		if (w>0)
		{
			if (w<=b/2) nummin++;
	    	else {
	     		if (w==a) nummin++;
		    	else {
		    		if (a>w&&(a-w)%(b-a)==0&&nummin>=(a-w)/(b-a)) nummin++;
		    		else nummin+=2;
				}
	    	}
		}
		
		if (nummin<=n) puts("Yes");
		else puts("No");
	}
}
