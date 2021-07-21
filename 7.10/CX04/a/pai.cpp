#include<bits/stdc++.h>
using namespace std;
int main()
{
    for (int T=1;T<=10000;T++)
    {
        system("data.exe");
        double s=clock();
        system("anew.exe");
        double o=clock();
        system("asol.exe");
        if (system("fc bf.out sol.out"))
        {
            puts("Wa");
            return 0;
        } else printf("AC Round#%d time %.01f ms\n",T,o-s);
    }
}
