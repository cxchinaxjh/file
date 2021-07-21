#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,n) for(i=a;i<=n;i++)
#define ford(i,n,a) for(i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
const int N=2e5+5;
ull ans;
ll a[N],f[N],b[N],sum[N];
ll n,i;
void solve(int l,int r)
{
	ll mid,i,tot,w,k,t;
	if (l==r) 
	{
		ans+=a[l];
		//cout<<l<<' '<<r<<' '<<ans<<endl;
		return;
	}
	mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	tot=a[mid];
	f[mid]=a[mid];
	sum[mid]=a[mid];
	ford(i,mid-1,l)
	{
		tot+=a[i];
		f[i]=max(f[i+1],tot);
		sum[i]=f[i]+sum[i+1];
	}
	sum[mid+1]=a[mid+1];
	tot=a[mid+1];
	f[mid+1]=a[mid+1];
	fori(i,mid+2,r)
	{
		tot+=a[i];
		f[i]=max(tot,f[i-1]);
		sum[i]=f[i]+sum[i-1];
	}
	w=a[mid]; b[mid]=a[mid];
	ford(i,mid-1,l)
	{
		if (w<0) w=0;
		w+=a[i];
		b[i]=max(b[i+1],w);
	}
	w=a[mid+1]; b[mid+1]=a[mid+1];
	fori(i,mid+2,r)
	{
		if (w<0) w=0;
		w+=a[i];
		b[i]=max(b[i-1],w);
	}
	//if (l==1&&r==5) cout<<ans<<endl;
	//cout<<sum[3]<<endl;
	ford(i,mid,l)
	{
		//if (l==1&&r==3) cout<<b[i]<<"  "<<f[i]<<endl;
		k=lower_bound(b+mid+1,b+r+1,b[i])-b-1;
		t=upper_bound(f+mid+1,f+r+1,b[i]-f[i])-f-1;
		//if (l==1&&r==3) cout<<k<<' '<<t<<endl;
		if (k>mid)
	  	{
	     	if (k-t>0) 
	     	{
	     		if (t>mid) ans+=sum[k]-sum[t]+f[i]*(k-t);
	     		else ans+=sum[k]+f[i]*(k-t);
	     		//cout<<sum[k]<<"  "<<ans<<endl;
	    		if (t-mid>0) ans+=(t-mid)*b[i];
	     	} else {
	     		if (k-mid>0) ans+=(k-mid)*b[i];
	    	}
		}
		//if (l==1&&r==3) cout<<' '<<ans<<endl;
		
	}
	//cout<<f[5]<<' '<<b[5]<<endl;
	fori(i,mid+1,r)
	{
		k=lower_bound(b+l,b+mid+1,b[i],greater<ll>())-b;
		t=lower_bound(f+l,f+mid+1,b[i]-f[i],greater<ll>())-f;
		if (k<=mid)
		{
			if (t-k>0) 
		  {
		   	if (t>mid) ans+=sum[k]+f[i]*(t-k);
		  	else ans+=sum[k]-sum[t]+f[i]*(t-k);
		  	if (mid+1-t>0) ans+=(mid+1-t)*b[i];
	      } else {
		   	if (1+mid-k>0) ans+=(1+mid-k)*b[i];
		  }
		}
		  
	}
	//cout<<l<<' '<<r<<' '<<ans<<endl;
}
int main()
{
	cin>>n;
	fori(i,1,n)
	scanf("%lld",&a[i]);
	solve(1,n);
	cout<<ans<<endl;
}
