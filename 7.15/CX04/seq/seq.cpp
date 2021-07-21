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
ll tree[N],a[N],w[N],num[N];
ll n,m,i,T,ops,numd,x,y,z,las,j,now;
ll lowbit(ll x)
{
	return x&(-x);
}
void add(ll x,ll y)
{
	ll i;
	for (i=x;i<=n;i+=lowbit(i)) tree[i]+=y;
}
ll sum(ll x)
{
	ll i,w;
	w=0;
	for (i=x;i>=1;i-=lowbit(i)) w+=tree[i];
	return w;
}
int main()
{
	freopen("seq.in","r",stdin); freopen("seq.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		memset(tree,0,sizeof(tree));
		fori(i,1,n) 
		{
			scanf("%lld",&a[i]);
			add(i,a[i]);
			add(i+1,-a[i]);
		}
		fori(i,1,m)
		{
			numd=0;
			scanf("%lld",&ops);
			if (ops==1)
			{
				w[1]=-a[1];
		fori(j,2,n)
		{
			if (a[j-1]-a[j]>0)
			{
				w[j]=w[j-1]+a[j-1]-a[j];
				num[j]=0;
			} else
			{
				w[j]=w[j-1];
				if (a[j-1]-a[j]<0) num[j]=1;
				else num[j]=2;
			}
		}
		        fori(j,2,n)
		        if (num[j]==1&&num[j-1]==0) numd++;
				printf("%lld %lld\n",w[n]+a[n],numd*2);
			}
			if (ops==0)
			{
				scanf("%lld%lld%lld",&x,&y,&z);
				fori(j,x,y) a[j]+=z;	
			}
		}
	}
}
