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

#define MOD 1000000007
// a^x
unsigned long long pow1(unsigned long long a,
                        unsigned long long x)
{
    unsigned long long result=1;
    a%=MOD;
    while(x)
    {
        if(x&1)
            result=(result*a)%MOD;
        a=(a*a)%MOD;
        x>>=1;
    }
    return result;
}

int main() {
    freopen("../Round_B/A-large.in","r",stdin);
    freopen("../out.txt","w",stdout);
    int t, n, k [10000];
    cin >> t;
    long long r = 0;
    for (int i = 0; i < t; ++i){
        r = 0;
        cin >> n;
        for (int j = 0; j < n; ++j)
            cin >> k[j];
        for (int p = 0; p < n-1; ++p)
            for (int q = p+1; q < n; ++q){
                int dist = q-p-1;
                r += (k[q]-k[p])*pow1(2,dist);
                r %= 1000000007;
            }
        cout << "Case #" << i+1 << ": " << int(r) << endl;
    }
    return 0;
}