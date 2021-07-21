#include<bits/stdc++.h>
using namespace std;
 
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
 
const int M=(int)100005;
 
typedef long long ll;
 
struct node {
 int c,v;
 bool operator <(const node &s) const{
  return v<s.v;
 }
}A[M];
int n,K;
int f[M][22];
bool check(ll lim) {
 FOR(i,0,n) FOR(j,0,K) f[i][j]=2e9;
 f[0][0]=0;
 FOR(i,1,n) {
  FOR(j,0,K-1) {
   if(A[i].v-A[i].c-f[i-1][j]>=lim) {
    f[i][j+1]=min(f[i][j+1],f[i-1][j]+A[i].c);
   }
  }
  FOR(j,0,K) {
   f[i][j]=min(f[i][j],f[i-1][j]);
  }
 }
 return f[n][K]<2e9;
}
inline void judge()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
}
int main() {
	judge();
 int T;
 scanf("%d",&T);
 while(T--) {
  scanf("%d%d",&n,&K);
  ++K;
  FOR(i,1,n) scanf("%d%d",&A[i].c,&A[i].v);
  sort(A+1,A+n+1);
  int L=0,R=2e9,res=0;
  while(L<=R) {
   ll mid=L+R>>1;
   if(check(mid)) res=mid,L=mid+1;
   else R=mid-1;
  }
  printf("%lld\n",res);
 }
 return 0;
}
