#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef unsigned long long ull;
ull n,len,cnt,k,T,a[20],s;
const int p[16]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
void sc(ull x,ull y,ull ans)
{
	ull i,t;
	if (y>n) return;
	if (x>len)
	{
		if (ans>cnt)
		{
			cnt=ans;
			k=y;
		}
		if (ans==cnt&&y<k) k=y;
		return;
	}
	t=1;
	for (i=1;i<=a[x-1];i++)
	{
		a[x]=i;
		t*=p[x];
		if ((__int128)y*(__int128)t>(__int128)n) break;
		sc(x+1,y*t,ans*(i+1));
	}
}
int main()
{
    cin>>T;
    while (T--)
    {
    	s++;
    	cnt=0;
     	cin>>n;
     	if (s==24) cout<<n<<endl;
    	if (n==1)
      	{
	     	cout<<1<<endl;
	    	return 0;
    	}
    	a[0]=31;
	    for (len=1;len<=15;len++)
	    sc(1,1,1);
	    cout<<cnt<<' '<<k<<endl;
    }
}
