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
const int b[3]={0,10000,250};
const int N=1e6+5;

ll n,i,j,p[N],w1,w2,ans,k,tr[N],f[N],w[N],tot,anss;
ull seed;
ull rd() 
{
    seed ^= seed << 13;
    seed ^= seed >> 7;
    seed ^= seed << 17;
    return seed;
}
ll lowbit(ll x)
{
	return x&(-x);
}
ll sum(ll x)
{
	ll ans,i;
	ans=0;
	for (i=x;i>=1;i-=lowbit(i))
	ans+=tr[i];
	return ans;
}
void add(ll x,ll y)
{
	ll i;
	for (i=x;i<=n;i+=lowbit(i))
	tr[i]+=y;
}
int main()
{
	//freopen("triple.in","r",stdin); freopen("triple.out","w",stdout);
	cin >> n >> seed;
    p[1]=1;
    fori(i,2,n) 
	{
        p[i]=i;
        swap(p[i], p[rd() % i + 1]);
    }
    fori(i,1,n)
    {
    	f[i]=sum(p[i]);
    	add(p[i],1);
	}
	//fori(i,1,n) cout<<f[i]<<endl;
	memset(tr,0,sizeof(tr));
	fori(i,1,n)
    {
    	w[i]=sum(p[i]);
    	tot+=w[i];
    	add(p[i],f[i]);
	}
	memset(tr,0,sizeof(tr));
	ford(i,n,1)
	{
		anss=sum(n)-sum(p[i]);
		anss=(anss-1)*anss/2;
		ans+=anss;
		add(p[i],1);
	}
	cout<<ans-tot<<endl;
}
