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
const int N=3e6+5;
const int inf=1e15;
ll nn,m,n,i,w,t,ans,s;

inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

struct node
{
	ll x,id;
	inline bool operator <(const node &b)const{
		return x>b.x;
	};
}k;

struct node1
{
	ll num,x;
}a[N];
priority_queue<node> q1;
priority_queue< ll,vector<ll>,greater<ll> > q0;
bool cmp(node1 a,node1 b)
{
	return (a.x<b.x);
}
int main()
{
	cin>>nn>>m;
	fori(i,1,nn) 
	{
		a[i].x=read();
		a[i].num=-1;
	}
	n=nn+m;
	fori(i,nn+1,nn+m)
	{
		a[i].x=read(); 
		a[i].num=read();
		s+=a[i].num;
    }
    if (s<nn)
    {
    	puts("-1");
    	return 0;
	}
    sort(a+1,a+1+n,cmp);
    fori(i,1,n)
    if (a[i].num==-1)
    {
    	w=inf;
    	if (q1.size())
    	{
    		k=q1.top();
    		q1.pop();
    		w=a[i].x+k.x;
    		t=k.id;
    		a[t].num--;
    		if (a[t].num>0) q1.push(node{k.x,t});
		}
		ans+=w;
		q0.push(-a[i].x-w);
	} else {
		while(q0.size()&&q0.top()+a[i].x<0&&a[i].num>0)
		{
			w=q0.top()+a[i].x;
			q0.pop();
			a[i].num--;
			q1.push(node{-a[i].x-w,0});
			ans+=w;
		}
		if (a[i].num>0) q1.push(node{-a[i].x,i});
	}
	cout<<ans<<endl;
}
