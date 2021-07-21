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
const int no=1e9;
const int N=5005;
const int M=1e6+5;
ll dis[N][N],las[M],nxt[M],to[M],q[M];
ll len,n,m,k,i,j,x,y,t,s1,s2,t1,t2,a,b;
db ans,anss;
void add(ll x,ll y)
{
	to[++len]=y;
	nxt[len]=las[x];
	las[x]=len;
}
void spfa(ll x)
{
	ll i,l,r,t;
	dis[x][x]=0;
	l=1; r=1;
	q[1]=x;
	while (l<=r)
	{
		t=q[l];
		for (i=las[t];i;i=nxt[i])
		if (dis[x][t]+1<dis[x][to[i]])
		{
			dis[x][to[i]]=dis[x][t]+1;
			r++;
			q[r]=to[i];
		}
		l++;
	}
}
db dd(ll k,ll a)
{
	return (db)(a-(k%a))*(1/(db)(k/a+1))+(db)(k%a)*(1/(db)(k/a+2));
}
db deal(ll k,ll a,ll b)
{
	ll t,l,r,mid;
	db w1,w2;
	w1=2147483647.0;
	if (a==0||b==0)
	 	{
	 		if (a==0&&b==0)
	 		{
	 			return 0;
			 }
			 if (a==0)
			 {
			    return dd(k,b);
			 }
			 if (b==0)
			 {
			 	return dd(k,a)*2;
			 }
		 }
	 	else {
	 		/*fori(t,1,k)
	     	{
	     		w2=dd(t,a)*2+dd(k-t,b);
	     		cout<<t<<' '<<w2<<endl;
	     		w1=min(w1,w2);
	    	}*/
	    	l=1; r=k;
	    	while (l<=r)
	    	{
	    		mid=(l+r)>>1;
	    		w2=dd(mid,a)*2+dd(k-mid,b);
	    		w1=min(w2,w1);
	    		if (w2<dd(mid+1,a)*2+dd(k-mid-1,b)) r=mid-1;
	    		else l=mid+1;
			}
	    	return w1;
		 }
}
int main()
{
	//freopen("city.in","r",stdin); freopen("city.out","w",stdout);
	cin>>n>>m>>k;
	fori(i,1,n)
	 fori(j,1,n)
	 dis[i][j]=no;
	fori(i,1,m)
	{
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	fori(i,1,n)
	spfa(i);
	/*fori(i,1,n)
	{
		fori(j,1,n) cout<<dis[i][j]<<' ';
		cout<<endl;
	}*/
	cin>>s1>>t1>>s2>>t2;
	ans=deal(k,0,dis[s1][t1]+dis[s2][t2]);
	//cout<<dis[1][3]<<endl;
	fori(i,1,n)
	 fori(j,1,n)
	 {
	 if (dis[i][j]!=no&&dis[s1][i]!=no&&dis[j][t1]!=no&&dis[s2][i]!=no&&dis[j][t2]!=no)
	 {
	 if (dis[s1][i]+dis[i][j]+dis[j][t1]+dis[s2][i]+dis[i][j]+dis[j][t2]==dis[s1][t1]+dis[s2][t2])
	 {
	 	//cout<<i<<' '<<j<<endl;
	 	a=dis[i][j];
	 	b=dis[s1][i]+dis[j][t1]+dis[s2][i]+dis[j][t2];
	 	//cout<<a<<' '<<b<<endl;
	 	ans=min(ans,deal(k,a,b));
	 }
	 }
	 if (dis[i][j]!=no&&dis[s1][i]!=no&&dis[j][t1]!=no&&dis[s2][j]!=no&&dis[i][t2]!=no)
	 {
	 if (dis[s1][i]+dis[i][j]+dis[j][t1]+dis[s2][j]+dis[i][j]+dis[i][t2]==dis[s1][t1]+dis[s2][t2])
	 {
	 	//cout<<i<<' '<<j<<endl;
	 	a=dis[i][j];
	 	b=dis[s1][i]+dis[j][t1]+dis[s2][j]+dis[i][t2];
	 	//cout<<a<<' '<<b<<endl;
	 	ans=min(ans,deal(k,a,b));
	 }
	 }
	 }
	 
	 
	 printf("%0.12f",ans);
}
