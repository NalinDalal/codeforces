/*A. Swap Columns and Find a Path
time limit per test2 seconds
memory limit per test512 megabytes

There is a matrix consisting of 2
 rows and 𝑛
 columns. The rows are numbered from 1
 to 2
 from top to bottom; the columns are numbered from 1
 to 𝑛
 from left to right. Let's denote the cell on the intersection of the 𝑖
-th row and the 𝑗
-th column as (𝑖,𝑗)
. Each cell contains an integer; initially, the integer in the cell (𝑖,𝑗)
 is 𝑎𝑖,𝑗
.

You can perform the following operation any number of times (possibly zero):

choose two columns and swap them (i. e. choose two integers 𝑥
 and 𝑦
 such that 1≤𝑥<𝑦≤𝑛
, then swap 𝑎1,𝑥
 with 𝑎1,𝑦
, and then swap 𝑎2,𝑥
 with 𝑎2,𝑦
).
After performing the operations, you have to choose a path from the cell (1,1)
 to the cell (2,𝑛)
. For every cell (𝑖,𝑗)
 in the path except for the last, the next cell should be either (𝑖+1,𝑗)
 or (𝑖,𝑗+1)
. Obviously, the path cannot go outside the matrix.

The cost of the path is the sum of all integers in all (𝑛+1)
 cells belonging to the path. You have to perform the operations and choose a
path so that its cost is maximum possible.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤5000
). The description of the test cases follows.

Each test case consists of three lines:

the first line contains one integer 𝑛
 (1≤𝑛≤5000
) — the number of columns in the matrix;
the second line contains 𝑛
 integers 𝑎1,1,𝑎1,2,…,𝑎1,𝑛
 (−105≤𝑎𝑖,𝑗≤105
) — the first row of the matrix;
the third line contains 𝑛
 integers 𝑎2,1,𝑎2,2,…,𝑎2,𝑛
 (−105≤𝑎𝑖,𝑗≤105
) — the second row of the matrix.
It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 5000
.

Output
For each test case, print one integer — the maximum cost of a path you can
obtain.

Example
InputCopy
3
1
-10
5
3
1 2 3
10 -5 -3
4
2 8 5 3
1 10 3 4
OutputCopy
-5
16
29
Note
Here are the explanations of the first three test cases of the example. The left
matrix is the matrix given in the input, the right one is the state of the
matrix after several column swaps (possibly zero). The optimal path is
highlighted in green.





*/

#include <iostream>
#include <vector>
using namespace std;
int main() {

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    std::vector<long> a(n);
    for (long p = 0; p < n; p++) {
      cin >> a[p];
    }
    std::vector<long> b(n);
    for (long p = 0; p < n; p++) {
      cin >> b[p];
    }

    long add(-1e9), total(0);
    for (long p = 0; p < n; p++) {
      total += (a[p] > b[p] ? a[p] : b[p]);
      long second = (a[p] < b[p] ? a[p] : b[p]);
      add = (add > second ? add : second);
    }
    total += add;
    cout << total << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2046/325314451
