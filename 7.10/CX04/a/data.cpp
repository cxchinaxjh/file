#include<bits/stdc++.h>
using namespace std;
#define fori(i,a,b) for(i=a;i<=b;i++)
pair<int,int> e[100005];
map< pair<int,int>,bool > h;
int i,n,m,w;
int random(int x)
{
    return rand()*rand()%x+1;
}int main()
{
	freopen("data.in","w",stdout);
    srand((unsigned)time(0));
    n=random(10);
    m=random(50);
    w=random(20);
    cout<<n<<' '<<m<<' '<<w<<endl;
    fori(i,1,n)
    printf("%d ",random(3)-1);
    printf("\n");
    fori(i,1,n)
    printf("%d ",random(3)-1);
    printf("\n");
}
