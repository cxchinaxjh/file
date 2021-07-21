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

const int N=5005; 
const int M=1e6+5;
struct node
{
	ll x,c;
}d[M];

ll n,m,i,ans,len,tot[M],j,w[M],x[M],sum[N][N],f[N][N];

inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

ll fabs(ll x)
{
	if (x<0) return (-x);
	else return x;
}

bool cmp(node a,node b)
{
	return (a.x<b.x);
}
int main()
{
	freopen("mice.in","r",stdin); freopen("mice.out","w",stdout);
	cin>>n>>m;
	fori(i,1,n) x[i]=read();
	sort(x+1,x+1+n);
	fori(i,1,m) 
	{
		d[i].x=read();
		d[i].c=read();
	}
	sort(d+1,d+1+m,cmp);
	fori(i,1,m) tot[i]=tot[i-1]+d[i].c;
	if (tot[m]<n)
	{
		puts("-1");
		return 0;
	}
	if (n>5000||m>5000)
	{
		len=1;
		fori(i,1,n)
		{
			while (len<m&&fabs(x[i]-d[len].x)>fabs(x[i]-d[len+1].x)) len++;
			ans+=fabs(x[i]-d[len].x);
		}
		cout<<ans<<endl;
		return 0;
	}
	d[0].x=-1e15;
	d[m+1].x=1e15;
	fori(i,1,m)
	  fori(j,1,n)
	  sum[i][j]=sum[i][j-1]+fabs(x[j]-d[i].x);
	fori(i,1,m)
	  w[i]=lower_bound(x+1,x+1+n,(w[i-1]+w[i])/2+(w[i-1]+w[i])%2)-x;
	fori(i,1,n)
	 fori(j,1,m)
	 if (i<=tot[j]) 
	 {
	 	if (max(w[j],i-d[j].c)<=i) f[i][j]=f[max(w[j],i-d[j].c)][j-1]+sum[j][i]-sum[j][max(w[j],i-d[j].c)];
	      else {
	      	f[i][j]=f[min(i,tot[j-1])][j-1]+sum[j][i]-sum[j][min(i,tot[j-1])];
	        }
	 }
	cout<<f[n][m]<<endl;
}
