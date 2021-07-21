//#pragma GCC optimize(2)
//#pragma GCC optimize("inline")
//#pragma GCC optimize(3)
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
//const int b=430;
const int b=2;
const int N=1e6+5;

ll n,i,p[N],w1,w2,ans,xx,yy,k[N];
ull seed;
ull rd() 
{
    seed ^= seed << 13;
    seed ^= seed >> 7;
    seed ^= seed << 17;
    return seed;
}
inline ll kk(ll y)
{
	return (y-1)/b+1;
}
ll query(ll x,ll y,ll z)
{
	ll c,d,l,r,i,j,mid,bo,anss;
	if (x>y) return 0;
	c=kk(x);
	d=kk(y);
	//cout<<x<<' '<<y<<endl;
	//cout<<endl;
	anss=0;
	fori(i,c+1,d-1)
	{
		r=i*b;
	    l=r-b+1;
	    bo=r;
	    while (l<=r)
	    {
	    	mid=(l+r)>>1;
	    	if (k[mid]>z)
	    	{
	    		bo=mid;
	    		r=mid-1;
			} else l=mid+1;
		}
		if (k[bo]>z) bo--;
		anss+=r-bo;
	}
	printf("%lld %lld\n",x,y);
	fori(i,x,y) printf("%lld ",k[i]);
	puts("");
	fori(i,x-1,y) printf("%lld ",p[i]);
	puts("");
	//cout<<x<<' '<<min(c*b,y)<<endl;
	fori(i,x,min(c*b,y))
	if (p[i]>z) anss++;
	if (kk(x)!=kk(y))
	{
		fori(i,max(x,d*b-b+1),y)
    	if (p[i]>z) anss++;
	}
	return anss;
}
ll tot1(ll x,ll y)
{
	ll i,anss;
	anss=0;
	anss+=query(x+1,y-1,p[y]);
	anss+=query(y+1,n,p[x])-query(y+1,n,p[y]);
	return anss;
}
ll tot2(ll x,ll y)
{
	ll i,anss;
	anss=0;
	anss+=x-1-query(1,x-1,p[y]);
	return anss;
}
ll find(ll x)
{
	ll l,r,mid,i;
	r=kk(x)*b;
	l=r-b+1;
	/*while (l<=r)
	{
		mid=(l+r)>>1;
		if (k[mid]<p[x]) l=mid+1;
		else if (k[mid]>p[x]) r=mid-1;
		else return mid;
	}*/
	fori(i,l,r)
	if (k[i]==p[x]) return i;
}
void deal(ll x)
{
	ll l,r,i;
	r=kk(x)*b;
	l=r-b+1;
	fori(i,x,r-1)
	if (k[x]>k[x+1]) swap(k[x],k[x+1]);
	else break;
	ford(i,x,l+1)
	if (k[x-1]>k[x]) swap(k[x],k[x-1]);
	else break;
}
int main()
{
	//freopen("triple.in","r",stdin); freopen("triple.out","w",stdout);
	cin >> n >> seed;
    p[1]=1;
    k[1]=1;
    fori(i,2,n) 
	{
        p[i]=i;
        k[i]=i;
    }
    ans=0;
    //cout<<n<<endl;
    fori(i,2,n)
    {
    	w1=rd()%i+1;
    	w2=i;
    	//cout<<w1<<' '<<w2<<endl;
    	//cout<<n<<endl;
    	if (w1>w2) swap(w1,w2);
    	if (p[w1]<p[w2])
    	{
    		//cout<<n<<endl;
    		ans-=tot1(w1,w2);
    		if (kk(w1)!=kk(w2))
        	{
        		xx=find(w1);
        		yy=find(w2);
        		swap(k[xx],k[yy]);
        		deal(xx);
        		deal(yy);
			}
    		swap(p[w1],p[w2]);
    		ans+=tot2(w1,w2);
    		//cout<<n<<endl;
        }
        else if (p[w1]>p[w2])
        {
        	ans-=tot2(w1,w2);
        	if (kk(w1)!=kk(w2))
        	{
        		xx=find(w1);
        		yy=find(w2);
        		swap(k[xx],k[yy]);
        		deal(xx);
        		deal(yy);
			}
        	swap(p[w1],p[w2]);
    		ans+=tot1(w1,w2);
		}
	}
	//fori(i,1,n) cout<<p[i]<<endl;
	cout<<ans<<endl;
}
