#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
typedef __int128 lll;
const int N=3005;
int n,m,i,x,y,w[N][N],a[N],num,j,bo;
int main()
{
	freopen("c.in","r",stdin);
	cin>>n>>m;
	fori(i,1,m)
	{
		scanf("%lld%lld",&x,&y);
		w[x][y]=true;
		w[y][x]=true;
	}
	fori(i,1,n) w[i][i]=true;
	freopen("c.out","r",stdin);
	fori(i,1,m)
	{
		cin>>num;
		fori(j,1,num)
		cin>>a[j];
		bo=true;
		fori(j,2,num)
		if(!w[a[j]][a[j-1]]) bo=false;
		if(!w[a[1]][a[num]]) bo=false;
		if (bo==false) printf("%d",i);
	}
	puts("123456789");
}
