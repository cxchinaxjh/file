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
ll a[N],minn[N],f[N][N];
bool tag[N][N];
ll n,m,i,j,ans;
ll fabs(ll x)
{
	if (x<0) return (-x);
	else return x;
}
int main()
{
	freopen("rating.in","r",stdin); freopen("rating.out","w",stdout);
	cin>>n>>m;
	fori(i,1,n) 
	   scanf("%lld",&a[i]);
	fori(i,1,n)
	 fori(j,i,n)
	 if (fabs(a[j]-a[i])>m) break;
	 else {
	 	tag[i][j]=true;
	 	//cout<<i<<' '<<j<<endl;
	 }
	 //puts("");
	fori(i,1,n)
	{
		minn[i]=n;
		ford(j,i,1)
		if (tag[j][i])
		{
			f[i][j]=minn[j-1]+1;
			minn[i]=min(minn[i],f[i][j]);
			//cout<<i<<' '<<j<<endl;
		}
	}
	ans=n;
	ford(j,n,1)
	if (tag[j][n]) ans=min(ans,f[n][j]);
	cout<<ans<<endl;
}
