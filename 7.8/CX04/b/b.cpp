#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,b) for(i=a;i<=b;i++)
#define ford(i,a,b) for(i=a;i>=b;i--)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N=2e5+5;
map<int,int> t,w;
int n,m,i,x,y,ans,las,j,len1,a[N],w1[N],nxt[N];
void deal(int k)
{
	int bo,l,r,mid;
	l=1; r=len1;
	bo=0;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (w1[mid]<=k)
		{
			bo=mid;
			l=mid+1;
		} else r=mid-1;
	}
	if (bo>0) ans=min(ans,k-w1[bo]);
	if (bo+1<=len1) ans=min(ans,w1[bo+1]-k);
}
int main()
{
	freopen("b.in","r",stdin); freopen("b.out","w",stdout);
	cin>>n>>m;
	fori(i,1,n) 
	{
		scanf("%d",&a[i]);
		if (t.find(a[i])==t.end()) 
		{
			t[a[i]]=i;
			w[a[i]]=i;
		} else {
			nxt[w[a[i]]]=i;
			w[a[i]]=i;
		}
	}
	ans=2147483647;
	fori(i,1,n)
	if (i==t[a[i]])
	{
		las=i;
		for(j=nxt[i];j;j=nxt[j])
		{
			ans=min(ans,j-las);
			las=j;
		}
	}
	fori(i,1,m)
	{
		scanf("%d%d",&x,&y);
		if (x!=y)
		if (t.find(x)!=t.end())
		{
			if (t.find(y)!=t.end())
			{
				len1=0;
				for(j=t[x];j;j=nxt[j])
				{
					len1++;
					w1[len1]=j;
				}
				sort(w1+1,w1+1+len1);
				for(j=t[y];j;j=nxt[j])
					deal(j);
				nxt[w[y]]=t[x];
				w[y]=w[x];
				t.erase(t.find(x));
				w.erase(w.find(x));
			} else{
				t[y]=t[x];
				w[y]=w[x];
				t.erase(t.find(x));
				w.erase(w.find(x));
			}
		}
		printf("%d\n",ans);
	}
}
