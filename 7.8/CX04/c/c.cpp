#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,b) for(i=a;i<=b;i++)
#define ford(i,a,b) for(i=a;i>=b;i--)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N=5e6+5; 
string s;
int len,i,w,k,j;
bool ji[24][N];
void wri(int x,int y)
{
	int i;
	ford(i,x-1,0)
	 if ((1<<i)&y) printf("1");
	 else printf("0");
}
int main()
{
	freopen("c.in","r",stdin); freopen("c.out","w",stdout);
	cin>>s;
	len=s.length();
	fori(i,0,len-1)
	{
		w=1; k=0;
		ford(j,i,max(i-21,0))
	    {
	    	k+=w*(s[j]-'0');
	    	ji[i-j+1][k]=true;
	    	w*=2;
	    }
	}
	 fori(i,1,22)
	 fori(j,0,(1<<i)-1)
	 if (!ji[i][j]) 
	 {
	 	wri(i,j);
	 	return 0;
	 }
}
