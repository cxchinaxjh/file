#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,b) for(i=a;i<=b;i++)
#define ford(i,a,b) for(i=a;i>=b;i--)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N=2005;
ll n,i,j,a[N],k,l[N][N],f[N][N];
ull ans;
int main()
{
	freopen("d.in","r",stdin); freopen("d.out","w",stdout);
	cin>>n;
	if (n>1000)
	{
		fori(i,1,n)
	    scanf("%lld",&a[i]);
	    fori(i,1,n)
	    ans+=a[i]*i*(n-i+1);
	    cout<<ans<<endl;
	    return 0;
	}
	fori(i,1,n)
	scanf("%lld",&a[i]);
	fori(i,1,n)
	{
		l[i][i]=a[i];
		f[i][i]=a[i];
		k=a[i];
		fori(j,i+1,n)
	    {
	    	k=k+a[j];
	    	l[i][j]=max(l[i][j-1],k);
	    }
	}
	fori(i,1,n-1)
	{
		fori(j,1,n-i)
		f[j][j+i]=max(l[j][j+i],f[j+1][j+i]);
	}
	fori(i,1,n)
	 fori(j,i,n)
	 ans+=f[i][j];
	cout<<ans<<endl;
}
