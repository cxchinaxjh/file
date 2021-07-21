#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int M=5e6;
const int N=1e6;
struct node
{
	ll l,r,ans,num;
}q[M];
struct node1
{
	ll min,max;
}e[M];
ll tree[M],n,m,i,x,y;
ll len;
ll lowbit(ll x)
{
	return x&(-x);
}
void add(ll x,ll y)
{
	int i;
	for (i=x;i<=N;i+=lowbit(i))
	tree[i]+=y;
}
ll gans(ll x)
{
	int i,ans;
	ans=0;
	for (i=x;i>=1;i-=lowbit(i))
		ans+=tree[i];
	return ans;
}
bool cmp(node a,node b)
{
	return a.l<b.l;
}
bool cmp1(node a,node b)
{
	return a.num<b.num;
}
bool cmp2(node1 a,node1 b)
{
	return a.min<b.min;
}
int main()
{
	//freopen("d.in","r",stdin); freopen("d.out","w",stdout);
	cin>>n>>m;
	fori(i,1,n-1)
	{
		scanf("%lld%lld",&x,&y);
		e[i].min=min(min(x,y),i);
		e[i].max=max(max(x,y),i);
		add(e[i].max,1);
	}
	sort(e+1,e+n,cmp2);
	fori(i,1,m)
	{
		scanf("%lld%lld",&q[i].l,&q[i].r);
		q[i].num=i;
	}
	len=1;
	sort(q+1,q+1+m,cmp);
	fori(i,1,m)
	{
		while (e[len].min<q[i].l&&len<n) 
		{
			//cout<<e[len].max<<endl;
			add(e[len].max,-1);
			len++;
			//cout<<"  "<<len<<endl;
		}
		//cout<<0<<endl;
		q[i].ans=gans(q[i].r);
		//cout<<q[i].l<<' '<<q[i].r<<endl;
    }
	sort(q+1,q+1+m,cmp1);
	fori(i,1,m)
	printf("%lld\n",q[i].r-q[i].l+1-q[i].ans);
}
