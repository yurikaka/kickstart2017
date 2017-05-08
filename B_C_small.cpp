#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <queue>
#include <memory.h>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <math.h>
#include <stdio.h>

using namespace std;

int g[105][105], n, m, k;

int tri(int h, int p, int q){
    if (g[p][q] == 0)
        return h;
    int hh = 1, lx = p, ly = q, rx = p, ry = q;
    while (true){
        lx++;ly--;ry++;
        if (lx > n || ly < 1 || ry > m)
            break;
        bool tt = true;
        for (int i = ly; i <= ry; ++i)
            if (g[lx][i] == 0){
                tt = false;
                break;
            }
        if (!tt)
            break;
        ++hh;
    }
    return max(h,hh);
}

int main() {
    freopen("../Round_B/C-small-attempt0.in","r",stdin);
    freopen("../out.txt","w",stdout);
    int t, h, maxx;
    char c;
    cin >> t;
    for (int i = 0; i < t; ++i){
        cin >> n >> m >> k;
        for (int p = 1; p <= n; ++p)
            for (int q = 1; q <= m; ++q){
                cin >> c;
                if (c == '#')
                    g[p][q] = 1;
                else
                    g[p][q] = 0;
            }
        h = 0;
//        maxx = 0;
        for (int p = 1; p <= n; ++p){
            for (int q = 1; q <= m; ++q) {
                h = tri(h,p,q);
            }
        }
        cout << "Case #" << i+1 <<": " << h*h << endl;
    }
}