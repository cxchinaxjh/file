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
const int N=5e5+5;
const int Mod=1e9+7;
ll n,m,i,a[N],op,s,y,x,j,to[N],las[N],nxt[N],f[N][15],len,fa[N];
inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

void add(ll x,ll y)
{
	to[++len]=y;
	nxt[len]=las[x];
	las[x]=len;
}

void maketree(ll x,ll fa)
{
	ll i,j,k;
	f[x][0]=1;
	fori(i,1,10) f[x][i]=0;
	for (i=las[x]; i; i=nxt[i])
		if (to[i]!=fa)
		{
			maketree(to[i],x);
			ford(j,10,1)
			{
				fori(k,0,j-1)
				f[x][j]=(f[x][j]+f[x][k]*f[to[i]][j-k])%Mod;
			}
		}
	ford(i,10,1) f[x][i]=f[x][i-1]*a[x]%Mod;
}
void dp(ll x)
{
	ll i,j,k;
	f[x][0]=1;
	fori(i,1,10) f[x][i]=0;
	for (i=las[x]; i; i=nxt[i])
		if (to[i]!=fa[x])
		{
			ford(j,10,1)
			{
				fori(k,0,j-1)
				f[x][j]=(f[x][j]+f[x][k]*f[to[i]][j-k])%Mod;
			}
		}
	ford(i,10,1) f[x][i]=f[x][i-1]*a[x]%Mod;
}
void cr(ll x,ll y)
{
	fa[y]=fa[x];
	fa[x]=y;
	dp(x);
	dp(y);
}
void dfs(ll x)
{
	if (fa[x]!=0)
	{
		dfs(fa[x]);
		cr(fa[x],x);
	}
	else return;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	fori(i,1,n) a[i]=read();
	fori(i,2,n)
	{
		fa[i]=read();
		add(i,fa[i]);
		add(fa[i],i);
	}
	maketree(1,0);
	fori(i,1,m)
	{
		op=read();
		if (op==0)
		{
			x=read(); y=read();
			a[x]=y;
			fori(j,1,10)
			{
				dp(x);
				if (fa[x]==0) break;
				x=fa[x];
			}
		}
		if (op==1)
		{
			x=read(); s=read();
			dfs(x);
			printf("%lld\n",f[x][s]);
		}
	}
}
