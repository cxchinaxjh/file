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
vector<ll> a[10];
ll T,i,n,l,r;
ll ji(ll x,ll y)
{
	if (x%2==1) return (y-x+2)/2;
	else return (y-x+1)/2;
}
ll k(ll x)
{
	ll w,i,ans,l,r,t;
	w=1+sqrt(1+x);
	ans=w;
	if (w%2==1) ans-=(1+(w-1)/2)*(w-1)/2;
	else  ans-=(1+(w-1)/2)*((w-1)/2)+w/2;
	t=x/w;
	r=w;
	l=x/(t+1)+1;
	while (r>=1)
	{
		//cout<<l<<' '<<r<<endl;
		if (l>=1) 
		{
			ans+=(r-l+1)*(t/2);
			if(t%2==0)  ans-=ji(l,r);
		}
		else {
			ans+=r*(t/2);
			if(t%2==0)  ans-=ji(1,r);
		}
		if (l<=1) break;
		t=x/(l-1);
		r=l-1;
    	l=x/(t+1)+1;
	}
	return ans;
}
ll kk(ll x)
{
	ll w,i,ans,l,r,t;
	w=1+sqrt(1+x);
	ans=0;
	fori(i,1,w)
	ans+=(x/i-i+2)/2;
	return ans;
}
int main()
{
	//freopen("equation.in","r",stdin); freopen("equation.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>l>>r;
		//cout<<kk(r)-kk(l-1)<<endl;
		cout<<k(r)-k(l-1)<<endl; 
	}
}

