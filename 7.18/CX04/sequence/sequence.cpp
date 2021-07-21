#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uin;
const int N=1e4+5;
struct node
{
	ll x,num;
};
ll a[N],powd[N],lend,q[N],n,i,k,j,tot,seed,p,w[N],f[N]; 
//typedef __int128 lll;
/*ll query(ll l,ll r)
{
	return ((hash[r]-hash[l]*powd[r-l+1])%p+p)%p; 
}*/
bool cmp(node a,node b)
{
	if (a.x<b.x||a.x==b.x&&a.num<b.num) return true;
	return false; 
}
void sc(ll num,ll x,ll hash)
{
	ll i;
	node b[N];
	if (x>n) return;
	fori(i,1,n) b[i].x=a[i],b[i].num=i;
	sort(b+x,b+1+n,cmp);
	fori(i,1,n)
	{
		q[num]=b[i].x;
		if (tot<k)
		{
			tot++;
			printf("%lld\n",(hash*seed%p+b[i].x)%p);
	    }
		sc(num+1,b[i].num+1,(hash*seed%p+b[i].x)%p);
	}
}
int main()
{
	freopen("sequence.in","r",stdin); freopen("sequence.out","w",stdout);
	cin>>n>>k>>seed>>p;
	powd[0]=1;
	fori(i,1,n)
	{
		scanf("%lld",&a[i]);
	}
	sc(1,1,0);
	
}
