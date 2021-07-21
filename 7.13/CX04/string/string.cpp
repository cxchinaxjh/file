//#pragma GCC optimize(2)
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
const int n=61;
const int Mod=998244353;
string s;
ll len,i,j,ans,v[N],num[70],k1[70],k2[70],k[70][70],kk[70][70],hg[N],f[N][70],a[70][70],numd[70];
int main()
{
	freopen("string.in","r",stdin); freopen("string.out","w",stdout);
	cin>>s;
	len=s.length();
	fori(i,0,len-1)
	{
		if (s[i]>='0'&&s[i]<='9') v[i+1]=s[i]-'0';
		if (s[i]>='A'&&s[i]<='Z') v[i+1]=s[i]-55;
		if (s[i]>='a'&&s[i]<='z') v[i+1]=s[i]-61;
	}
	//fori(i,1,len) cout<<v[i]<<endl;
	fori(i,1,len)
	{
		fori(j,0,n)
		{
			if (j!=v[i]) 
			{
				k1[j]+=num[j];
				k[j][v[i]]+=num[j];
			}
			else {
				k2[j]+=i-1-num[v[i]];
				hg[i]=hg[i-1]+i-1-num[v[i]];
			}
		}
		num[v[i]]++;
		fori(j,0,n)
		if (j!=v[i+1]) 
		{
			f[i][j]=hg[i]-(k1[v[i+1]]+k1[j]+k2[v[i+1]]+k2[j]-k[v[i+1]][j]-k[j][v[i+1]]);
			f[i][j]%=Mod;
		}
	}
	
	ford(i,len,1)
	{
		fori(j,0,n)
		if (v[i]!=j)
		{
			ans+=a[j][v[i]]%Mod*f[i-1][j]%Mod;
		}
		fori(j,0,n)
		if (v[i]!=j) a[v[i]][j]+=kk[j][v[i]];
		fori(j,0,n)
		if (v[i]!=j) kk[v[i]][j]+=numd[j];
		numd[v[i]]++;
	}
	cout<<ans%Mod<<endl;
}
