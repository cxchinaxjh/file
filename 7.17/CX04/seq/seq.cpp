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
ll to[N],s[N],las[N],nxt[N],dep[N],sum[N],num[N],w[N],tag[N];
ll len,y,n,i,nn,ss,l,r,mid,bo;
struct node
{
	ll x,y,z;
}a[N];
bool cmp(node a,node b)
{
	return a.z>b.z;
}
void add(ll x,ll y,ll z)
{
	to[++len]=y;
	w[len]=z;
	nxt[len]=las[x];
	las[x]=len;
}
void maketree(ll x,ll fa)
{
	ll i;
	dep[x]=dep[fa]+1;
	sum[x]=s[x];
	num[x]=1;
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=fa)
	{
		maketree(to[i],x);
		sum[x]+=sum[to[i]];
		num[x]+=num[to[i]];
	}
}
void dfs(ll x,ll fa,ll y)
{
	ll i;
	nn+=1;
	ss+=s[x];
	tag[x]=true;
	for (i=las[x];i;i=nxt[i])
	if (w[i]<y&&to[i]!=fa)
		dfs(to[i],x,y);
}
bool check(ll x)
{
	memset(tag,false,sizeof(tag));
	ll i,lend,s;
	lend=0;
	s=0;
	fori(i,1,n)
	if (!tag[i]) 
	{
		ss=0;
	    nn=0;
		dfs(i,0,x);
		lend++;
		sum[lend]=ss;
		s+=sum[lend];
		num[lend]=nn;
	}
	//cout<<lend<<endl;
	fori(i,1,lend)
		if (s-sum[i]<num[i]) return false;
	return true;
}
int main()
{
	//freopen("seq.in","r",stdin); freopen("seq.out","w",stdout);
	cin>>n;
	fori(i,1,n-1)
	{
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		add(a[i].x,a[i].y,a[i].z);
		add(a[i].y,a[i].x,a[i].z);
	}
	fori(i,1,n) scanf("%lld",&s[i]);
	l=0; r=1e9;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid))
		{
			l=mid+1;
			bo=mid;
		} else r=mid-1;
	}
	cout<<bo<<endl;
}
