#include<cctype>
#include<cstdio>
#include<cstring>
#define le(p) ((p)<<1)
#define ri(p) ((p)<<1|1)
#define ll long long
using namespace std;
const int N=4e5+7;
const int M=1<<16;
const ll mod=1e9+7;
ll read(){
	char c;
	ll x=0,f=1;
	while(!isdigit(c=getchar()))
		f-=(c=='-')*2;
	while(isdigit(c)){
		x=x*10+f*(c-48);
		c=getchar();
	}
	return x;
}
void add(ll& a,ll b){
	a+=b;
	if(a>=mod)
		a-=mod;
}
struct matrix{
	ll a[2][2];
	matrix(){
		memset(a,0,sizeof(a));
	}
	ll* operator [](int n){
		return a[n];
	}
	friend matrix operator +(matrix a,matrix b){
		for(register int i=0;i<2;++i)
		for(register int j=0;j<2;++j)
			add(a[i][j],b[i][j]);
		return a;
	}
	friend matrix operator *(matrix a,matrix b){
		matrix c;
		for(register int i=0;i<2;++i)
		for(register int k=0;k<2;++k)
		for(register int j=0;j<2;++j)
			add(c[i][j],a[i][k]*b[k][j]%mod);
		return c;
	}
};
ll n,m,x,a[N];
int L[N],R[N];
ll tag[N];
matrix F,G[N],A[M+7],B[M+7],C[M+7];
matrix f(ll n){
	return A[n&(M-1)]*B[(n>>16)&(M-1)]*C[n>>32];
}
void up(int p){
	G[p]=G[le(p)]+G[ri(p)];
}
void down(int p){
	if(!tag[p])
		return;
	matrix T=f(tag[p]);
	G[le(p)]=G[le(p)]*T;
	G[ri(p)]=G[ri(p)]*T;
	tag[le(p)]+=tag[p];
	tag[ri(p)]+=tag[p];
	tag[p]=0;
}
void build(int p,int l,int r){
	L[p]=l;
	R[p]=r;
	if(l==r){
		matrix T;
		T[0][1]=1;
		G[p]=T*f(a[l]);
		return;
	}
	int m=(l+r)>>1;
	build(le(p),l,m);
	build(ri(p),m+1,r);
	up(p);
}
void update(int p,int l,int r,ll k){
	if(l<=L[p]&&R[p]<=r){
		G[p]=G[p]*f(k);
		tag[p]+=k;
		return;
	}
	down(p);
	int m=(L[p]+R[p])>>1;
	if(l<=m)
		update(le(p),l,r,k);
	if(r>m)
		update(ri(p),l,r,k);
	up(p);
}
ll query(int p,int l,int r){
	if(l<=L[p]&&R[p]<=r)
		return G[p][0][0];
	down(p);
	int m=(L[p]+R[p])>>1;
	ll res=0;
	if(l<=m)
		add(res,query(le(p),l,r));
	if(r>m)
		add(res,query(ri(p),l,r));
	return res;
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	F[0][1]=F[1][0]=F[1][1]=1;
	A[0][0][0]=A[0][1][1]=1;
	B[0][0][0]=B[0][1][1]=1;
	C[0][0][0]=C[0][1][1]=1;
	for(int i=1;i<=M;++i)
		A[i]=A[i-1]*F;
	for(int i=1;i<=M;++i)
		B[i]=B[i-1]*A[M];
	for(int i=1;i<=M;++i)
		C[i]=C[i-1]*B[M];
	build(1,1,n);
	for(int i=1;i<=m;++i){
		ll op=read();
		ll l=read();
		ll r=read();
		if(op==1){
			x=read();
			update(1,l,r,x);
		}
		else
			printf("%lld\n",query(1,l,r));
	}
	return 0;
}
