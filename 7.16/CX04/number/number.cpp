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
ll a[N],f[N],ff[N];
ll n,i,w,ans;
int main()
{
	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
	cin>>n;
	fori(i,1,n) scanf("%lld",&a[i]);
	w=a[1];
	f[1]=a[1];
	fori(i,2,n)
	{
		if (w<0) w=0;
		w+=a[i];
		f[i]=max(f[i-1],w);
	}
	ff[n]=a[n];
	w=a[n];
	ford(i,n-1,1)
	{
		if (w<0) w=0;
		w+=a[i];
		ff[i]=max(ff[i+1],w);
	}
	ans=max(f[n],ff[1]);
	fori(i,1,n-1)
	ans=max(ans,f[i]+ff[i+1]);
	cout<<ans<<endl;
}
