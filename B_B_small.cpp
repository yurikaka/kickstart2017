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


//Problem B. Center
//        This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
//Small input
//13 points
//        Solve B-small
//        Large input
//21 points
//        Solve B-large
//        Problem
//
//There are N weighted points in a plane. Point i is at (Xi, Yi) and has weight Wi.
//
//In this problem, we need to find a special center of these points. The center is a point (X, Y) such that the sum of max(|X-Xi|, |Y-Yi|)*Wi is minimum.
//
//Input
//
//        The input starts with one line containing exactly one integer T, which is the number of test cases. T test cases follow.
//
//Each test case begins with one line containing one integer N. N lines follow. Each line contains three space-separated real numbers Xi, Yi, and Wi. Xi, Yi and Wi have exactly 2 digits after the decimal point.
//
//Output
//
//        For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the sum of max(|X-Xi|, |Y-Yi|)*Wi for center (X, Y).
//
//y will be considered correct if it is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.
//
//Limits
//
//1 ≤ T ≤ 10.
//-1000.00 ≤ Xi ≤ 1000.00.
//-1000.00 ≤ Yi ≤ 1000.00.
//Small dataset
//
//1 ≤ N ≤ 100;
//Wi = 1.0, for all i.
//Large dataset
//
//1 ≤ N ≤ 10000;
//1.0 ≤ Wi ≤ 1000.0, for all i.
//Sample
//
//
//        Input
//
//Output
//
//3
//2
//0.00 0.00 1.00
//1.00 0.00 1.00
//4
//1.00 1.00 1.00
//1.00 -1.00 1.00
//-1.00 1.00 1.00
//-1.00 -1.00 1.00
//2
//0.00 0.00 1.00
//1.00 0.00 2.00
//
//Case #1: 1.0
//Case #2: 4.0
//Case #3: 1.0
