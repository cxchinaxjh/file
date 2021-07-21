#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=5e6+5;
const int M=2e6+5;
ll n,m,k,i,a[N],x,y,ans,jp[M][22],sum[N],qpow[N],nxt[N],j,b[N];
int main()
{
	freopen("c.in","r",stdin); freopen("c.out","w",stdout);
	cin>>n>>m>>k;
	qpow[0]=1;
	fori(i,1,20)
	qpow[i]=qpow[i-1]*2;
	fori(i,1,n) 
		scanf("%lld",&a[i]);
	fori(i,1,n) 
	sum[i]=sum[i-1]+a[i];
	fori(i,1,n)
	if (a[i]>k) 
	{
		a[i]=0;
		b[i]=1;
	}
	fori(i,1,n)
	{
		nxt[i]=upper_bound(sum+1,sum+1+n,sum[i-1]+k)-sum;
		b[i]=b[i-1]+b[i];
	}
		
	fori(j,0,20)
	jp[n+1][j]=n+1;
	ford(i,n,1)
	{
		jp[i][0]=nxt[i];
		fori(j,1,20)
		jp[i][j]=jp[jp[i][j-1]][j-1];
	}
	/*fori(i,1,n)
	cout<<nxt[i]<<endl;*/
	fori(i,1,m)
	{
		scanf("%lld%lld",&x,&y);
		ans=0;
		if (b[y]-b[x-1]>0) puts("Chtholly");
		else {
			while (x<=y)
			{
				ford(j,20,0)
				if (jp[x][j]<=y)
				{
					x=jp[x][j];
					ans+=qpow[j];
					break;
				}
				if (jp[x][0]>y)
				{
					x=jp[x][0];
					ans++;
				}
				//cout<<x<<endl;
			}
			printf("%lld\n",ans);
		}
	}
}
