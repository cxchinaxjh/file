#include<bits/stdc++.h>
using namespace std;
const int n=1e4;//可以更改，下同
const int m=1e5;//
pair<int,int> e[100005];
map< pair<int,int>,bool > h;
int i;
int random(int x)
{
    return rand()*rand()%x;
}
int main()
{
    srand((unsigned)time(0));
    freopen("b.in","w",stdout);
    cout<<n<<' '<<m<<endl;
    for (i=1;i<n;i++)
    {
        int fa=random(i)+1;
        e[i]=make_pair(fa,i+1);
        h[e[i]]=h[make_pair(i+1,fa)]=1;
    }
    for (i=n;i<=m;i++)
    {
        int x,y;
        do
        {
            x=random(n)+1; y=random(n)+1;
        } while(x==y||h[make_pair(x,y)]);
        e[i]=make_pair(x,y);
        h[e[i]]=h[make_pair(y,x)]=1;
    }
    random_shuffle(e+1,e+m+1);
    for (i=1;i<=m;i++)
    printf("%d %d %d %d\n",e[i].first,e[i].second,random(200000)-100000,random(200000)-100000);
    cout<<-1000000000<<' '<<1000000000<<endl;
}
