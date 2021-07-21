#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,b) for(i=a;i<=b;i++)
#define ford(i,a,b) for(i=a;i>=b;i--)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
string a;
char ch;
db ctl,hd,jiao,kj,cando;
void zz()
{
	db z;
	if (a[0]=='H') return;
	if (a=="AP") z=5;
	else z=2;
	if (kj>3*hd) z*=3;
	else if (kj>2*hd) z*=2;
	jiao=max((db)0,jiao-z);
}
void losed(){
	puts("We didn't penetrate their armor!");
}
void won()
{
	puts("Penetration!");
}
void might()
{
	puts("Server is important~");
}
int main()
{
	freopen("a.in","r",stdin); freopen("a.out","w",stdout);
	scanf("%c",&ch);
	while (ch!='\n') scanf("%c",&ch);
	cin>>a>>ctl>>jiao>>kj>>hd;
	zz();
	if (a[0]=='A') 
	{
		if (jiao>=70) 
		{
			losed();
			return 0;
		}
	}
	if (a=="HEAT")
	{
		if (jiao>=85)
		{
			losed();
			return 0;
		}
	}
	cando=cos(jiao/(db)180*3.14159265358979)*ctl;
	if (cando*0.75>=hd) won();
	else if (cando*1.25>=hd) might();
	else losed();
	fclose(stdin); fclose(stdout);
}
