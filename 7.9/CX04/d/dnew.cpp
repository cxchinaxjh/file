#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=3e6+5;
const int W=1e6;
const int M=5e5;
struct node
{
	int l,r,ans,lca;
}q[N];
vector<ll> num[N],v[N],numi[N],num1[N],v1[N],numi1[N];
int to[N],nxt[N],las[N],dep[N],f[M][25],t[N],t1[N];
int len,n,m,i,xx,yy;
void add(int x,int y)
{
	len++;
	to[len]=y;
	nxt[len]=las[x];
	las[x]=len;
}
void maketree(int x,int fa)
{
	int i;
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	fori(i,1,20)
	f[x][i]=f[f[x][i-1]][i-1];
	for(i=las[x];i;i=nxt[i])
	if (to[i]!=fa)
		maketree(to[i],x);
}
int LCA(int x,int y)
{
	int i;
	if (dep[x]<dep[y]) swap(x,y);
	for (i=20;i>=0;i--)
	if (dep[f[x][i]]>=dep[y]) x=f[x][i];
	if (x==y) return x;
	for (i=20;i>=0;i--)
	if (f[x][i]!=f[y][i])
	{
		x=f[x][i];
		y=f[y][i];
	}
	return f[x][0];
}
void deal(int x)
{
	int i;
	t[dep[x]+x]++;
	if (num[x].size()>0)
	{
		//cout<<numi[x].size()<<endl;
		fori(i,0,num[x].size()-1)
		{
			//cout<<1;
			//cout<<num[x][i]<<endl;
			q[numi[x][i]].ans+=v[x][i]*t[num[x][i]];
		}
		
	}
	
	//cout<<x<<endl;
	for(i=las[x];i;i=nxt[i])
	if (to[i]!=f[x][0])
		deal(to[i]);
	//cout<<x<<endl;
	t[dep[x]+x]--;
}
void did(int x)
{
	int i;
	t1[x-dep[x]+W]++;
	if (num1[x].size()>0)
	fori(i,0,num1[x].size()-1)
	{
		q[numi1[x][i]].ans+=v1[x][i]*t1[num1[x][i]];
		//if (numi1[x][i]==1) printf("%d %lld %lld %lld\n",x,v1[x][i],num1[x][i]-W,t1[num1[x][i]]);
	}
	for(i=las[x];i;i=nxt[i])
	if (to[i]!=f[x][0])
		did(to[i]);
	t1[x-dep[x]+W]--;
}
int main()
{
	cin>>n>>m;
	fori(i,1,n-1)
	{
		scanf("%d%d",&xx,&yy);
		add(xx,yy);
		add(yy,xx);
	}
	maketree(1,0);
	fori(i,1,m)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].lca=LCA(q[i].l,q[i].r);
		if (dep[q[i].lca]+q[i].lca==dep[q[i].l]) q[i].ans=1;
		num[q[i].l].push_back(dep[q[i].l]);
		v[q[i].l].push_back(1);
		numi[q[i].l].push_back(i);
		num[q[i].lca].push_back(dep[q[i].l]);
		v[q[i].lca].push_back(-1);
		numi[q[i].lca].push_back(i);
		num1[q[i].r].push_back(dep[q[i].l]-2*dep[q[i].lca]+W);
		v1[q[i].r].push_back(1);
		numi1[q[i].r].push_back(i);
		num1[q[i].lca].push_back(dep[q[i].l]-2*dep[q[i].lca]+W);
		v1[q[i].lca].push_back(-1);
		numi1[q[i].lca].push_back(i);
	}
	deal(1);
	//cout<<0<<endl;
	did(1);
	fori(i,1,m)
	printf("%d\n",q[i].ans);
	//lca special judge
}
