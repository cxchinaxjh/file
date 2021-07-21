#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N=1e5+5;
struct node
{
	int x,y;
	double c;
}e[N];
int n,m,fa[N];
pair<int,int> ed[N];
int q1[N],q2[N];
inline bool cmp(const node &x,const node &y)
{
	return x.c<y.c;
}
inline int find(int x){if(x==fa[x])return x;return fa[x]=find(fa[x]);}
inline double sum(double x)
{
	rep(i,1,n)fa[i]=i;
	rep(i,1,m)
	{
		e[i].x=ed[i].first,e[i].y=ed[i].second;
		e[i].c=1.0*q1[i]*x+q2[i];
	}
	sort(e+1,e+1+m,cmp);
	int t=n;double ans=0;
	rep(i,1,m)
	{
		int x1=e[i].x,x2=e[i].y;
		x1=find(x1);x2=find(x2);
		if(x1==x2)continue;
		t--;fa[x1]=x2;ans+=e[i].c;
		//printf("%.3lf\n",e[i].c);
		if(t==1)return ans;
	}
	return 0;
}
inline void judge()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
}
inline double ab(double x)
{
	return x<0 ? -x : x;
}
int main()
{	
	judge();
	scanf("%d%d",&n,&m);
	rep(i,1,m)
	{
		int x,y,c;scanf("%d%d%d%d",&x,&y,&q1[i],&q2[i]);
		ed[i].first=x,ed[i].second=y;
	}
	double l,r;int x,y;scanf("%d%d",&x,&y);
	l=x,r=y;
	int T=80;
	while(T--)
	{
		double midl=(l+l+r)/3.0,midr=(l+r+r)/3.0;
		double w1=sum(midl),w2=sum(midr);
		if(w1>w2) r=midr;
		else l=midl;
		if(ab(w2-w1)<=1e-4)break;
	}
	//printf("%.3lf %.3lf\n",l,r);
	printf("%.3lf\n",sum((l+r)/2.0));
	//for(int i=x;i<=y;i++)printf("%d %.3lf\n",i,sum(i));
	return 0;
}

