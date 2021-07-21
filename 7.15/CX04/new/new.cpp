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
int n,m,v,i,val[20],d[20],p[20];
int main()
{
	freopen("new.in","r",stdin); freopen("new.out","w",stdout);
	cin>>n>>m>>v;
	fori(i,1,n) cin>>val[i];
	fori(i,1,n) cin>>d[i];
	fori(i,1,n) cin>>p[i];
	if (val[2]>val[1])
	{
		cout<<d[1]*p[1]+d[2]*p[2];
		return 0;
	}
	else {
		cout<<d[1]*p[1]+d[2]*p[2];
		return 0;
	}
}
