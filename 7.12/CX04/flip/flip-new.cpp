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
#define int long long
const int N=1005;
struct
{
	int x,y;
}q[N*N];
int fa1[N][N],fa2[N][N],tag[N][N],up[N],down[N],ans[N*N];
int n,m,i,j,anss,k;
int gfa1(int x,int y)
{
	if (fa1[x][y]==y) return y;
	fa1[x][y]=gfa1(x,fa1[x][y]);
	return fa1[x][y];
}
int gfa2(int x,int y)
{
	if (fa2[x][y]==y) return y;
	fa2[x][y]=gfa2(x,fa2[x][y]);
	return fa2[x][y];
}
signed main()
{
	//freopen("flip.in","r",stdin); freopen("flip.out","w",stdout);
	cin>>n>>m;
	fori(i,1,n*m) scanf("%lld%lld",&q[i].x,&q[i].y);
	fori(i,0,m+1)
	 fori(j,0,n+1) 
	 {
	 	fa1[i][j]=j;
	 	fa2[i][j]=j;
	 }
	ford(i,n*m,1)
	{
		//cout<<0<<endl;
		
		tag[q[i].x][q[i].y]=true;
		fa1[q[i].y][q[i].x]--;
		fa2[q[i].y][q[i].x]++;
		up[q[i].y]=gfa2(q[i].y,q[i].x)-q[i].x;
		//cout<<up[q[i].y]<<endl;
		down[q[i].y]=q[i].x-gfa1(q[i].y,q[i].x);
		//cout<<down[q[i].y]<<endl;
		fori(j,q[i].y+1,m)
		if (!tag[q[i].x][j]) break;
		else {
			up[j]=min(gfa2(j,q[i].x)-q[i].x,up[j-1]);
			down[j]=min(q[i].x-gfa1(j,q[i].x),down[j-1]);
		}
		ford(j,q[i].y-1,1)
		if (!tag[q[i].x][j]) break;
		else {
			up[j]=min(gfa2(j,q[i].x)-q[i].x,up[j+1]);
			down[j]=min(q[i].x-gfa1(j,q[i].x),down[j+1]);
		}
	    //cout<<0<<endl;
		anss=0;
		fori(j,q[i].y,m)
		{
			if (!tag[q[i].x][j]) break;
			ford(k,q[i].y,1)
			{
				if (!tag[q[i].x][k]) break;
				anss+=min(up[j],up[k])*min(down[j],down[k]);
			}
		}
		ans[i]=ans[i+1]+anss;
	}
	fori(i,2,n*m+1)
	printf("%lld\n",ans[i]);
}

