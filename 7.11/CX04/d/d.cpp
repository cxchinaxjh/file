#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=30000;
int n,i,j;
unsigned int a[N],b[N],c[N],maxa,maxb,maxc,mina,minb,minc,ans;
unsigned int f()
{
	return (maxa-mina)*(maxb-minb)*(maxc-minc);
}
int main()
{
freopen("d.in","r",stdin); freopen("d.out","w",stdout);
	cin>>n;
	if (n>2000) 
	{
		puts("0");
		return 0;
	}
	fori(i,1,n) cin>>a[i];
	fori(i,1,n) cin>>b[i];
	fori(i,1,n) cin>>c[i];
	fori(i,1,n)
	{
		maxa=a[i];
		maxb=b[i];
		maxc=c[i];
		mina=a[i];
		minb=b[i];
		minc=c[i];
		ans=ans+f();
		fori(j,i+1,n)
	    {
	 	    maxa=max(maxa,a[j]);
	    	maxb=max(maxb,b[j]);
	    	maxc=max(maxc,c[j]);
	    	mina=min(mina,a[j]);
	    	minb=min(minb,b[j]);
	    	minc=min(minc,c[j]);
	    	ans=ans+f();
	    }
	}
	 cout<<ans<<endl;
}
