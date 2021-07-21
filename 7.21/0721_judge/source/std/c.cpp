#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
typedef long long LL;
using namespace std;
const int N = 26;

inline void judge()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
}

int n , K;
char str[N];
vector<string> trans[N];
vector<int> prefix[N];
bool vis[26][1 << 8];
 
bool isrow(char *s) {
    while (*s) {
        if (!isdigit(*s ++))
            return 0;        
    }
    return 1;
}
 
string itos(int x) {
    string s = "";
    while (x > 1) {
        s += (x & 1) + '0';
        x >>= 1;
    }
    reverse(s.begin() , s.end());
    return s;
}
int Stoi(string s) {
    int x = 1;
    for (int i = 0 ; i < s.size() && i < K ; ++ i)
        x = x << 1 | s[i] - '0';
    return x;
}
 
int cat(int A , int B) {
    int begin = -1;	
    for (int i = K ; i >= 0 ; -- i)
        if (B >> i & 1) {
            begin = i;
            break;
        }
    while (begin > 0) {
        int tmp = A << 1 | (B >> (-- begin) & 1);
        if (tmp >= 1 << K + 1)
            break;
        A = tmp;
    }
    return A;
    string C = itos(A) + itos(B);
    if (C.size() > K)
        C = C.substr(0 , K);
    return Stoi(C);
}
 
int main() {
	judge();
    scanf("%d%d\n" , &n , &K);
    //puts("233");
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        int c = *str - 'A';
        trans[c].push_back(str + 3);
        if (isrow(str + 3)) {
            int num = Stoi(str + 3);
            if (!vis[c][num]) {
                vis[c][num] = 1;
                prefix[c].push_back(num);
            }
        }
    }
    int mask = 1 << K + 1;
    while (1) {
        bool changed = 0;
        for (int i = 0 ; i < 26 ; ++ i) {
            for (auto &t : trans[i]) {
                static bool Hash[2][1 << 8];
                int cur = 0 , nxt = 1;
                memset(Hash[cur] , 0 , sizeof(Hash[cur]));
                Hash[cur][1] = 1;
                for (auto &ch : t) {
                    memset(Hash[nxt] , 0 , sizeof(Hash[nxt]));
                    for (int j = 1 ; j < mask ; ++ j) {
                        if (!Hash[cur][j])
                            continue;
                        if (ch == '0') {
                            Hash[nxt][cat(j , 2)] = 1;
                        } else if (ch == '1') {
                            Hash[nxt][cat(j , 3)] = 1;
                        } else {
                            for (auto &s : prefix[ch - 'A'])
                                Hash[nxt][cat(j , s)] = 1;
                        }
                    }
                    swap(cur , nxt);
                }                
                for (int s = 1 ; s < mask ; ++ s) {
                    //cout << s << endl;
                    if (Hash[cur][s] && !vis[i][s]) {
                        changed = 1;
                        vis[i][s] = 1;
                        prefix[i].push_back(s);
                    }
                }
            }
        }
        if (!changed)
            break;
    }
    cout << prefix['S' - 'A'].size() << endl;
    for (auto &s : prefix['S' - 'A']) {
        if (s == 1)
            cout << "eps" << endl;
        else
            cout << itos(s) << endl;
    }    
    return 0;
}
