#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
ll n,m,l,r,bo,mid;
bool ye;
ll qpow(ll x,ll y)
{
	if (y==0) return 1;
	if (y==1) return x;
	ll w;
	w=qpow(x,y/2);
	if (w>n)
	{
		ye=false;
		w%=n;
	}
	if (y%2==0) 
	{
		if (w*w>n)
		{
			ye=false;
			return w*w%n;
		}
		return w*w;
	}
	else {
		if (w*w>n)
		{
			ye=false;
			return w*w%n*x%n;
		}
		if (w*w*x>n)
		{
			ye=false;
			return w*w*x%n;
		}
		return w*w*x;
	}
}
bool check(ll x)
{
	if (x>n) return false;
	ye=true;
	qpow(x,m);
	return ye;
}
int main()
{
	freopen("a.in","r",stdin); freopen("a.out","w",stdout);
	cin>>n>>m;
	l=1; r=n;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid))
		{
			bo=mid;
			l=mid+1;
		} else r=mid-1;
	}
	cout<<bo<<endl;
}
