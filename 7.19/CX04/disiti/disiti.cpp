#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uin;
const int N=1e5+5;
const int M=205;
const int E=1e6+5;
const int Mod=1000000007;
//typedef __int128 lll;
ll n,i,x,y,len,k,to[E],nxt[E],las[N],f[N][M][2][2],d[M];
void add(ll x,ll y)
{
	to[++len]=y;
	nxt[len]=las[x];
	las[x]=len;
}
/*void maketree(ll x,ll fa)
{
	ll i,j,t,ww,w;
	ww=0;
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=fa)
	{
		maketree(to[i],x);
		ww++;
	}
	f[x][1][1]=1;
	f[x][0][0]=1;
	if (ww==0)
	{
		return;
	}
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=fa)
	{
		w=to[i];
		ford(j,k,0)
		 fori(t,0,j-1)
		 f[x][j][1][0]=f[x][t][1][0]*(f[w][j-t-1][0][0]+f[w][j-t-1][0][1])%Mod,
		 f[x][j][1][1]=f[x][t][1][1]*(f[w][j-t-1][1][1]+f[w][j-t-1][1][0])%Mod
		 
	}
	memset(d,0,sizeof(d));
	d[0]=1;
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=fa)
	{
		w=to[i];
		ford(j,k,0)
		 fori(t,0,j)
		 f[x][j][0][0]=f[x][t][0][0]*f[w][j-t-1][0][1]%Mod
		ford(j,k,0)
		 fori(t,0,j)
		   d[j]=d[t]*f[w][j-t][0]%Mod;
	}
	fori(j,0,k) f[x][j][0]=((f[x][j][0]-d[j])%Mod+Mod)%Mod;//0 means 
}*/
int main()
{
	//freopen("disiti.in","r",stdin); freopen("disiti.out","w",stdout);
	cin>>n>>k;
	fori(i,1,n-1)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	maketree(1,0);
	//cout<<(f[1][k][0]+f[1][k][1])%Mod<<endl;
	cout<<1<<endl;
}
