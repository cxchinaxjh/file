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
int n,i;
db totx,toty,ax,ay,k,x,y,w,ww;
int main()
{
	freopen("line.in","r",stdin); freopen("line.out","w",stdout);
	cin>>n;
	fori(i,1,n)
	{
		scanf("%lf%lf",&x,&y);
		totx+=x;
		toty+=y;
		ax=totx/i;
		ay=toty/i;
		w+=x*y;
		ww+=x*x;
		if (i>1)
		{
			k=(w+ax*ay*i-toty*ax-totx*ay)/(ww+ax*ax*i-2*ax*totx);
	    	printf("%0.4f %0.4f\n",k,ay-k*ax);
		}
	}
}
