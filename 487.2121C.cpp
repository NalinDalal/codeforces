/*C. Those Who Are With Us
time limit per test1 second
memory limit per test256 megabytes
You are given a matrix of integers with 𝑛
 rows and 𝑚
 columns. The cell at the intersection of the 𝑖
-th row and the 𝑗
-th column contains the number 𝑎𝑖𝑗
.

You can perform the following operation exactly once:

Choose two numbers 1≤𝑟≤𝑛
 and 1≤𝑐≤𝑚
.
For all cells (𝑖,𝑗)
 in the matrix such that 𝑖=𝑟
 or 𝑗=𝑐
, decrease 𝑎𝑖𝑗
 by one.
You need to find the minimal possible maximum value in the matrix 𝑎
 after performing exactly one such operation.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛⋅𝑚≤105
) — the number of rows and columns in the matrix.

The next 𝑛
 lines of each test case describe the matrix 𝑎
. The 𝑖
-th line contains 𝑚
 integers 𝑎𝑖1,𝑎𝑖2,…,𝑎𝑖𝑚
 (1≤𝑎𝑖𝑗≤100
) — the elements in the 𝑖
-th row of the matrix.

It is guaranteed that the sum of 𝑛⋅𝑚
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum maximum value in the matrix 𝑎
 after performing exactly one operation.

Example
InputCopy
10
1 1
1
1 2
1 2
2 1
2
1
2 2
4 2
3 4
3 4
1 2 3 2
3 2 1 3
2 1 3 2
4 3
1 5 1
3 1 3
5 5 5
3 5 1
4 4
1 3 3 2
2 3 2 2
1 2 2 1
3 3 2 3
2 2
2 2
1 2
3 2
1 2
2 1
1 2
3 3
2 1 1
1 2 1
1 1 2
OutputCopy
0
1
1
3
2
4
3
1
1
2
Note
In the first three test cases, you can choose 𝑟=1
 and 𝑐=1
.

In the fourth test case, you can choose 𝑟=1
 and 𝑐=2
.


In the fifth test case, you can choose 𝑟=2
 and 𝑐=3
.


In the sixth test case, you can choose 𝑟=3 and 𝑐=2.
*/

#include <iostream>
#include <set>
#include <vector>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n, m;
    std::cin >> n >> m;
    std::vector<std::vector<long>> f(n, std::vector<long>(m, 0));
    long mx(0);
    for (long row = 0; row < n; row++) {
      for (long col = 0; col < m; col++) {
        std::cin >> f[row][col];
        mx = (mx > f[row][col] ? mx : f[row][col]);
      }
    }

    std::vector<long> vr(n), vc(m);
    long mxcnt(0);
    for (long row = 0; row < n; row++) {
      for (long col = 0; col < m; col++) {
        if (f[row][col] < mx) {
          continue;
        }
        ++vr[row];
        ++vc[col];
        ++mxcnt;
      }
    }

    bool single(false);
    for (long row = 0; !single && row < n; row++) {
      for (long col = 0; !single && col < m; col++) {
        single |= ((vr[row] + vc[col] - (f[row][col] == mx)) == mxcnt);
        // std::cout << "Row:" << row << "\tCol:" << col << "\tf:" <<
        // f[row][col] << "\tVR:" << vr[row] << "VC:" << vc[col] << "\tismx:" <<
        // (f[row][col] == mx) << "\tSingle:" << single << std::endl;
      }
    }

    std::cout << (mx - single) << std::endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2121/328170163
