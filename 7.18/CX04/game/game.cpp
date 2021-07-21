/*#include<bits/stdc++.h>

using namespace std;

#define fori(i,a,n) for(i=a;i<=n;i++)

#define ford(i,n,a) for(i=n;i>=a;i--)

typedef long long ll;

typedef double db;

typedef long double ld;

typedef unsigned long long ull;

typedef unsigned int uin;

//typedef __int128 lll;

const int N=7e5+5;
vector<ll> d[N],pre[N],suf[N];

ll n,a,b,x,y,l,r,j,len,maxx,maxi,w,ans,num[N],las[N],nxt[N],i,du[N],tag[N],q[N],to[N],f[N];

void add(ll x,ll y)

{

	to[++len]=y;

	nxt[len]=las[x];

	las[x]=len;

}

bool cmp(ll x,ll y)

{

	return x>y;

}

void maketree(ll x,ll fa)

{

	ll i,len,w;

	len=0;

	for (i=las[x]; i; i=nxt[i])

		if (to[i]!=fa)

		{

			maketree(to[i],x);

			len++;

			d[x].push_back(f[to[i]]);

		}

	sort(d[x].begin(),d[x].end(),cmp);

	if (len==0)

	{

		f[x]=0;

		return;

	}

     
	f[x]=d[x][0]+1;
	pre[x].push_back(f[x]); 
	fori(i,1,len-1)
	{
		pre[x].push_back(f[x]); 
		f[x]=max(d[x][i]+i+1,f[x]);
	 } 
	w=d[x][len-1]+len;
	suf[x].push_back(w);
	fori(i,len-2,0)
	{
		w=max(w,d[x][i]+i+1);
		suf[x].insert(suf[x].begin(),w);
	}
}

void cr(ll x,ll y)

{

	ll i,w;

	if (x==y) return;

	d[x].erase(find(d[x].begin(),d[x].end(),f[y]));

	//cout<<d[x].size()<<endl;

	if (d[x].size())

	{


		f[x]=d[x][0]+1;

		fori(i,1,d[x].size()-1)

		{

			f[x]=max(f[x],d[x][i]+i+1);

		}

	}

	else f[x]=0;

	if (d[y].size())

	{

		d[y].insert(lower_bound(d[y].begin(),d[y].end(),f[x],greater<ll>()),f[x]);

	}

	else

	{

		d[y].push_back(f[x]);

	}

	f[y]=d[y][0]+1;
	
	fori(i,1,d[y].size()-1)

	f[y]=max(f[y],d[y][i]+i+1);

}

void dfs(ll x,ll fa)

{

	ll i;

	cr(fa,x);

	ans=min(ans,f[x]);

	//cout<<ans<<endl;

	for (i=las[x]; i; i=nxt[i])

		if (to[i]!=fa) dfs(to[i],x);

	cr(x,fa);

}


int main()

{

	//freopen("game.in","r",stdin);freopen("game.out","w",stdout);

	cin>>n>>a>>b;

	fori(i,1,n-1)

	{

		scanf("%lld%lld",&x,&y);

		add(x,y);

		add(y,x);

	}

	ans=2147483647;

	maketree(1,0);
	dfs(1,1);

	cout<<ans<<endl;

	cout<<ans<<endl;

}*/
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



const int N=7e5+5;

vector<ll> d[N];



ll n,a,b,x,y,l,r,j,len,maxx,maxi,w,ans,num[N],las[N],nxt[N],i,du[N],tag[N],q[N],to[N],f[N];



void add(ll x,ll y)



{



	to[++len]=y;



	nxt[len]=las[x];



	las[x]=len;



}



bool cmp(ll x,ll y)



{



	return x>y;



}



void maketree(ll x,ll fa)



{



	ll i,len;


    //cout<<x<<endl; 
	len=0;



	for (i=las[x]; i; i=nxt[i])



		if (to[i]!=fa)



		{

/*if (x==64776)
{
	cout<<to[i]<<endl;
	cout<<endl;
	cout<<endl;
}*/

			maketree(to[i],x);



			len++;



			d[x].push_back(f[to[i]]);



		}



	

//cout<<" "<<len<<endl;

	if (len==0)



	{



		f[x]=0;



		return;



	}
     sort(d[x].begin(),d[x].end(),cmp);
	f[x]=d[x][0]+1;

	fori(i,1,len-1)

	f[x]=max(d[x][i]+i+1,f[x]);
}



void cr(ll x,ll y)



{



	ll i,w;



	if (x==y) return;



	d[x].erase(find(d[x].begin(),d[x].end(),f[y]));



	//cout<<d[x].size()<<endl;



	if (d[x].size())



	{





		f[x]=d[x][0]+1;



		fori(i,1,d[x].size()-1)



		{



			f[x]=max(f[x],d[x][i]+i+1);



		}



	}



	else f[x]=0;



	if (d[y].size())



	{



		d[y].insert(lower_bound(d[y].begin(),d[y].end(),f[x],greater<ll>()),f[x]);



	}



	else



	{



		d[y].push_back(f[x]);



	}



	f[y]=d[y][0]+1;

	

	fori(i,1,d[y].size()-1)



	f[y]=max(f[y],d[y][i]+i+1);



}



void dfs(ll x,ll fa)



{



	ll i;


	cr(fa,x);



	ans=min(ans,f[x]);



	//cout<<ans<<endl;



	for (i=las[x]; i; i=nxt[i])



		if (to[i]!=fa) dfs(to[i],x);



	cr(x,fa);



}





int main()



{



	freopen("game.in","r",stdin);freopen("game.out","w",stdout);



	cin>>n>>a>>b;



	fori(i,1,n-1)



	{



		scanf("%lld%lld",&x,&y);



		add(x,y);



		add(y,x);



	}



	ans=2147483647;



	maketree(1,0);

	dfs(1,1);



	cout<<ans<<endl;



	cout<<ans<<endl;



}
