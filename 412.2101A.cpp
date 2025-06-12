/* A. Mex in the Grid
time limit per test2 seconds
memory limit per test256 megabytes

You are given 𝑛2
 cards with values from 0
 to 𝑛2−1
. You are to arrange them in a 𝑛
 by 𝑛
 grid such that there is exactly one card in each cell.

The MEX (minimum excluded value) of a subgrid∗
 is defined as the smallest non-negative integer that does not appear in the
subgrid.

Your task is to arrange the cards such that the sum of MEX values over all
(𝑛(𝑛+1)2)2 subgrids is maximized.

∗
A subgrid of a 𝑛
 by 𝑛
 grid is specified by four numbers 𝑙1,𝑟1,𝑙2,𝑟2
 satisfying 1≤𝑙1≤𝑟1≤𝑛
 and 1≤𝑙2≤𝑟2≤𝑛
. The element in the 𝑖
-th row and the 𝑗
-th column of the grid is part of the subgrid if and only if 𝑙1≤𝑖≤𝑟1
 and 𝑙2≤𝑗≤𝑟2
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤500
) — the side length of the grid.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 1000
.

Output
For each test case, output 𝑛
 lines, each containing 𝑛
 integers representing the elements of the grid.

If there are multiple answers, you can output any of them.

Example
InputCopy
2
2
3
OutputCopy
0 1
2 3
8 4 5
6 0 1
7 2 3
Note
In the first test case, one valid arrangement is:

0	1
2	3
There are 9
 subgrids in total, and the 4
 of them with non-zero MEX are shown below:

0
values:[0]
 — MEX: 1
0	1
values:[0,1]
  — MEX: 2
0
2
values:[0,2]
  — MEX: 1
0	1
2	3
values:[0,1,2,3]
  — MEX: 4
The sum of MEX over all subgrids would be 1+2+1+4=8
. It can be proven that no other arrangements have a larger sum of MEX values.


*/
// center is -> (n/2,n/2);(n/2-1,(n-1)/2)
// use spiral pattrn to fill grid;pattern expands outward from the center,
// increasing the number of steps taken in each direction as the spiral grows.
// Track the current direction and the number of steps to take in each
// direction. Change direction every time the spiral completes a layer.
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    int x, y;
    if (n % 2 == 1) {
      x = n / 2;
      y = n / 2;
    } else {
      x = n / 2 - 1;
      y = n / 2 - 1;
    }
    int num = 0;
    grid[x][y] = num++;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
    int current_dir = 0;
    int steps = 1;
    while (num < n * n) {
      for (int d = 0; d < 2; ++d) {
        for (int i = 0; i < steps; ++i) {
          x += dir[current_dir][0];
          y += dir[current_dir][1];
          if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != -1) {
            // Adjust position if out of bounds or already filled
            x -= dir[current_dir][0];
            y -= dir[current_dir][1];
            continue;
          }
          grid[x][y] = num++;
        }
        current_dir = (current_dir + 1) % 4;
      }
      steps++;
    }
    // Fill any remaining cells (shouldn't be necessary)
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == -1) {
          grid[i][j] = num++;
        }
      }
    }
    // Output the grid
    for (const auto &row : grid) {
      for (int val : row) {
        cout << val << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2101/323986963
