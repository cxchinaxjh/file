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
struct node
{
	int x,y,num,tag;
}a[N];
int n,m,i,ans[10][N];
bool cmp1(node a,node b)
{
	if (a.x<b.x||a.x==b.x&&a.y<b.y) return true;
	return false;
}
bool cmp2(node a,node b)
{
	if (a.y<b.y||a.y==b.y&&a.x<b.x) return true;
	return false;
}
int main()
{
	freopen("eat.in","r",stdin); freopen("eat.out","w",stdout);
	cin>>n>>m;
	fori(i,1,n)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].num=i;
		a[i].tag=1;
	}
	fori(i,n+1,n+m)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].num=i-n;
		a[i].tag=2;
	}
	sort(a+1,a+1+n+m,cmp1);
	fori(i,2,n+m)
	if (a[i].x==a[i-1].x&&a[i].tag!=a[i-1].tag)
	{
		ans[a[i].tag][a[i].num]=1;
		ans[a[i-1].tag][a[i-1].num]=1;
	}
	sort(a+1,a+1+n+m,cmp2);
	fori(i,2,n+m)
	if (a[i].y==a[i-1].y&&a[i].tag!=a[i-1].tag)
	{
		ans[a[i].tag][a[i].num]=1;
		ans[a[i-1].tag][a[i-1].num]=1;
	}
	fori(i,1,n)
	printf("%d",ans[1][i]);
	puts("");
	fori(i,1,m)
	printf("%d",ans[2][i]);
}
