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
ll m,n,i;
int main()
{
	freopen("math.in","r",stdin); freopen("math.out","w",stdout);
	cin>>n;
	m=n+1;
	if (n%2==0) n/=2;
	if (m%2==0) m/=2;
	fori(i,2,1e5)
	if (n%i==0||m%i==0)
	{
		cout<<n*m/i<<endl;
		return 0;
	}
	cout<<max(n,m)<<endl;
}
