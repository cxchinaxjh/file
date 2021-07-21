#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=2e6+5;
ll w[10],a[N],b[N],ans[10],l[10],r[10],num[N];
ll n,m,k,i,ro,re,len,x;
int wind(int x,int y)
{
	if (x==0)
	{
		if (y==1) return 1;
		if (y==2) return 2;
		if (y==0) return 0;
	}
	if (x==1)
	{
		if (y==2) return 1;
		if (y==0) return 2;
		if (y==1) return 0;
	}
	if (x==2)
	{
		if (y==0) return 1;
		if (y==1) return 2;
		if (y==2) return 0;
	}
}
int main()
{
	freopen("data.in","r",stdin); freopen("sol.out","w",stdout);
	cin>>n>>m>>x;
	fori(i,1,n) scanf("%lld",&a[i]);
	fori(i,1,n) scanf("%lld",&b[i]);
	fori(i,1,n)
	{
		num[i]=wind(a[i],b[i]);
		w[num[i]]++;
	} 
	ro=m/n;
	re=m%n;
	w[1]=w[1]*ro;
	w[2]=w[2]*ro;
	fori(i,1,re)
	w[wind(a[i],b[i])]++;
	num[0]=55;
	//single 
	fori(i,1,n)
	if (num[i]==num[i-1]) 
	{
		len++;
		if (len>=x) 
			l[num[i]]++;
	}
	else {
		len=1;
		if (len>=x) l[num[i]]++;
	}
	if (len==n)
	{
		if (m>=x) w[num[1]]+=m-x+1;
		cout<<w[1]<<' '<<w[2]<<endl;
		return 0;
	}
	fori(i,1,n)
	{
		a[i+n]=a[i];
		b[i+n]=b[i];
		num[i+n]=num[i];
	}
	fori(i,1,2*n)
	if (num[i]==num[i-1]) 
	{
		len++;
		if (len>=x) r[num[i]]++;
	}
	else {
		len=1;
		if (len>=x) r[num[i]]++;
	}
	//cout<<l[1]<<' '<<r[1]<<endl;
	//cout<<l[2]<<' '<<r[2]<<endl;
	if (ro>=1)
	{
		ans[1]=w[1]+(r[1]-l[1])*(ro-1)+l[1];
		ans[2]=w[2]+(r[2]-l[2])*(ro-1)+l[2];
		fori(i,1,n)
    	if (num[i]==num[i-1]) len++;
     	else len=1;
    	fori(i,n+1,n+re)
    	if (num[i]==num[i-1]) 
    	{
    		len++;
	     	if (len>=x) ans[num[i]]++;
    	}
     	else {
	    	len=1;
	    	if (len>=x) ans[num[i]]++;
    	}
	} else {
		ans[1]=w[1];
		ans[2]=w[2];
		fori(i,1,re)
    	if (num[i]==num[i-1]) 
    	{
    		len++;
	     	if (len>=x) ans[num[i]]++;
    	}
     	else {
	    	len=1;
	    	if (len>=x) ans[num[i]]++;
    	}
    }
    cout<<ans[1]<<' '<<ans[2]<<endl;
}
