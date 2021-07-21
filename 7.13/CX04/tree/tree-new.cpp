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
const db e=1e-7;
const int N=3e5+5;;
int n,i,to[N],len,nxt[N],las[N],x;
db l,r,mid,anss,ans[N],f[N],bo,v[N];
bool tag;
void add(int x,int y)
{
	to[++len]=y;
	nxt[len]=las[x];
	las[x]=len;
}
void maketree(int x,int fa)
{
	int i;
	f[x]=v[x];
	//cout<<f[x]<<endl;
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=fa)
	{
		maketree(to[i],x);
		f[x]+=max((db)0,f[to[i]]);
	}
}
void cr(int x,int y)
{
	if (x==y) return;
	f[x]=f[x]-max(f[y],(db)0);
	f[y]=f[y]+max(f[x],(db)0);
}
void dfs(int x,int fa)
{
	int i;
	cr(fa,x);
	//cout<<x<<' '<<f[x]<<' '<<f[fa]<<endl;
	if (f[x]<0) 
	{
		tag=false;
		//cout<<f[x]<<endl;
	}
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=fa)
		dfs(to[i],x);
	cr(x,fa);
}
bool check(db x)
{
	int i;
	//cout<<x<<endl;
	fori(i,1,n)
	{
		v[i]-=x;
		//cout<<i<<' '<<v[i]<<endl;
	}
	
	tag=true;
	maketree(1,0);
	//cout<<f[2]<<endl;
	dfs(1,1);
	//cout<<endl;
	//cout<<tag<<endl;
	fori(i,1,n)
	v[i]+=x;
	return tag;
} 
int main()
{
	//freopen("tree.in","r",stdin); freopen("tree.out","w",stdout);
	cin>>n;
	fori(i,1,n) scanf("%lf",&v[i]);
	fori(i,2,n) 
	{
		scanf("%d",&x);
		add(x,i);
		add(i,x);
	}
	l=0; r=1e9;;
	while (r-l>=e)
	{
		mid=(l+r)/2;
		if (check(mid))
		{
			l=mid+e;
			bo=mid;
		} else r=mid-e;
	}
	cout<<bo<<endl;
}
