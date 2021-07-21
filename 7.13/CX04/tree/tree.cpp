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
const int N=100;
int n,i,v[N],f[N],tag[N];
db anss,ans[N];
void pd()
{
	int i,num;
	db p;
	p=0; num=0;
	fori(i,1,n)
	if (tag[i])
	{
		if (num>0&&tag[f[i]]==false) return;
		p+=v[i];
 		num++;
	}
	p=p/(db)num;
	fori(i,1,n)
	if (tag[i]) ans[i]=max(ans[i],p);
}
void sc(int x)
{
	if (x>n)
	{
		pd();
		return;
	}
	tag[x]=true;
	sc(x+1);
	tag[x]=false;
	sc(x+1);
}
int main()
{
	freopen("tree.in","r",stdin); freopen("tree.out","w",stdout);
	cin>>n;
	fori(i,1,n) scanf("%d",&v[i]);
	fori(i,2,n) scanf("%d",&f[i]);
	anss=1e9;
	sc(1);
	fori(i,1,n) anss=min(anss,ans[i]);
	cout<<anss<<endl;
}
