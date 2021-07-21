#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
ull mid,l,r,n,t,x,y,z,bo,rt,st,ans,i;
ull v(ull x,ull y,ull z)
{
	if (mid==0) return 0;
	return x*mid+y*mid+(mid-1)*mid/2*z;
}
int main()
{
	freopen("a.in","r",stdin); freopen("a.out","w",stdout);
	cin>>n>>t;
	fori(i,1,n)
	{
		scanf("%llu%llu%llu",&x,&y,&z);
		if (z==0)
		{
			ans+=t/(x+y)*y;
			st=t%(x+y);
			if (st>x) ans+=st-x;
			//cout<<ans<<endl;
			continue;
		}
		l=0; r=100000;
		while (l<=r)
		{
			mid=(l+r)>>1;
			if (v(x,y,z)<=t)
			{
				bo=mid;
				st=v(x,y,z);
				l=mid+1;
			} else r=mid-1;
		} 
		//cout<<bo<<endl;
		if (bo>0) ans+=y*bo+(bo-1)*bo/2*z;
		rt=t-st;
		if (rt>x) ans+=rt-x;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
