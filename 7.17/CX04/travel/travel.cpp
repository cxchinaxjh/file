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
vector<ll> c[N];
ll a[N],ru[N],q[N],num[N],las[N],nxt[N],to[N],fa[N],dfn[N],low[N],v[N],stacks[N],color[N],b[N],ct[N],cw[N],d[N];
ll n,i,x,y,l,j,l0,rr,mid,r,w,len,ans,numd,top,color_num,numb,co,bo,lend;
void add(ll x,ll y)
{
	to[++len]=y;
	nxt[len]=las[x];
	las[x]=len;
}
void tarjan(ll x)
{
    dfn[x]=++numd;
    low[x]=numd;
    v[x]=true;
    stacks[++top]=x;
    ll i;
        int y;
        y=fa[x];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        } else if (v[y]) low[x]=min(low[x],dfn[y]);
    if (low[x]==dfn[x])
    {
        int k;
        color_num++;
        ct[color_num]=numb+1;
        while (stacks[top]!=x)
        {
            k=stacks[top];
            v[k]=false;
            color[k]=color_num;
            b[++numb]=a[k];
            top--;
        }
        k=stacks[top];
        v[k]=false;
        color[k]=color_num;
        b[++numb]=a[k];
        cw[color_num]=numb;
        top--;
    }
}
void dfs(ll x)
{
	ll i,pos,w,temp;
	for(i=las[x];i;i=nxt[i])
	{
		w=c[to[i]][0];
		if (w>d[lend])
		{
			lend++;
			ans=max(ans,lend);
			d[lend]=w;
			dfs(to[i]);
			d[lend]=0;
			lend--;
		}
		else {
			pos=lower_bound(d+1,d+1+lend,w)-d;
			temp=d[pos];
	    	d[pos]=w;
	    	dfs(to[i]);
	    	d[pos]=temp;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin); freopen("travel.out","w",stdout);
	cin>>n;
	fori(i,1,n)
	 scanf("%lld",&a[i]);
	fori(i,1,n)
	{
		scanf("%lld",&x);
		fa[i]=x;
		//add(x,i);
		//ru[i]++;
	}
	fori(i,1,n)
	if (dfn[i]==0) tarjan(i);
	//cout<<color_num<<endl;
	fori(i,1,color_num)
	{
		sort(b+ct[i],b+cw[i]+1);
		c[i].push_back(b[ct[i]]);
		fori(j,ct[i]+1,cw[i])
		 if (b[j]!=b[j-1]) 
		 	c[i].push_back(b[j]);
		ans=max(ans,(ll)c[i].size());
	}
	fori(i,1,n)
	if (color[i]!=color[fa[i]])
	{
		add(color[fa[i]],color[i]);
		ru[color[i]]++;
	}
	ans=0;
	fori(i,1,color_num)
	if (ru[i]==0) 
	{
		fori(j,0,c[i].size()-1)
		d[j+1]=c[i][j];
		lend=c[i].size();
		ans=max(ans,lend);
		dfs(i);
		fori(j,0,c[i].size()-1)
		d[j+1]=0;
	}
	cout<<ans<<endl;
}
