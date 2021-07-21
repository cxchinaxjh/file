#include<bits/stdc++.h>
#define fori(i,a,b) for(i=a;i<=b;i++)
#define ford(i,a,b) for(i=a;i>=b;i--)
typedef long long ll;
typedef double db;
using namespace std;
const int Mod=1e9+7;
const int N=1e6+5;
const int ji=2000000016;
const int kk=65536;
struct node
{
	ll l,r,now,las,add;
}tr[N];
ll n,a[N],x,y,z,op,m,i,ww;
ll w[kk+5][2][2],w1[kk+5][2][2],j,k;
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
inline void mul(ll f[2],ll a[2][2])
{
	ll c[2],j,k;
	memset(c,0,sizeof(c));
	fori(j,0,1)
	 fori(k,0,1)
	 c[j]=(c[j]+f[k]*a[k][j])%Mod;
	 memcpy(f,c,sizeof(c));
}

inline void muld(ll a[2][2],ll b[2][2],ll c[2][2])
{
	ll i,j,k;
	memset(c,0,sizeof(c));
	fori(i,0,1)
	 fori(j,0,1)
	  fori(k,0,1)
	  c[i][j]=(c[i][j]+a[i][k]*b[k][j])%Mod;
}

inline ll fib(ll x,ll las,ll now)
{
	ll len,xx,a[2][2];
	ll f[2]={las,now};
	if (x==0)
	{
		ww=now;
		return las;
	}
	memset(a,0,sizeof(a));
	xx=x/65536;
	x%=65536;
	if (xx>0&&x>0) muld(w[x],w1[xx],a);
	else
	{
		if (x>0)
		{
			a[0][0]=w[x][0][0];
	    	a[0][1]=w[x][0][1];
	    	a[1][0]=w[x][1][0];
	    	a[1][1]=w[x][1][1];
		}
		if (xx>0)
		{
			a[0][0]=w1[xx][0][0];
	    	a[0][1]=w1[xx][0][1];
	    	a[1][0]=w1[xx][1][0];
	    	a[1][1]=w1[xx][1][1];
		}
	}
	mul(f,a);
	ww=f[1]%Mod;
	return f[0]%Mod;
}

inline void build(ll k,ll l,ll r)
{
	ll mid;
	tr[k].l=l;
	tr[k].r=r;
	if (l==r)
	{
	    tr[k].las=fib(a[l]-1,0,1);
		tr[k].now=ww;
		/*if (l==r) 
	    {
	    	cout<<l<<' '<<tr[k].now<<endl;
		}*/
		return;
	}
	mid=(l+r)>>1;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	tr[k].now=(tr[k*2].now+tr[k*2+1].now)%Mod;
	if (tr[k].now>=Mod) tr[k].now-=Mod;
	tr[k].las=(tr[k*2].las+tr[k*2+1].las)%Mod;
	if (tr[k].las>=Mod) tr[k].las-=Mod;
}

inline void pushdown(ll k)
{
	ll las,now;
	if (tr[k].add==0) return;
	if (tr[k].add>ji) tr[k].add-=ji;
	tr[k*2].add+=tr[k].add;
	tr[k*2+1].add+=tr[k].add;
	if (tr[k*2].add>ji) tr[k*2].add-=ji;
	if (tr[k*2+1].add>ji) tr[k*2+1].add-=ji;
	las=fib(tr[k].add,tr[k*2].las,tr[k*2].now);
	now=ww;
	tr[k*2].las=las;
	tr[k*2].now=now;
	las=fib(tr[k].add,tr[k*2+1].las,tr[k*2+1].now);
	now=ww;
	tr[k*2+1].las=las;
	tr[k*2+1].now=now;
	tr[k].add=0;
}

inline void change(ll k,ll x,ll y,ll z)
{
	ll mid,las,now;
	pushdown(k);
	if (tr[k].l>=x&&tr[k].r<=y)
	{
		if (z>ji) z-=ji;
		tr[k].add+=z;
		if (tr[k].add>ji) tr[k].add-=ji;
		las=fib(z,tr[k].las,tr[k].now);
		now=ww;
		tr[k].now=now;
		tr[k].las=las;
		return;
	}
	mid=(tr[k].l+tr[k].r)>>1;
	if (x<=mid) change(k*2,x,y,z);
	if (y>mid) change(k*2+1,x,y,z);
	tr[k].now=tr[k*2].now+tr[k*2+1].now;
	if (tr[k].now>=Mod) tr[k].now-=Mod;
	tr[k].las=tr[k*2].las+tr[k*2+1].las;
	if (tr[k].las>=Mod) tr[k].las-=Mod;
}

inline ll query(ll k,ll x,ll y)
{
	ll mid,w;
	pushdown(k);
	if (tr[k].l>=x&&tr[k].r<=y) return tr[k].now;
	mid=(tr[k].l+tr[k].r)>>1;
	w=0;
	if (x<=mid) w+=query(k*2,x,y);
	if (w>=Mod) w-=Mod;
	if (y>mid) w+=query(k*2+1,x,y);
	if (w>=Mod) w-=Mod;
	return w;
}

int main()
{
	//freopen("a.in","r",stdin); freopen("a.out","w",stdout);
	n=read(); m=read();
	fori(i,1,n) a[i]=read();
	w[1][0][1]=1;
	w[1][1][0]=1;
	w[1][1][1]=1;
	fori(i,2,kk)
		muld(w[1],w[i-1],w[i]);
	fori(j,0,1)
		 fori(k,0,1)
		 w1[1][j][k]=w[kk][j][k],
		 w1[0][j][k]=w[0][j][k];
	fori(i,2,kk)
	    muld(w1[1],w1[i-1],w1[i]);
	build(1,1,n);
	fori(i,1,m)
	{
		op=read();
		if (op==1)
		{
			x=read(); y=read(); z=read();
			change(1,x,y,z);
		}
		if (op==2)
		{
			x=read(); y=read();
			printf("%lld\n",query(1,x,y)%Mod);
		}
	}
}
