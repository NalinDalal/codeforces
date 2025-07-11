/*B. Matrix Stabilization
time limit per test2 seconds
memory limit per test256 megabytes
You are given a matrix of size 𝑛×𝑚
, where the rows are numbered from 1
 to 𝑛
 from top to bottom, and the columns are numbered from 1
 to 𝑚
 from left to right. The element at the intersection of the 𝑖
-th row and the 𝑗
-th column is denoted by 𝑎𝑖𝑗
.

Consider the algorithm for stabilizing matrix 𝑎
:

Find the cell (𝑖,𝑗)
 such that its value is strictly greater than the values of all its neighboring
cells. If there is no such cell, terminate the algorithm. If there are multiple
such cells, choose the cell with the smallest value of 𝑖 , and if there are
still multiple cells, choose the one with the smallest value of 𝑗
.
Set 𝑎𝑖𝑗=𝑎𝑖𝑗−1
.
Go to step 1
.
In this problem, cells (𝑎,𝑏)
 and (𝑐,𝑑)
 are considered neighbors if they share a common side, i.e., |𝑎−𝑐|+|𝑏−𝑑|=1
.

Your task is to output the matrix 𝑎
 after the stabilization algorithm has been executed. It can be shown that this
algorithm cannot run for an infinite number of iterations.

Input
Each test consists of multiple sets of input data. The first line contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of sets of input data. This is followed
by their description.

The first line of each set of input data contains two integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤100,𝑛⋅𝑚>1
) — the number of rows and columns of matrix 𝑎
.

The next 𝑛
 lines describe the corresponding rows of the matrix. The 𝑖
-th line contains 𝑚
 integers 𝑎𝑖1,𝑎𝑖2,…,𝑎𝑖𝑚
 (1≤𝑎𝑖𝑗≤109
).

It is guaranteed that the sum of 𝑛⋅𝑚
 over all sets of input data does not exceed 2⋅105
.

Output
For each set of input data, output 𝑛
 lines with 𝑚
 numbers in each line — the values of the cells of matrix 𝑎
 after the stabilization algorithm.

Example
InputCopy
6
1 2
3 1
2 1
1
1
2 2
1 2
3 4
2 3
7 4 5
1 8 10
5 4
92 74 31 74
74 92 17 7
31 17 92 3
74 7 3 92
7 31 1 1
3 3
1000000000 1 1000000000
1 1000000000 1
1000000000 1 1000000000
OutputCopy
1 1
1
1
1 2
3 3
4 4 5
1 8 8
74 74 31 31
74 74 17 7
31 17 17 3
31 7 3 3
7 7 1 1
1 1 1
1 1 1
1 1 1
Note
In the first set of input data, the algorithm will select the cell (1,1)
 twice in a row and then terminate.


In the second set of input data, there is no cell whose value is strictly
greater than the values of all neighboring cells.

In the third set of input data, the algorithm will select the cell (2,2)
 and then terminate.


In the fourth set of input data, the algorithm will select the cell (1,1)
 three times and then the cell (2,3)
 twice.
*/

#include <iostream>
#include <vector>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n, m;
    std::cin >> n >> m;
    std::vector<std::vector<long>> v(n, std::vector<long>(m, 0));
    for (long row = 0; row < n; row++) {
      for (long col = 0; col < m; col++) {
        std::cin >> v[row][col];
      }
    }

    for (long row = 0; row < n; row++) {
      for (long col = 0; col < m; col++) {
        bool largest(true);
        long mx(0);
        if (row > 0 && v[row - 1][col] >= v[row][col]) {
          largest = false;
        } else if (row > 0) {
          mx = (mx > v[row - 1][col] ? mx : v[row - 1][col]);
        }
        if (row + 1 < n && v[row + 1][col] >= v[row][col]) {
          largest = false;
        } else if (row + 1 < n) {
          mx = (mx > v[row + 1][col] ? mx : v[row + 1][col]);
        }
        if (col > 0 && v[row][col - 1] >= v[row][col]) {
          largest = false;
        } else if (col > 0) {
          mx = (mx > v[row][col - 1] ? mx : v[row][col - 1]);
        }
        if (col + 1 < m && v[row][col + 1] >= v[row][col]) {
          largest = false;
        } else if (col + 1 < m) {
          mx = (mx > v[row][col + 1] ? mx : v[row][col + 1]);
        }

        if (largest) {
          v[row][col] = mx;
        }
        std::cout << v[row][col] << " ";
      }
      std::cout << std::endl;
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1986/328557050
