#include<bits/stdc++.h>
#define fori(i,a,b) for(i=a;i<=b;i++)
#define ford(i,a,b) for(i=a;i>=b;i--)
typedef long long ll;
typedef double db;
using namespace std;
const int N=1e5+5;
ll T,x,y,z,num,n,i,bo,c[N],d[N],tag[N];
void scd(ll len,ll x)
{
	ll i;
	if (x==0) 
	{
		bo=true;
		return;
	}
	ford(i,min(min(n,x),c[len-1]-1),1)
	if (!tag[i])
	{
		if (x-i>i*(i-1)/2) break;
		c[len]=i;
		scd(len+1,x-i);
		if (bo==true) return;
	}
}
void sc(ll len,ll x)
{
	ll i;
	if (x==0) 
	{
		scd(1,y);
		return;
	}
	ford(i,min(min(n,x),d[len-1]-1),1)
	{
		if (x-i>i*(i-1)/2) break;
		d[len]=i;
		tag[i]=true;
		sc(len+1,x-i);
		tag[i]=false;
		if (bo==true) return;
	}
}
int main()
{
	freopen("b.in","r",stdin); freopen("b.out","w",stdout);
	cin>>T;
	while (T--)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		num=x+y+z;
		n=(sqrt((ll)1+8*num)-1)/2;
		if (x<y) swap(x,y);
		if (y<z) swap(y,z);
		if (x<y) swap(x,y);
		d[0]=1e15;
		c[0]=1e15;
		bo=false;
		sc(1,z);
		if (bo) puts("1");
		else puts("0");
	}
}
