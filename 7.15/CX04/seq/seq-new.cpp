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
ll n,m,i,T,ops,numd,x,y,z,las,j,now,ans;
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
void addx(ll x,ll y)
{
	ll i;
	for (i=x;i<=n;i+=lowbit(i)) tr[i]+=y;
}
ll sumx(ll x)
{
	ll i,w;
	w=0;
	for (i=x;i>=1;i-=lowbit(i)) w+=tr[i];
	return w;
}
int main()
{
	//freopen("seq.in","r",stdin); freopen("seq.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		ans=0;
		memset(tree,0,sizeof(tree));
		fori(i,1,n) 
		{
			scanf("%lld",&a[i]);
			add(i,a[i]);
			add(i+1,-a[i]);
			if (i>1) 
			{
				ans+=max(a[i]-a[i-1],(ll)0);
				num[i]=a[i]-a[i-1];
				addx(i,a[i]-a[i-1]);
			}
		}
		num[1]=-10;
		fori(i,2,n)
		if (num[i]>=0)
		{
			if (num[i-1]<0)
	    	{
	    		sum++;
	    		l[i]=i;
	    		r[i]=i;
	    	} else {
	    		r[l[i-1]]=i;
	    		l[i]=l[i-1];
	    		l[i-1]=0;
			}
		} else {
			if (num[i-1]>=0)
			{
				if (sumx(i-1)-sumx(l[i-1]-1)==0) sum0++;
			}
		}
		if (num[n]>=0)
		{
			if (sumx(n)-sumx(l[n]-1)==0) sum0++;
		}		
		fori(i,1,m)
		{
			numd=0;
			scanf("%lld",&ops);
			if (ops==1)
			{
				printf("%lld 0\n",ans);
			}
			if (ops==0)
			{
				scanf("%lld%lld%lld",&x,&y,&z);
				if (x>1) 
				{
					ans-=max(sum(x)-sum(x-1),(ll)0);
					addx(x,-(sum(x)-sum(x-1)));
				}
				if (y<n) 
				{
					ans-=max(sum(y+1)-sum(y),(ll)0);
					addx(y+1,-(sum(y+1)-sum(y)));
				}
				add(x,z);
				add(y+1,-z);
				if (x>1) 
				{
					w=sum(x)-sum(x-1);
					addx(x,w);
					if (num[x]>=0)
					{
						if (w>=0)
						{
							
						 } 
					}//las:num[x] now:w
					num[x]=w;
					ans+=max(num[x],(ll)0);
				}
				if (y<n) 
				{
					w=sum(y+1)-sum(y)
					addx(y+1,w);
					if (num[y+1]>=0)
					{
						if ()
					}
					num[y+1]=w;
					ans+=max(sum(y+1)-sum(y),(ll)0);
				}
			}
		}
	}
}
