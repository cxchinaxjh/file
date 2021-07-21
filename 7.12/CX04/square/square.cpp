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
ll n,i,x[N],ans,len,j,ans1,k,ddd,p[201],a[N][201],w[N],gf[N],gl[N];
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
ll gcd(ll x,ll y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	freopen("square.in","r",stdin); freopen("square.out","w",stdout);
	cin>>n;
	fori(i,2,1000)
	 if (prime(i))
	 {
	 	len++;
	 	p[len]=i;
	 }
	 
	 fori(i,1,n) scanf("%lld",&x[i]);
	 ddd=x[1];
	fori(i,2,n)
	ddd=gcd(ddd,x[i]);
	fori(i,1,n)
	x[i]/=ddd;
	 ans=1;
	fori(i,1,n)
	{	
		w[i]=1;
		fori(j,1,len)
		{
			while (x[i]%p[j]==0)
	    	{
	     		x[i]/=p[j];
	     		a[i][j]++;
	    	}
	    	if (a[i][j]%2) w[i]=w[i]*p[j]%Mod;
		}
		w[i]=w[i]*x[i]%Mod;
		ans=ans*w[i]%Mod;
	}
	

	gf[1]=w[1];
	fori(i,2,n)
	gf[i]=gcd(gf[i-1],w[i]);
	
	gl[n]=w[n];
	ford(i,n-1,1)
	gl[i]=gcd(gl[i+1],w[i]);
	
	ans1=1;
	//cout<<ans<<endl;
	fori(i,2,n-1)
	{
		k=gcd(gf[i-1],gl[i+1]);
		//cout<<k<<endl;
		w[i-1]/=k;
		w[i+1]/=k;
		ans1=ans1*k%Mod;
	}
	if (n>=3)
	{
	k=gl[2];
	w[2]/=k;
	w[3]/=k;
	ans1=ans1*k%Mod;
	k=gf[n-1];
	w[n-1]/=k;
	w[n-2]/=k;
	ans1=ans1*k%Mod;
	}
	//cout<<ans1<<endl;
	cout<<ans*qpow(ans1,Mod-2)%Mod<<endl;
}
