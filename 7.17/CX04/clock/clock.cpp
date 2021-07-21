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
int h,m,ans;

inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

int main()
{
	freopen("clock.in","r",stdin); freopen("clock.out","w",stdout);
	h=read(); m=read();
	ans=h;
	if (h>=12)
	{
		ans=11+h%12;
		h%=12;
	}
	if (11*m>=h*60) ans++;
	cout<<ans<<endl;
}
