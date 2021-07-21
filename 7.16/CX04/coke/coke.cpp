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
ll n,kong,ans;
int main()
{
	freopen("coke.in","r",stdin); freopen("coke.out","w",stdout);
	cin>>n;
	while (n>1)
	{
		kong+=n/2;
		ans+=n/2;
		n%=2;
		n+=kong/3;
		kong%=3;
	}
	cout<<ans<<endl;
}
