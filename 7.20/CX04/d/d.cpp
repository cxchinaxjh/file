#include<bits/stdc++.h>
#define fori(i,a,b) for(i=a;i<=b;i++)
#define ford(i,a,b) for(i=a;i>=b;i--)
typedef long long ll;
typedef double db;
using namespace std;
const int N=1e5+5;
ll T,n,x,i,a[N];
int main()
{
	freopen("d.in","r",stdin); freopen("d.out","w",stdout);
	cin>>T;
	srand(time(0));
	while (T--)
	{
		cin>>n;
		x=0;
		fori(i,1,n) 
		{
			scanf("%lld",&a[i]);
			x^=a[i];
		}
		sort(a+1,a+1+n);
		if (x>a[(1+n)/2]) puts("First");
		else if (n%2==0) puts("Draw");
		else puts("Second");
	}
}
