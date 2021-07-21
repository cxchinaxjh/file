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
const int N=1e6+5;
ll i,j,w,n,ans,k,t,di[N],tag[N];
int main()
{
	//freopen("disanti.in","r",stdin); freopen("disanti.out","w",stdout);
	fori(i,1,1e3)
	{
		for (j=1;j*i*i<=1e6;j++)
		tag[i*i*j]=i;
	}
	fori(i,1,1e6)
	di[i]=i/(tag[i]*tag[i]);
	cin>>n;
	fori(i,1,n)
	{
		fori(j,1,i-1)
		{
 			if (di[j]!=di[i-j])
			{
				w=2*tag[j*(i-j)];
				ans+=w-1;
				//cout<<i-j<<' '<<j<<' '<<w<<' '<<ans<<endl;
			 } 
		} 
	}
	ans/=2;
	/*fori(i,1,n)
	{
		fori(j,1,sqrt(i))
		{
 			fori(k,1,i-j*j)
 			if (di[k]!=1)
 			 {
 			 	fori(t,1,min(k,i-j*j-k))
 			 	if (di[t]!=1&&di[k]!=di[t])
 			 	{
 			 		if ((k*t)%(j*j)!=0) continue;
 			 		w=(k*t)/(j*j);
 			 		if (w>k&&j*j+k+t+w==i) ans++;
				  }
			  }
		} 
	}*/
	cout<<ans<<endl;
}
