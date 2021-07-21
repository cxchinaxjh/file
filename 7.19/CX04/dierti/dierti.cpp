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
const int base1=10003;
const int base2=19250817;
const int Mod=998244353;
const int N=3e5+5;
map<pair<ll,ll>,ll> q;
set< ull > q1;
ll hash1[N],hash2[N],basep1[N],basep2[N],jie[N],ni[N],eni[N];
ll len,ans,l,r,i,n;
string s;
ll qpow(ll x,ll y)
{
	ll w;
	if (y==0) return 1;
	if (y==1) return x%Mod;
	w=qpow(x,y/2);
	if (y%2==0) return w*w%Mod;
	else return w*w%Mod*x%Mod;
}
ll sum1(ll x,ll y)
{
	return ((hash1[y]-hash1[x-1]*basep1[y-x+1]%Mod)+Mod)%Mod;
}
ll sum2(ll x,ll y)
{
	return ((hash2[y]-hash2[x-1]*basep2[y-x+1]%Mod)+Mod)%Mod;
}
ull sqr(ll x)
{
	return x*x;
}
void solve(ll x)
{
	ll i,num,res,anss;
	ull rr,tot;
	num=len/x;
	res=len%x;
	q.clear();
	q1.clear();
	if (res==0)
	{
		anss=jie[num];
		fori(i,0,num-1)
		if (q.find(make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1)))==q.end()) q[make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))]=1;
		else q[make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))]++;
		fori(i,0,num-1)
		if (q.find(make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1)))!=q.end())  
		{
			//cout<<q[make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))]<<endl;
			anss=anss*ni[q[make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))]]%Mod;
			q.erase(q.find(make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))));
		}
		ans=(ans+anss)%Mod;
	} else {
		anss=jie[num];
		fori(i,0,num-1)
		if (q.find(make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1)))==q.end()) q[make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))]=1;
		else q[make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))]++;
		fori(i,0,num-1)
		if (q.find(make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1)))!=q.end())  
		{
			anss=anss*ni[q[make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))]]%Mod;
		}
		ans=(ans+anss)%Mod;
		q1.insert(sqr(sum1(i*x,len-1))+sqr(sum2(i*x,len-1)));
		//cout<<sqr(sum1(i*x,len-1))+sqr(sum2(i*x,len-1))<<endl;
		r=len-1;
		l=len-x;
		tot=0;
		rr=0;
		//cout<<anss<<endl;
		ford(i,num-1,0)
		{
			//cout<<q[make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))]<<endl;
			anss=anss*q[make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))]%Mod;
			q[make_pair(sum1(i*x,(i+1)*x-1),sum2(i*x,(i+1)*x-1))]--;
			q[make_pair(sum1(l,r),sum2(l,r))]++;
			anss=anss*eni[q[make_pair(sum1(l,r),sum2(l,r))]]%Mod;
			//cout<<q[make_pair(sum1(l,r),sum2(l,r))]<<endl;
			rr+=sqr(sum1(l,r))+sqr(sum2(l,r));
			tot+=sqr(sum1(i*x,(i+1)*x-1))+sqr(sum2(i*x,(i+1)*x-1));
			/*cout<<sqr(sum1(i*x,i*x+res-1))+sqr(sum2(i*x,i*x+res-1))-tot+rr<<endl;
			cout<<anss<<endl;*/
			if (q1.find(sqr(sum1(i*x,i*x+res-1))+sqr(sum2(i*x,i*x+res-1))-tot+rr)==q1.end()) ans=(ans+anss)%Mod;
			q1.insert(sqr(sum1(i*x,i*x+res-1))+sqr(sum2(i*x,i*x+res-1))-tot+rr);
			r-=len; l-=len;
		}
	}
	
}
int main()
{
	//freopen("dierti.in","r",stdin); freopen("dierti.out","w",stdout);
	cin>>s;
	len=s.length();
	basep1[0]=1;
	basep2[0]=1;
	fori(i,1,len)
	basep1[i]=basep1[i-1]*base1,
	          basep2[i]=basep2[i-1]*base2;
	jie[0]=1;
	ni[0]=1;
	eni[0]=1;
	jie[1]=1;
	ni[1]=1;
	eni[1]=1;
	fori(i,2,len)
	jie[i]=jie[i-1]*i%Mod,
	    eni[i]=qpow(i,Mod-2),
	       ni[i]=ni[i-1]*eni[i]%Mod;
	fori(i,0,len-1)
	hash1[i]=(hash1[i-1]*base1+s[i])%Mod,
	         hash2[i]=(hash2[i-1]*base2+s[i])%Mod;
	fori(i,1,len)
	{
		solve(i);
		cout<<ans<<endl;
	}
	
	cout<<ans%Mod<<endl;
}
