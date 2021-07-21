#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=2e5+5;
ll x,y,n,m,i,j,ans,len,num[N],to[N],las[N],nxt[N],f[N];
void add(ll n,ll x,ll y)
{
	len++;
	num[len]=n;
	to[len]=y;
	nxt[len]=las[x];
	las[x]=len;
}
void dfs(ll k)
{
	int i;
	for(i=las[k];i;i=nxt[i])
	if (num[i]>=x&&num[i]<=y&&to[i]>=x&&to[i]<=y&&f[to[i]]==0)
	{
		f[to[i]]=1;
		dfs(to[i]);
	}
}
int main()
{
	freopen("d.in","r",stdin); freopen("d.out","w",stdout);
	cin>>n>>m;
	fori(i,1,n-1)
	{
		scanf("%lld%lld",&x,&y);
		add(i,x,y);
		add(i,y,x);
	}
	fori(i,1,m)
	{
		memset(f,0,sizeof(f));
		scanf("%lld%lld",&x,&y);
		ans=0;
		fori(j,x,y)
		if (f[j]==0)
		{
			ans++;
			dfs(j);
		}
		printf("%lld\n",ans);
	}
}
