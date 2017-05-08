import sys

args = sys.argv[1:]

f = open(args[0])
f1 = open(args[1],'w')
case = int(f.readline())
for i in xrange(case):
    line = f.readline().split()
    r = int(line[0])
    c = int(line[1])
    l = min(r-1,c-1)
    cnt = r*c*(1+l)*l/2-(r+c)*l*(l+1)*(2*l+1)/6+((1+l)*l/2)*((1+l)*l/2)
    f1.write('Case #'+str(i+1)+': '+str(cnt%1000000007)+'\n')
f.close()
f1.close()


# Problem A. Square Counting
# This contest is open for practice. You can try every problem as many times as you like, though we won't keep track of which problems you solve. Read the Quick-Start Guide to get started.
# Small input
# 8 points	
# Solve A-small
# Large input
# 17 points	
# Solve A-large
# Problem

# Mr. Panda has recently fallen in love with a new game called Square Off, in which players compete to find as many different squares as possible on an evenly spaced rectangular grid of dots. To find a square, a player must identify four dots that form the vertices of a square. Each side of the square must have the same length, of course, but it does not matter what that length is, and the square does not necessarily need to be aligned with the axes of the grid. The player earns one point for every different square found in this way. Two squares are different if and only if their sets of four dots are different.

# Mr. Panda has just been given a grid with R rows and C columns of dots. How many different squares can he find in this grid? Since the number might be very large, please output the answer modulo 109 + 7 (1000000007).

# Input

# The first line of the input gives the number of test cases, T. T lines follow. Each line has two integers R and C: the number of dots in each row and column of the grid, respectively.
# Output

# For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of different squares can be found in the grid.
# Limits

# 1 ≤ T ≤ 100.
# Small dataset

# 2 ≤ R ≤ 1000.
# 2 ≤ C ≤ 1000.
# Large dataset

# 2 ≤ R ≤ 109.
# 2 ≤ C ≤ 109.
# Sample


# Input 
 	
# Output 
 
# 4
# 2 4
# 3 4
# 4 4
# 1000 500

# Case #1: 3
# Case #2: 10
# Case #3: 20
# Case #4: 624937395

# The pictures below illustrate the grids from the three sample cases and a valid square in the third sample case.
