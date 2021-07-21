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
const int N=1005;
ll n,m,hmin,hmax,ans,i,j,x,y,minn[N],maxx[N],tag[N][N];
void d1(int y,int x)
{
	int i;
	fori(i,x,n)
	if (tag[i][y]) break;
	maxx[y]=i-1;
	ford(i,x,1)
	if (tag[i][y]) break;
	minn[y]=i+1;
}
void dd1(ll x,ll y)
{
	ll i,j,k,t;
	ford(i,y,hmin)
	{
		ford(j,x,minn[i])
    	{
    		fori(k,y,hmax)
    		if (minn[k]<=j) ans-=min(maxx[k],maxx[i])-x+1;
    		else break;
		}
	}
}
int main()
{
	//freopen("flip.in","r",stdin); freopen("flip.out","w",stdout);
	cin>>n>>m;
	ans=(1+n)*n/2*(1+m)*m/2;
	fori(i,1,n*m)
	{
		scanf("%lld%lld",&x,&y);
		fori(j,y,m)
		if (tag[x][j]) break;
		else {
			d1(j,x);
			if (j!=y) 
			{
				maxx[j]=min(maxx[j-1],maxx[j]);
				minn[j]=max(minn[j-1],minn[j]);
			}
			
		}
		hmax=j-1;
		
		ford(j,y-1,1)
		if (tag[x][j]) break;
		else {
			d1(j,x);
			if (j!=y) 
			{
				maxx[j]=min(maxx[j+1],maxx[j]);
				minn[j]=max(minn[j+1],minn[j]);
			}
			
		}
		hmin=j+1;
		
		cout<<hmax<<' '<<hmin<<endl;
		puts("");
		fori(j,1,m)
		cout<<maxx[j]<<' '<<minn[j]<<endl;
		
		
		
		dd1(x,y);
		cout<<ans<<endl;
		//ans++;
		/*fori(j,hmin,y)
		ans-=x-minn[j]+1;
		fori(j,y,hmax)
		ans-=maxx[j]-x+1;
		cout<<ans<<endl;*/
		/*ford(j,y-1,hmin)
		{
			//ans-=(maxx[j]-x)*(hmax-y+x-minn[y]);
			ans-=(x-minn[j])*(hmax-y+maxx[y]-x);
		}
		cout<<ans<<endl;
		fori(j,y+1,hmax)
		{
			ans-=(maxx[j]-x)*(y-hmin+x-minn[y]);
			//ans-=(x-minn[j])*(y-hmin+maxx[y]-x);
		}*/
		//cout<<ans<<endl;
		/*ans-=(maxx[y]-x)*(x-minn[y]);
		//cout<<y<<endl;
		ans-=(hmax-y)*(y-hmin);*/
		//cout<<ans<<endl;
		fori(j,hmin,y-1)
		ans-=min(maxx[j]-x,maxx[y]-x);
		fori(j,y+1,hmax)
		ans-=min(x-minn[j],x-minn[y]);
		cout<<ans<<endl;
		
		tag[x][y]=true;
	}
}

