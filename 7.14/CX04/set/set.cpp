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
vector<ll> w[N],v[N];
ll a[N],b[N],num[N],fa[N],vis[N],tag[N];
ll maxx,lenn,n,i,k,ans,j,len;
ll gfa(ll x)
{
	if (fa[x]==x) return x;
	fa[x]=gfa(fa[x]);
	return fa[x];
}
void check()
{
	ll i,j,w;
	w=0;
	//cout<<lenn<<endl;
	//fori(i,1,lenn) cout<<num[i]<<' ';
	//puts("");
	fori(i,1,lenn)
	if (vis[num[i]]) 
	{
		w+=a[num[i]];
		if (v[num[i]].size()>0)
		{
			//cout<<i<<' '<<v[num[i]].size()<<endl;
			fori(j,0,v[num[i]].size()-1)
			if (vis[v[num[i]][j]]) 
				w-=b[num[i]];
		}
	}
	maxx=max(maxx,w);
}
void sc(int x)
{
	//cout<<x<<' '<<lenn<<endl;
	if (x>lenn) 
	{
		check();
		return;
	}
	vis[num[x]]=true;
	sc(x+1);
	vis[num[x]]=false;
	sc(x+1);
}
ll deal(ll x)
{
	ll i;
	maxx=0;
	lenn=w[x].size();
	//cout<<lenn<<endl;
	fori(i,0,lenn-1)
	num[i+1]=w[x][i];
	sc(1);
}
int main()
{
	freopen("set.in","r",stdin); freopen("set.out","w",stdout);
	cin>>n;
	fori(i,1,n) scanf("%lld",&a[i]);
	fori(i,1,n) scanf("%lld",&b[i]);
	fori(i,1,n) fa[i]=i;
	fori(i,2,n)
	{
		k=i;
		fori(j,2,1000)
		{
			k*=i;
			if (k>n) break;
			v[k].push_back(i);
			fa[k]=fa[i];
		}
	}
	fori(i,1,n)
	{
		gfa(i);
		//cout<<fa[i]<<endl;
	}
	 
	fori(i,1,n)
	{
		if (tag[fa[i]]==0) tag[fa[i]]=++len;
		w[tag[fa[i]]].push_back(i);
	}
	fori(i,1,len)
	{
	    deal(i);
		ans=ans+maxx;
	}
	cout<<ans<<endl;	
}
