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

int main() {
    freopen("../Round_B/B-small-attempt0.in","r",stdin);
    freopen("../out.txt","w",stdout);
    int t, n;
    double xx, yy, ww, x[105], y[105];
    cin >> t;
    for (int i = 0; i < t; ++i){
        cin >> n;
        for (int j = 0; j < n; ++j){
            cin >> xx >> yy >> ww;
            x[j] = xx+yy;
            y[j] = xx-yy;
        }
        double sum = 0.0, mini;
        for (int q = 1; q < n; ++q)
            sum += abs(x[q]-x[0]);
        mini = sum;
        for (int p = 1; p < n; ++p){
            sum = 0.0;
            for (int q = 0; q < n; ++q)
                if (p!=q)
                    sum += abs(x[q]-x[p]);
            mini = min(sum,mini);
        }
        double mini2;
        sum = 0.0;
        for (int q = 1; q < n; ++q)
            sum += abs(y[q]-y[0]);
        mini2 = sum;
        for (int p = 1; p < n; ++p){
            sum = 0.0;
            for (int q = 0; q < n; ++q)
                if (p!=q)
                    sum += abs(y[q]-y[p]);
            mini2 = min(sum,mini2);
        }
//        cout << "Case #"<<i+1 << ": " << (mini+mini2)/2.0 << endl;
        printf("Case #%d: %.6f\n",i+1,(mini+mini2)/2.0);
    }
}