#include <bits/stdc++.h>
using namespace std;
long long a[2000010];
bool alice[2000010],bob[2000010];
int main()
{
freopen("data.in","r",stdin); freopen("bf.out","w",stdout);
	long long n,k,x,t1=0,t2=0;
	cin>>n>>k>>x;
	long long s1,s2;
	for (long long i=1;i<=n;i++) cin>>a[i];
	for (long long i=1;i<=n;i++)
	{
		long long tem;
		cin>>tem;
		a[i]=a[i]-tem;
		if (a[i]==1||a[i]==-2)
		{
			alice[i]=false;
			bob[i]=true;
			t2++;
		}
		if (a[i]==-1||a[i]==2)
		{
			alice[i]=true;
			bob[i]=false;
			t1++;
		}
		if (a[i]==0)
		{
			alice[i]=false;
			bob[i]=false;
		}
	}
	if (x>k)
	{
		t1=t1*(k/n);
		t2=t2*(k/n);
		k=k%n;
		for (long long i=1;i<=k;i++)
		{
			if (alice[i]) t1++;
			if (bob[i]) t2++;
		}
		cout<<t1<<" "<<t2<<endl;
		return 0;
	}
	if (x>n)
	{
		long long s=k-x+1;
		t1=t1*(k/n);
		t2=t2*(k/n);
		k=k%n;
		for (long long i=1;i<=k;i++)
		{
			if (alice[i]) t1++;
			if (bob[i]) t2++;
		}
		long long talice=true,tbob=true;
		for (long long i=1;i<=n;i++)
		{
			talice=talice&alice[i];
			tbob=tbob&bob[i];
		}
		if (talice) t1=t1+s;
		if (tbob) t2=t2+s;
		cout<<t1<<" "<<t2<<endl;
		return 0;
	}
	if (k>=n+x-1)
	{
		for (long long i=1;i<=x;i++)
		{
			alice[i+n]=alice[i];
			bob[i+n]=bob[i];
		}
		long long sum1=0,sum2=0,talice=0,tbob=0;
		bool falice=true,fbob=true;
		for (long long i=1;i<x;i++)
		{
			if (!alice[i])
			{
				falice=false;
				talice=i;
			}
			if (!bob[i])
			{
				fbob=false;
				tbob=i;
			}
		}
		for (long long i=x;i<=n+x-1;i++)
		{
			if (!alice[i])
			{
				falice=false;
				talice=i;
			}
			if (!bob[i])
			{
				fbob=false;
				tbob=i;
			}
			if (i-x+1>talice) falice=true;
			if (i-x+1>tbob) fbob=true;
			if (falice) sum1++;
			if (fbob) sum2++;
		}
		s1=(t1+sum1)*((k-n*2)/n);
		s2=(t2+sum2)*((k-n*2)/n);
		k=k-((k-n*2)/n)*n;
		while (k>=n+x-1)
		{
			s1=s1+t1+sum1;
			s2=s2+t2+sum2;
			k=k-n;
		}
		falice=true;fbob=true;
		for (long long i=1;i<x;i++)
		{
			if (!alice[i])
			{
				falice=false;
				talice=i;
			}
			if (!bob[i])
			{
				fbob=false;
				tbob=i;
			}
		}
		for (long long i=x;i<=k;i++)
		{
			if (!alice[i])
			{
				falice=false;
				talice=i;
			}
			if (!bob[i])
			{
				fbob=false;
				tbob=i;
			}
			if (i-x+1>talice) falice=true;
			if (i-x+1>tbob) fbob=true;
			if (falice) s1++;
			if (fbob) s2++;
		}
		for (long long i=n+1;i<=k;i++) a[i]=a[i-n];
		for (long long i=1;i<=k;i++)
		{
			if (a[i]==-1||a[i]==2) s1++;
			if (a[i]==1||a[i]==-2) s2++;
		}
		cout<<s1<<" "<<s2<<endl;
		return 0;
	}
	s1=0;s2=0;
	for (long long i=n+1;i<=k;i++)
	{
		a[i]=a[i-n];
		alice[i]=alice[i-n];
		bob[i]=bob[i-n];
	}
	bool falice=true,fbob=true;
	long long talice,tbob;
	for (long long i=1;i<x;i++)
	{
		if (!alice[i])
		{
			falice=false;
			talice=i;
		}
		if (!bob[i])
		{
			fbob=false;
			tbob=i;
		}
	}
	for (long long i=x;i<=k;i++)
	{
		if (!alice[i])
		{
			falice=false;
			talice=i;
		}
		if (!bob[i])
		{
			fbob=false;
			tbob=i;
		}
		if (i-x+1>talice) falice=true;
		if (i-x+1>tbob) fbob=true;
		if (falice) s1++;
		if (fbob) s2++;
	}
	for (long long i=n+1;i<=k;i++) a[i]=a[i-n];
	for (long long i=1;i<=k;i++)
	{
		if (a[i]==-1||a[i]==2) s1++;
		if (a[i]==1||a[i]==-2) s2++;
	}
	cout<<s1<<" "<<s2<<endl;
	return 0;
}
