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
const int N=5005;
ll a[N],las[N],nxt[N],f[N][N],sum[N][N],k,t,n,m,i,j,w,l,r,ans;
int main()
{
	freopen("sequence.in","r",stdin); freopen("sequence.out","w",stdout);
	cin>>n;
	fori(i,1,n) scanf("%lld",&a[i]);
	cin>>m;
	fori(i,1,n)
	{
		nxt[i]=las[a[i]];
		las[a[i]]=i;
	}
	fori(i,1,n)
	{
		k=0;
		fori(j,i,n)
		{
			if (nxt[j]>=i) w=0;
			else w=1;
			k=k^w;
			f[i][j]=f[i][j-1]+k;
		}
	}
	fori(i,1,n)
	{
		fori(j,1,i)
		sum[j][i]=sum[j-1][i]+f[j][i];
	}
	fori(i,1,m)
	{
		ans=0;
		cin>>l>>r;
		ans=sum[r][r]-sum[l-1][r];
		cout<<ans<<endl;
	}
}
