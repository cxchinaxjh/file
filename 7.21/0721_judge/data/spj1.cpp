#include<fstream>
#include<iostream>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N=1e5+5;
typedef long long ll;
int a[N],n,m;
ll pre[N];
int main(int argc,char *argv[]) {
	ifstream fin,fout,fstd;
	ofstream fscore,freport;
    fin.open(argv[1]);
    fout.open(argv[2]);
    fstd.open(argv[3]);
    fscore.open(argv[5]);
    freport.open(argv[6]);

    int score=atoi(argv[4]);
    ll ans;
    fstd>>ans;
    ll res;
    fout>>res;
    if(ans!=res)
    {
    	fscore<<0<<endl;
    	freport<<"Wrong Answer";
	    fin.close();
	    fout.close();
	    fstd.close();
	    fscore.close();
	    freport.close();
    	return 0;
    }
    fin>>n>>m;
    rep(i,1,n-1)fin>>a[i];
    rep(i,2,n)pre[i]=pre[i-1]+a[i-1];
    ll sum=0;
    int x,y;
    while(fout>>x>>y)
    {
    	if(x<1 || y<1 || x>n || y>n)
    	{
			fscore<<5<<endl;
			freport<<"Partly Correct";
			fin.close();
		    fout.close();
		    fstd.close();
		    fscore.close();
		    freport.close();
			return 0;
		}
    	sum+=pre[y]-pre[x];
    }
    if(sum!=ans)
	{
		fscore<<5<<endl;
		freport<<"Partly Correct";
	}
    else
	{
		fscore<<10<<endl;
		freport<<"Correct!";
	}
	fin.close();
    fout.close();
    fstd.close();
    fscore.close();
    freport.close();
    return 0;
}
