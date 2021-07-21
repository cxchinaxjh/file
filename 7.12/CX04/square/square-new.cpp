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
const int Mod=1000000007;
const int N=2e5+5;
const int M=2e6+5;
ll n,i,x[N],ans,len,j,ans1,k,ddd,p[201],a[N][201],num[M];
ll qpow(ll x,ll y)
{
	if (y==0) return 1;
	if (y==1) return x%Mod;
	ll w;
	w=qpow(x,y/2);
	if (y%2) return w*w%Mod*x%Mod;
	else return w*w%Mod;
}
bool prime(ll x)
{
	int i;
	bool bo;
	bo=true;
	fori(i,2,sqrt(x))
	if (x%i==0) return false;
	return true;
}
int main()
{
	//freopen("square.in","r",stdin); freopen("square.out","w",stdout);
	cin>>n;
	fori(i,2,1000)
	 if (prime(i))
	 {
	 	len++;
	 	p[len]=i;
	 }
	 
	 fori(i,1,n) scanf("%lld",&x[i]);
	 ans=1;
	fori(i,1,n)
	{	
		fori(j,1,len)
		{
			while (x[i]%p[j]==0)
	    	{
	     		x[i]/=p[j];
	     		a[i][j]++;
	    	}
	    	if (a[i][j]%2) num[p[j]]++;
		}
		if (x[i]>1)
			num[x[i]]++;
	}
	fori(i,2,1e6)
	{
		ans=ans*qpow(i,min(num[i],n-num[i]))%Mod;
		//cout<<num[i]<<endl;
	}
	
	cout<<ans<<endl;
}
