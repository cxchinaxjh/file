#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=100005;
const ll inf=1e12;
ll n,i,j,K,p,l,t,a[N],s[N];
ll f[N][2],L[N][2],R[N][2];
ll tot,ansl[N],ansr[N],ans;
inline void read(ll &x)
{
	x=0; ll ff=1; char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if (ch=='-') ff=-1,ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x*=ff;
}
void update(ll x,ll v)
{
	f[x][0]=f[x-1][0];
	f[x][0]=max(f[x][0],f[x-1][0]-v);
	f[x][0]=max(f[x][0],f[x-1][1]+a[x-1]);
	f[x][1]=f[x-1][0]-v;
	f[x][1]=max(f[x][1],f[x-1][1]+a[x-1]);
	L[x][0]=inf; R[x][0]=-1;
	L[x][1]=inf; R[x][1]=-1;
	
	if (f[x][0]==f[x-1][0]) L[x][0]=min(L[x][0],L[x-1][0]),R[x][0]=max(R[x][0],R[x-1][0]);
	if (f[x][0]==f[x-1][1]+a[x-1]) L[x][0]=min(L[x][0],L[x-1][1]),R[x][0]=max(R[x][0],R[x-1][1]);
	if (f[x][0]==f[x-1][0]-v) L[x][0]=min(L[x][0],L[x-1][0]+1),R[x][0]=max(R[x][0],R[x-1][0]+1);
	
	if (f[x][1]==f[x-1][0]-v) L[x][1]=min(L[x][1],L[x-1][0]+1),R[x][1]=max(R[x][1],R[x-1][0]+1);
	if (f[x][1]==f[x-1][1]+a[x-1]) L[x][1]=min(L[x][1],L[x-1][1]),R[x][1]=max(R[x][1],R[x-1][1]);
}
void Dp(ll x)
{
	ll i;
	f[0][0]=0; L[0][0]=0; R[0][0]=0;
	f[0][1]=-inf; L[0][1]=-1; R[0][1]=-1;
	for (i=1;i<=n;i++) update(i,x);
}
ll find0(ll x,ll NK,ll v)
{
	//printf("%lld %lld %lld %lld\n",x,f[x][0],f[x-1][0]-v,v);
	if (f[x][0]==f[x-1][0]&&NK>=L[x-1][0]&&NK<=R[x-1][0]) return 1;
	else if (f[x][0]==f[x-1][0]-v&&NK>=L[x-1][0]+1&&NK<=R[x-1][0]+1) return 2;
	else if (f[x][0]==f[x-1][1]+a[x-1]&&NK>=L[x-1][1]&&NK<=R[x-1][1]) return 3;
	return -1;
}
ll find1(ll x,ll NK,ll v)
{
	if (f[x][1]==f[x-1][0]-v&&NK>=L[x-1][0]+1&&NK<=R[x-1][0]+1) return 1;
	else if (f[x][1]==f[x-1][1]+a[x-1]&&NK>=L[x-1][0]&&NK<=R[x-1][0]) return 2;
	return -1;
}
void get(ll K,ll v)
{
	ll i;
	ll NK=K,op=0;
	for (i=n;i>=1;i--)
	{
		ll A=-1;
		if (op==0) 
		{
			A=find0(i,NK,v);
			//printf("%lld %lld %lld\n",i,op,A);
			if (A==1) op=0;
			else if (A==2) ansl[++tot]=i,ansr[tot]=i,NK--,op=0;
			else op=1,ansr[++tot]=i;
		}
		else 
		{
			A=find1(i,NK,v);
			//printf("%lld %lld %lld\n",i,op,A);
			if (A==1) ansl[tot]=i,NK--,op=0;
			else op=1;
		}
	}
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	read(n); read(K);
	//printf("%lld %lld\n",n,K);
	for (i=1;i<=n-1;i++) read(a[i]),s[i+1]=s[i]+a[i];
	//for (i=1;i<=n-1;i++) printf("%lld ",a[i]); printf("\n");
	ll l=-1e12,r=1e12;
	while (l<=r)
	{
		ll mi=(l+r)>>1;
		Dp(mi); 
		//printf("%lld\n",mi);
		if (K>=L[n][0]&&K<=R[n][0])
		{
			//printf("%lld %lld %lld \n",K,L[n][0],R[n][0]);
			ans=f[n][0]+K*mi;
			get(K,mi);
			break;
		}
		else if (K>R[n][0]) r=mi-1;
		else l=mi+1;
	}
	printf("%lld\n",ans);
	for (i=1;i<=tot;i++) printf("%lld %lld\n",ansl[i],ansr[i]);
	//printf("%lld %lld\n",s[89253]-s[2430],s[100000]-s[1]);
} 
