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
const int N=1e6+5;
struct node
{
	ll l,r,num,x;
} b[N];
struct node1
{
	ll x,num;
} c[N];
ll a[N],numzl[N],numzr[N],numfl[N],numfr[N],tot[N],num[N],tag[N];
ll n,m,i,len,t,lenz,lenf,sum,numd,k,lenc;
bool cmp(node a,node b)
{
	return a.x>b.x;
}
bool cmpd(node1 a,node1 b)
{
	return a.x<b.x;
}
int main()
{
	freopen("d.in","r",stdin); freopen("d.out","w",stdout);
	cin>>n>>m;
	if (m==0)
	{
		puts("0");
		return 0;
	}
	fori(i,1,n-1)
	{
		scanf("%lld",&a[i]);
		tot[i]=tot[i-1]+a[i];
		if (a[i]>=0)
		{
			num[i]=1;
			sum+=a[i];
		}
		else num[i]=-1;
	}
	t=1;
	fori(i,2,n-1)
	if (num[i]!=num[i-1])
	{
		if (num[i-1]>0)
		{
			lenz++;
			numzl[lenz]=t;
			numzr[lenz]=i-1;
		}
		else
		{
			lenf++;
			numfl[lenf]=t;
			numfr[lenf]=i-1;
		}
		t=i;
	}
	if (num[i-1]>0)
	{
		lenz++;
		numzl[lenz]=t;
		numzr[lenz]=i-1;
	}
	else
	{
		lenf++;
		numfl[lenf]=t;
		numfr[lenf]=i-1;
	}
	if (lenz==m)
	{
		printf("%lld\n",sum);
		fori(i,1,lenz)
		printf("%lld %lld\n",numzl[i],numzr[i]+1);
		return 0;
	}
	if (lenz<m)
	{
		fori(i,1,lenf) numd+=numfr[i]-numfl[i];
		if (a[1]<0) numd++;
		if (a[n]<0) numd++;
		if (numd+lenz>=m)
		{
			printf("%lld\n",sum);
			k=1;
			while (m>lenz&&k<numzl[1])
			{
				m--;
				printf("%lld %lld\n",k,k);
				k++;
			}
			fori(i,1,lenz)
			{
				printf("%lld %lld\n",numzl[i],numzr[i]+1);
				if (i<lenz)
				{
					k=numzr[i]+2;
					while (m>lenz&&k<numzl[i+1])
					{
						m--;
						printf("%lld %lld\n",k,k);
						k++;
					}
				}
			}
			k=numzr[lenz]+2;
			while (m>lenz&&k<=n-1)
			{
				m--;
				printf("%lld %lld\n",k,k);
				k++;
			}
			return 0;
		}
		m-=numd;
		m-=lenz;
		//cout<<m<<endl;
		fori(i,1,n-1)
		if (a[i]>=0)
		{
			lenc++;
			c[lenc].x=a[i];
			c[lenc].num=i;
		}
		sort(c+1,c+1+lenc,cmpd);
		fori(i,1,m)
		{
			sum-=c[i].x;
			a[c[i].num]=-1;
			//cout<<c[i].num<<endl;
		}
		fori(i,1,n-1)
		if (a[i]<0) num[i]=-1;
		else num[i]=1;
		printf("%lld\n",sum);
		lenz=0;
		lenf=0;
		t=1;
		fori(i,2,n-1)
		if (num[i]!=num[i-1])
		{
			if (num[i-1]>0)
			{
				lenz++;
				numzl[lenz]=t;
				numzr[lenz]=i-1;
			}
			else
			{
				lenf++;
				numfl[lenf]=t;
				numfr[lenf]=i-1;
			}
			t=i;
		}
		if (num[i-1]>0)
		{
			lenz++;
			numzl[lenz]=t;
			numzr[lenz]=i-1;
		}
		else
		{
			lenf++;
			numfl[lenf]=t;
			numfr[lenf]=i-1;
		}
		k=1;
		while (k<numzl[1])
		{
			printf("%lld %lld\n",k,k);
			k++;
		}
		fori(i,1,lenz)
		{
			printf("%lld %lld\n",numzl[i],numzr[i]+1);
			if (i<lenz)
			{
				k=numzr[i]+2;
				while (m>lenz&&k<numzl[i+1])
				{
					m--;
					printf("%lld %lld\n",k,k);
					k++;
				}
			}
		}
		k=numzr[lenz]+2;
		while (k<=n-1)
		{
			printf("%lld %lld\n",k,k);
			k++;
		}
		return 0;
	}
	if (lenz>m)
	{
		fori(i,1,lenz-1)
		{
			b[i].l=numzr[i]+1;
			b[i].r=numzl[i+1]-1;
			b[i].x=tot[b[i].r]-tot[b[i].l-1];
			b[i].num=i;
		}
		sort(b+1,b+lenz,cmp);
		fori(i,1,lenz-m)
		{
			sum+=b[i].x;
			tag[b[i].num]=true;
		}
		printf("%lld\n",sum);
		t=0;
		fori(i,1,lenz)
		if (!tag[i])
		{
			if (t!=0)
			{
				printf("%lld %lld\n",t,numzr[i]+1);
				t=0;
			}
			else printf("%lld %lld\n",numzl[i],numzr[i]+1);
		}
		else
		{
			if (t==0) t=numzl[i];
		}
		return 0;
	}
}
