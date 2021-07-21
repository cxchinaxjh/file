#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=1e4;
const int M=1e7+5;
int i,j,len,lend,bo,l,r,ans,p[N];
int n,ru[2*N+5],q[2*N+5],num[2*N+5],c[2*N+5][100],las[M],nxt[M],to[M];
void add(int x,int y)
{
	lend++;
	to[lend]=y;
	nxt[lend]=las[x];
	las[x]=lend;
	//cout<<lend<<endl;
}
bool fi(int x)
{
	int j;
	fori(j,1,ans)
		if (c[x][j]==false) 
		{
			num[x]=j;
			return true;
		}
	return false;
}
int main()
{
	freopen("b.in","r",stdin); freopen("b.out","w",stdout);
	cin>>n;
	if (n==1)
	{
		printf("1\n");
		printf("1\n");
		return 0;
	}
	if (n==2)
	{
		printf("1\n");
		printf("1 1\n");
		return 0;
	}
	if (n<=6)
	{
		cout<<(n+1)/2<<endl;
		fori(i,1,n)
		printf("%d ",(i+1)/2);
		return 0;
	}
	cout<<4<<endl;
	fori(i,1,n)
	printf("%d ",(i-1)%4+1);
	/*fori(i,2,n)
	{
		bo=true;
		fori(j,2,sqrt(i))
		if (i%j==0)
		{
			bo=false;
			break;
		}
		if (bo)
		{
			len++;
			p[len]=i;
		}
	}
	//cout<<len<<endl;
	
	fori(i,1,n)
	 {
	 	fori(j,1,len)
	 	if (i+p[j]>n) break;
	 	else {
	 		add(i,i+p[j]);
	 		ru[i+p[j]]++;
	     }
	 }
	l=1; r=2; ans=1;
	q[1]=1; q[2]=2;
	num[1]=1; num[2]=1;
	while (l<=r)
	{
		for (i=las[q[l]];i;i=nxt[i])
		{
			ru[to[i]]--;
			c[to[i]][num[q[l]]]=true;
			if (ru[to[i]]==0)
			{
				r++;
				q[r]=to[i];
				if (!fi(to[i]))
				{
					ans++;
					num[to[i]]=ans;
				}
			}
		}
		l++;
	}
	cout<<ans<<endl;
	fori(i,1,n-1)
	printf("%d ",num[i]);
	printf("%d\n",num[n]);*/
}
