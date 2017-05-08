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
    freopen("../Round_B/A-small-attempt0.in","r",stdin);
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
                r += (k[q]-k[p])*(1<<dist);
                r %= 1000000007;
            }
        cout << "Case #" << i+1 << ": " << int(r) << endl;
    }
    return 0;
}


//Problem A. Math Encoder
//This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
//Small input
//7 points
//        Solve A-small
//        Large input
//16 points
//        Solve A-large
//        Problem
//
//Professor Math is working on a secret project and is facing a challenge where a list of numbers need to be encoded into a single number in the most efficient manner. After much research, Professor Math finds a 3 step process that can best encode the numbers:
//
//The first step is to find all possible non-empty subsets of the list of numbers and then, for each subset, find the difference between the largest and smallest numbers (that is, the largest minus the smallest) in that subset. Note that if there is only one number in a subset, it is both the largest and the smallest number in that subset. The complete set itself is also considered a subset.
//Then add up all the differences to get the final encoded number.
//As the number may be large, output the number modulo 109 + 7 (1000000007).
//The professor has shared an example and its explanation below. Given a list of numbers, can you help the professor build an efficient function to compute the final encoded number?
//
//Input
//
//        The first line of the input gives the number of test cases, T. This is followed by T test cases where each test case is defined by 2 lines:
//
//        The first line gives a positive number N: the number of numbers in the list and
//The second line contains a list of N positive integers Ki, sorted in non-decreasing order.
//Output
//
//        For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the final encoded number.
//
//Since the output can be a really big number, we only ask you to output the remainder of dividing the result by the prime 109 + 7 (1000000007).
//
//Limits
//
//1 ≤ T ≤ 25.
//1 ≤ Ki ≤ 10000, for all i.
//Ki ≤ Ki+1, for all i < N - 1.
//Small dataset
//
//1 ≤ N ≤ 10.
//
//Large dataset
//
//1 ≤ N ≤ 10000.
//
//Sample
//
//
//        Input
//
//Output
//
//1
//4
//3 6 7 9
//
//Case #1: 44
//
//Explanation for the sample input
//        Find all subsets and get the difference between largest & smallest numbers:
//[3], largest-smallest = 3 - 3 = 0.
//[6], largest-smallest = 6 - 6 = 0.
//[7], largest-smallest = 7 - 7 = 0.
//[9], largest-smallest = 9 - 9 = 0.
//[3, 6], largest-smallest = 6 - 3 = 3.
//[3, 7], largest-smallest = 7 - 3 = 4.
//[3, 9], largest-smallest = 9 - 3 = 6.
//[6, 7], largest-smallest = 7 - 6 = 1.
//[6, 9], largest-smallest = 9 - 6 = 3.
//[7, 9], largest-smallest = 9 - 7 = 2.
//[3, 6, 7], largest-smallest = 7 - 3 = 4.
//[3, 6, 9], largest-smallest = 9 - 3 = 6.
//[3, 7, 9], largest-smallest = 9 - 3 = 6.
//[6, 7, 9], largest-smallest = 9 - 6 = 3.
//[3, 6, 7, 9], largest-smallest = 9 - 3 = 6.
//Find the sum of the differences calculated in the previous step:
//3+4+6+1+3+2+4+6+6+3+6
//= 44.
//Find the answer modulo 109 + 7 (1000000007):
//44 % 1000000007 = 44