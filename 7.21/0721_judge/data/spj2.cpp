#include<fstream>
#include<iostream>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N=1e5+5;
typedef long long ll;
string t[500];
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
    	freport<<"Wrong number";
	    fin.close();
	    fout.close();
	    fstd.close();
	    fscore.close();
	    freport.close();
    	return 0;
    }
    rep(i,1,ans)fstd>>t[i];
    rep(i,1,ans)
    {
    	string tt;
    	fout>>tt;
    	int flag=0;
    	rep(j,1,ans)if(t[j]==tt){flag=1;break;}
    	if(!flag)
    	{
    		freport<<"Wrong string";
    		fscore<<0<<endl;
    	}
    }
	fscore<<10<<endl;
	freport<<"Correct!";
    return 0;
}
