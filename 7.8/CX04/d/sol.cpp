#include<bits/stdc++.h>
#include<set>
#define I inline
#define re register
#define Me(x,y) memset(x,y,sizeof(x))
#define N 100000
#define M 100000
#define W 25
#define db double
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a) :(b))
#define it iterator
#define Gc() getchar()
#define ll long long
#define ull unsigned ll
using namespace std;
int n,m,A[N+5];ull ans,Q[N+5];ll now,Sum[N+5],Maxn[N+5];
I void solve(int l,int r){
	if(l==r) return (void)(ans+=A[l]);re int m=l+r>>1,i,rs,lx,rx,mid;solve(l,m);solve(m+1,r);
	for(Sum[m]=Maxn[m]=A[m],now=max(A[m],0),i=m-1;i>=l;i--)Sum[i]=Sum[i+1]+A[i],now+=A[i],Maxn[i]=max(Maxn[i+1],now),now=max(now,0);
	for(Q[m]=Sum[m],i=m-1;i>=l;i--) Sum[i]=max(Sum[i+1],Sum[i]),Q[i]=Q[i+1]+Sum[i];
	for(Sum[m+1]=Maxn[m+1]=A[m+1],now=max(A[m+1],0),i=m+2;i<=r;i++)Sum[i]=Sum[i-1]+A[i],now+=A[i],Maxn[i]=max(Maxn[i-1],now),now=max(now,0);
	for(Q[m+1]=Sum[m+1],i=m+2;i<=r;i++) Sum[i]=max(Sum[i-1],Sum[i]),Q[i]=Q[i-1]+Sum[i];
	Q[m]=0;for(rs=m+1,i=m;i>=l;i--){
		while(rs<=r&&Maxn[rs]<=Maxn[i]) rs++;lx=m;rx=rs;while(lx+1<rx) mid=lx+rx>>1,(Sum[mid]<Maxn[i]-Sum[i]?lx:rx)=mid;
		ans+=Q[rs-1]-Q[lx]+(rs-1-lx)*Sum[i]+Maxn[i]*(lx-m);//printf("%d %d %d %lld\n",i,l,r,Q[rs-1]-Q[lx]+(rs-1-lx)*Sum[i]+Maxn[i]*(lx-m));
	}Q[m]=Sum[m];
	Q[m+1]=0;for(rs=m,i=m+1;i<=r;i++){
		while(rs>=l&&Maxn[rs]<Maxn[i]) rs--;lx=rs;rx=m+1;while(lx+1<rx) mid=lx+rx>>1,(Sum[mid]>Maxn[i]-Sum[i]?lx:rx)=mid;
		ans+=Q[rs+1]-Q[rx]+(rx-1-rs)*Sum[i]+Maxn[i]*(m-lx);//printf("%d %d %d %lld\n",i,l,r,Q[rs-1]-Q[rx]+(rx+1-rs)*Sum[i]+Maxn[i]*(m-lx));
	}
}
int main(){
	//freopen("d.in","r",stdin);freopen("d.out","w",stdout);
	re int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);solve(1,n);printf("%llu\n",ans);
}
