#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=2e6+5;
const int M=5e6+5;
const int Mod=19260817;
vector<ll> w[N],son[N];
ll st[N],ins[N],tag[N],a[N][5],vis[N],to[M],las[N],nxt[M],sum[N],num[N],v[N];
ll slen,len,n,m,i,j,x,y,t,ss,s,elen,ans,k,ni2;
ll qpow(ll x,ll y)
{
	if (y==0) return 1;
	if (y==1) return x%Mod;
	ll w;
	w=qpow(x,y/2)%Mod;
	if (y%2==0) return w*w%Mod;
	else return w*w%Mod*x%Mod;
}
ll sq(ll x)
{
	return x*x%Mod;
}
ll ni(ll x)
{
	if (x==1) return 1;
	return qpow(x,Mod-2);
}
void dfs(ll x,ll fa)
{
	ll i,t;
	slen++;
	st[slen]=x;
	vis[x]=true;
	ins[x]=true;
	fori(i,1,a[x][0])
	{
		t=a[x][i];
		if (t==fa) continue;
		//printf("%d %d\n",x,t);
		if (!vis[t]) 
		dfs(t,x);
		if (ins[t])
		{
			len++;
			w[len].push_back(t);
			tag[t]=len;
			ins[t]=false;
			while (st[slen]!=t)
			{
				ins[st[slen]]=false;
				tag[st[slen]]=len;
				w[len].push_back(st[slen]);
				slen--;
			}
			slen--;
		}	
	}
	if (ins[x])
	{
		slen--;
		ins[x]=false;
		len++;
		tag[x]=len;
		w[len].push_back(x);
	}
}
void add(ll x,ll y)
{
	elen++;
	to[elen]=y;
	nxt[elen]=las[x];
	las[x]=elen;
}
void maketree(ll x,ll f)
{
	ll i,w1,w2,tot,totp;
	sum[x]=ss;
	if (v[x]==2) num[x]=sum[x]%Mod;
	ss*=v[x];
	ss%=Mod;
	//cout<<x<<endl;
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=f) 
	{
		son[x].push_back(to[i]);
		maketree(to[i],x);
		num[x]+=num[to[i]];
		num[x]%=Mod;
	}
	w1=ni(sum[x]);
	w2=ni(v[x]);
	//cout<<0<<endl;
	if (v[x]==2&&son[x].size()>0)
	{
		//cout<<son[x].size()<<endl;
		fori(i,0,son[x].size()-1)
		if (son[x][i]!=0)
		{
			ans+=num[son[x][i]]*w1%Mod*w2%Mod;
			ans%=Mod;
		}
    }
    //cout<<0<<endl;
	if (son[x].size()>1)
	{
		tot=0;
		totp=0;
		//cout<<0<<endl;
		fori(i,0,son[x].size()-1)
		if (son[x][i]!=0)
		{
			tot+=num[son[x][i]];
			tot%=Mod;
			totp+=sq(num[son[x][i]]);
			totp%=Mod;
		}
		ans+=((sq(tot)-totp)%Mod+Mod)%Mod*ni2%Mod*sq(w1)%Mod*w2%Mod;
		ans%=Mod;
	}
	//cout<<ans<<endl;
	ss*=w2;
	ss%=Mod;
}

int main()
{
	freopen("c.in","r",stdin); freopen("c.out","w",stdout);
	cin>>n>>m;
	fori(i,1,m)
	{
		scanf("%lld%lld",&x,&y);
		a[x][0]++;
		a[x][a[x][0]]=y;
		a[y][0]++;
		a[y][a[y][0]]=x;
	}
	dfs(1,0);
    fori(i,1,len)
	{
		fori(j,0,w[i].size()-1)
	    {
	    	fori(k,1,a[w[i][j]][0])
	    	{
	    		t=a[w[i][j]][k];
	    		if (tag[w[i][j]]!=tag[t]&&w[i][j]>t)
	    		{
	    			add(tag[w[i][j]],tag[t]);
	    			add(tag[t],tag[w[i][j]]);
				}
			}
		}
		if (w[i].size()>1) v[i]=2;
		else v[i]=1;
    }
    ni2=ni(2);
    ss=1;
    maketree(1,0);
    cout<<ans%Mod<<endl;
}
