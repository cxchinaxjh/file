#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uin;
//typedef __int128 lll;
const int N=1e6+5;
ll n,i,a[N],b[N],j,ans;
ll sum(ll x,ll y)
{
	ll lenx,leny,anss,i,j,k;
	lenx=0;
	leny=0;
	while (x>0)
	{
		lenx++;
		a[lenx]=x%10;
		x/=10;
	}
	while (y>0)
	{
		leny++;
		b[leny]=y%10;
		y/=10;
	}
	anss=0;
	fori(i,1,lenx)
	fori(j,1,leny)
	for(k=1; (i+k-1<=lenx)&&(j+k-1<=leny); k++)
		if (a[i+k-1]==b[j+k-1]) anss=max(anss,k);
		else break;
	return anss;
}
int main()
{
	freopen("diyiti.in","r",stdin); freopen("diyiti.out","w",stdout);
	//cin>>n;
	n=1e6;
	ans=0;
	fori(i,1,n)
	{
		fori(j,1,i-1)
		ans+=sum(i,j)*2;
		ans+=sum(i,i);
		printf("%lld,",ans);
	}
	//cout<<ans<<endl;
	// }

}
