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
const ld eps=1e-7;
struct node
{
	ll x,y;
	ld z;
}e[N];
ll fa[N],x[N],y[N],a[N],b[N];
ll n,m,i;
ld ans,l,r,mid,w;
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline bool cmp(node a,node b)
{
	return a.z<b.z;
}
inline ll gfa(ll x)
{
	if (x==fa[x]) return x;
	fa[x]=gfa(fa[x]);
	return fa[x];
}
inline ld kruskal()
{
	ll i;
	ld anss;
	fori(i,1,n) fa[i]=i;
	anss=0;
	sort(e+1,e+1+m,cmp);
	fori(i,1,m)
	if (gfa(e[i].x)!=gfa(e[i].y))
	{
		fa[fa[e[i].y]]=fa[e[i].x];
		anss+=e[i].z;
	}
	return anss;
}
inline ld check(ld xx)
{
	ll i;
	fori(i,1,m)
	{
		e[i].x=x[i];
		e[i].y=y[i];
		e[i].z=(ld)a[i]*xx+(ld)b[i];
	}
	return kruskal();
}
int main()
{
	freopen("b.in","r",stdin); freopen("b.out","w",stdout);
	cin>>n>>m;
	fori(i,1,m)
	{
		x[i]=read();
		y[i]=read();
		a[i]=read();
		b[i]=read();
	}
	cin>>l>>r;
	ans=-1e100;
	while (r-l>=eps)
	{
		mid=(l+r)/2;
		w=check(mid);
		ans=max(ans,w);
		if (w>check(mid+eps)) r=mid-eps;
		else l=mid+eps;
	}
	printf("%0.3f",(db)ans);
}
