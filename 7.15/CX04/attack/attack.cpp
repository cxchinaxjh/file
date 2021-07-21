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
ll to[N],las[N],nxt[N],f[N],ff[N],a[N],son[N],k[N],m1[N],m2[N];
ll len,ans,n,i,xx,yy;
void add(ll x,ll y)
{
	to[++len]=y;
	nxt[len]=las[x];
	las[x]=len;
}
void maketree(ll x,ll fa)
{
	ll i,max1,max2;
	//cout<<x<<endl;
	max1=-1e17;
	max2=-1e17;
	f[x]=a[x];
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=fa)
	{
		maketree(to[i],x);
		f[x]=max(f[x],a[x]+f[to[i]]);
		if (f[to[i]]>max1) 
		{
			max2=max1;
			max1=f[to[i]];
		}
		else if (f[to[i]]>max2) max2=f[to[i]];
	}
	ff[x]=max(f[x],max1+max2+a[x]);
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=fa)
	{
		ff[x]=max(ff[x],ff[to[i]]);
	}
		
}
void chr(ll x,ll y)
{
	ll i,max1,max2;
	f[x]=a[x];
	max1=-1e17;
	max2=-1e17;
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=y) 
	{
		f[x]=max(f[x],a[x]+f[to[i]]);
		if (f[to[i]]>max1) 
		{
			max2=max1;
			max1=f[to[i]];
		}
		else if (f[to[i]]>max2) max2=f[to[i]];
	}
	ff[x]=max(f[x],max1+max2+a[x]);
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=y) ff[x]=max(ff[x],ff[to[i]]);
	f[y]=a[y];
	max1=-1e17;
	max2=-1e17;
	for (i=las[y];i;i=nxt[i])
	{
		f[y]=max(f[y],a[y]+f[to[i]]);
		if (f[to[i]]>max1) 
		{
			max2=max1;
			max1=f[to[i]];
		}
		else if (f[to[i]]>max2) max2=f[to[i]];
	}
	ff[y]=max(f[y],max1+max2+a[y]);
	for (i=las[y];i;i=nxt[i])
	ff[y]=max(ff[y],ff[to[i]]);
}
void dfs(ll x,ll fa)
{
	chr(fa,x);
	ll i,max1,max2,w,max3,max4,max5,max6;
	/*cout<<x<<endl;
	fori(i,1,n) cout<<i<<' '<<f[i]<<' '<<ff[i]<<endl;
	puts("");*/
	max1=-1e17;
	max2=-1e17;
	m1[0]=-1e17;
	m2[0]=-1e17;
	max3=-1e17;
	max4=-1e17;
	w=0;
	for (i=las[x];i;i=nxt[i])
	{
		w++;
		k[w]=to[i];
		m1[w]=m1[w-1];
		m2[w]=m2[w-1];
		if (f[to[i]]>m1[w])
		{
		    m2[w]=m1[w];
			m1[w]=f[to[i]];	
		} else {
			if (f[to[i]]>m2[w])
			m2[w]=f[to[i]];	
		}
		if (ff[to[i]]>max1)
		{
			max2=max1;
			max1=ff[to[i]];
		}
		else {
			if (ff[to[i]]>max2)
			max2=ff[to[i]];
		}
	}
	ans=max(ans,max1+max2);
	/*cout<<ans<<endl;
	puts("");*/
	ford(i,w,1)
	{
		//cout<<i<<' '<<k[i]<<endl;
		if (m1[i-1]>max3)
		{
			max5=m1[i-1];
			max6=max(m2[i-1],max3);
		}
		else 
		{
			max5=max3;
			max6=max(m1[i-1],max4);
		}
		//cout<<max5<<' '<<max6<<endl;
		ans=max(ans,ff[k[i]]+a[x]+max5+max6);
		if (f[k[i]]>max3)
		{
			max4=max3;
			max3=f[k[i]];
		}
		else 
		{
			if (f[k[i]]>max4) max4=f[k[i]];
		}
	}
	/*cout<<ans<<endl;
	puts("");*/
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=fa)
		dfs(to[i],x);
	chr(x,fa);
}
int main()
{
	freopen("attack.in","r",stdin); freopen("attack.out","w",stdout);
	cin>>n;
	fori(i,1,n) scanf("%lld",&a[i]);
	fori(i,1,n-1)
	{
		scanf("%lld%lld",&xx,&yy);
		add(xx,yy);
		add(yy,xx);
	}
	ans=-1e17;
	maketree(1,0);
	//cout<<0<<endl;
	dfs(1,1);
	cout<<ans<<endl;
}
