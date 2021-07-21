#include<bits/stdc++.h>
using namespace std;
const int n=1e5;//可以更改，下同
const int m=15;//
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
    freopen("travel.in","w",stdout);
    cout<<n<<endl;
    for (i=1;i<=n;i++)
    {
       printf("%d ",random(1e9+7));
    }
    puts("");
    for (i=1;i<=n;i++)
    {
       printf("%d ",random(n)+1);
    }
}
