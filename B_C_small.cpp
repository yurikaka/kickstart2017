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


//Problem C. Christmas Tree
//This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
//Small input
//11 points
//        Solve C-small
//        Large input
//32 points
//        Solve C-large
//        Problem
//
//You are given a rectangular grid with N rows and M columns. Each cell of this grid is painted with one of two colors: green and white. Your task is to find the number of green cells in the largest Christmas tree in this grid.
//
//To define a Christmas tree, first we define a good triangle as follows:
//
//A good triangle with top point at row R, column C and height h (h > 0) is an isoceles triangle consisting entirely of green cells and pointing upward. Formally, this means that: The cell (R, C) is green, and for each i from 0 to h-1 inclusive, the cells in row R+i from column C-i to column C+i are all green.
//
//For example:
//
//..#..
//.####
//#####
//is a good triangle with height 3. The # cells are green and the . cells are white. Note that there is a green cell that is not part of the good triangle, even though it touches the good triangle.
//
//..#..
//.###.
//####.
//is NOT a good triangle with height 3, because the 5th cell in the 3rd row is white. However, there are good triangles with height 2 present.
//
//...#.
//.###.
//#####.
//is NOT a good triangle with height 3. However, there are good triangles with height 2 present.
//
//A K-Christmas tree is defined as follows:
//
//It contains exactly K good triangles in vertical arrangement.
//The top cell of the i+1-th triangle must share its top edge with the bottom edge of any one of the cells at the base of the i-th triangle. This means that, if the base of the i-th triangle is at row r, from column c1 to column c2, then the top of the i+1-th triangle must be on row r+1, in a column somewhere between c1 and c2, inclusive.
//For example, if K = 2:
//
//...#...
//..###..
//.#####.
//#######
//..#....
//.###...
//#####..
//is a valid 2-Christmas tree. Note that the height of the 2 good triangles can be different.
//
//..#..
//.###.
//.#...
//is also a valid 2-Christmas tree. Note that a good triangle can be of height 1 and have only one green cell.
//
//...#...
//..###..
//.#####.
//.......
//..#....
//.###...
//#####..
//The two good triangles with height 3 does NOT form a valid 2-Christmas tree, because the 2nd triangle must starts from the 4-th row.
//
//...#.
//..###
//.#...
//###..
//The two good triangles with height 2 does NOT form a valid 2-Christmas tree, because the top of the 2nd triangle must be in a column between 3 and 5, inclusive.
//
//You need to find the K-Christmas tree with the largest number of green cells.
//
//Input
//
//        The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of three lines:
//
//The first line contains 3 space-separated integers N, M and K, where N is the number of rows of the grid, M is the number of columns of the grid and K is the number of good triangle in the desired Christmas tree.
//The next N lines each contain exactly M characters. Each character will be either . or #, representing a white or green cell, respectively.
//Output
//
//        For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of green cells in the largest K-Christmas tree. If there is no K-Christmas tree, output 0.
//
//Limits
//
//1 ≤ T ≤ 100.
//1 ≤ M ≤ 100.
//1 ≤ N ≤ 100.
//Each cell in the grid is either . or #.
//
//Small dataset
//
//K = 1.
//
//Large dataset
//
//1 ≤ K ≤ 100.
//
//Sample
//
//
//        Input
//
//Output
//
//4
//3 5 1
//..#..
//.###.
//#####
//3 5 1
//.....
//.....
//.....
//4 5 1
//#####
//#####
//#####
//#####
//4 5 2
//#####
//#####
//#####
//#####
//
//Case #1: 9
//Case #2: 0
//Case #3: 9
//Case #4: 10
