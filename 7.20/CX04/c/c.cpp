#include<bits/stdc++.h>
#define fori(i,a,b) for(i=a;i<=b;i++)
#define ford(i,a,b) for(i=a;i>=b;i--)
typedef long long ll;
typedef double db;
using namespace std;
const int N=505;
const int M=1e6+5;
string s[N];
ll n,m,i,j,x,y,xx,yy,qq,bo,a[N][N],q1[M],q2[M],vis[N][N];
void dfs(ll x,ll y)
{
	vis[x][y]=true;
	if (x==xx&&y==yy) 
	{
		bo=true;
		return;
	}
	if (a[x+1][y]==0&&!vis[x+1][y]) dfs(x+1,y);
	if (a[x][y+1]==0&&!vis[x][y+1]) dfs(x,y+1);
}
int main()
{
	freopen("c.in","r",stdin); freopen("c.out","w",stdout);
	cin>>n>>m>>qq;
	fori(i,1,n)
		cin>>s[i];
	fori(i,1,n)
	 fori(j,1,m)
	 a[i][j]=s[i][j-1]-'0';
	fori(i,0,n+1) 
	 a[i][0]=1,a[i][m+1]=1;
	fori(i,0,m+1)
	 a[0][i]=1,a[n+1][i]=1;
	fori(i,1,qq)
	{
		memset(vis,0,sizeof(vis));
		scanf("%lld%lld%lld%lld",&x,&xx,&y,&yy);
		bo=false;
		dfs(x,y);
		if (bo) puts("Yes");
		else puts("No");
	}
}
