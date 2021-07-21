#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=500005;
const int M=205;
int n,m,k,i,j,ans,f[N][M];
string s1,s2;
int main()
{
	freopen("c.in","r",stdin); freopen("c.out","w",stdout);
	cin>>n>>m>>k;
	cin>>s1>>s2;
	if (n-m>k||m-n>k)
	{
		puts("-1");
		return 0;
	}
	fori(i,1,m)
	{
		fori(j,max(1,i-k),min(i+k,n))
    	{
	    	f[i][j-i]=max(f[i-1][j-i+1],f[i][j-i-1]);
	     	if (s2[i-1]==s1[j-1])
	     	f[i][j-i]=max(f[i][j-i],f[i-1][j-i]+1);
		    //printf("%d ",f[i][j-i]);
	    }
	    //printf("\n");
	}
	
	ans=f[m][min(m+k,n)-m];
	//cout<<ans<<endl;
	if (n+m-2*ans>k) puts("-1");
	else printf("%d\n",n+m-2*ans);
}
