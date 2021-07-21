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
const int Mod=1e9+7;
const int N=100;
ll to[N],a[N],tag[N],nxt[N],las[N],q[N],f[N],ok[N],aa[N];
ll n,m,i,len,s,x,y,op,ans;
void add(ll x,ll y)
{
	to[++len]=y;
	nxt[len]=las[x];
	las[x]=len;
}
bool d(ll tot)
{
	ll l,r,i,w;
	fori(i,1,tot) ok[i]=false;
	q[1]=f[1];
	l=1; r=1;
	ok[1]=true;
	while (l<=r)
	{
		w=q[l];
		for (i=las[w];i;i=nxt[i])
		if (tag[to[i]]&&ok[aa[to[i]]]==false) 
		{
			ok[aa[to[i]]]=true;
			r++;
			q[r]=f[aa[to[i]]];
		}
		l++;
	}
	fori(i,1,tot)
	if (!ok[i]) return false;
}
void check()
{
	ll i,tot,w;
	tot=0;
	w=1;
	fori(i,1,n)
	if (tag[i]) 
	{
		f[++tot]=i;
		aa[i]=tot;
		w*=a[i];
		w%=Mod;
	}
	if (tot!=s) return;
	if (!tag[x]) return;
	//cout<<tot<<endl;
	if (d(tot)) ans=(ans+w)%Mod; 
}
void dfs(ll x)
{
	//cout<<x<<endl;
	if (x>n) 
	{
		check();
		return;
	}
	tag[x]=true;
	dfs(x+1);
	tag[x]=false;
	dfs(x+1);
}
int main()
{
	freopen("tree.in","r",stdin); freopen("tree.out","w",stdout);
	cin>>n>>m;
	fori(i,1,n) scanf("%lld",&a[i]);
	fori(i,2,n)
	{
		scanf("%lld",&x);
		add(i,x);
		add(x,i);
	}
	fori(i,1,m)
	{
		scanf("%lld",&op);
		if (op==0)
		{
			scanf("%lld%lld",&x,&y);
			a[x]=y;
		}
		if (op==1)
		{
			scanf("%lld%lld",&x,&s);
			ans=0;
			dfs(1);
			printf("%lld\n",ans);
		}
	}
}
