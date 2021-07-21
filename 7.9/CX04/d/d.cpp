#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=1e6+5;
int lend,to[N],nxt[N],las[N],fa[N],dep[N],a[N],b[N];
int n,i,x,y,m;
void add(int x,int y)
{
	lend++;
	to[lend]=y;
	nxt[lend]=las[x];
	las[x]=lend;
}
void maketree(int x,int f)
{
	fa[x]=f;
	dep[x]=dep[f]+1;
	int i;
	for (i=las[x];i;i=nxt[i])
	if (to[i]!=f) maketree(to[i],x);
}
void del(int x,int y)
{
	int lena,lenb,ans,i;
	lena=0; lenb=0; ans=0;
	while (dep[x]>dep[y]){
		lena++;
		a[lena]=x;
		x=fa[x];
	}
	while (dep[x]<dep[y]){
		lenb++;
		b[lenb]=y;
		y=fa[y];
	}
	while (x!=y)
	{
		lena++;
		a[lena]=x;
		x=fa[x];
		lenb++;
		b[lenb]=y;
		y=fa[y];
	}
	lena++; a[lena]=x;
	ford(i,lenb,1)
	{
		lena++;
		a[lena]=b[i];
	}
	/*cout<<ans<<endl;
	fori(i,1,lena)
	cout<<i<<' '<<a[i]<<endl;*/
	fori(i,1,lena)
	if (a[i]==i-1) 
	{
		ans++;
		//cout<<i<<' '<<ans<<endl;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("d.in","r",stdin); freopen("d.out","w",stdout);
	cin>>n>>m;
	fori(i,1,n-1)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	maketree(1,0);
	fori(i,1,m)
	{
		scanf("%d%d",&x,&y);
		del(x,y);
	}
}
