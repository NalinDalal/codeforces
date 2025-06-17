/*B. Make Three Regions
time limit per test2 seconds
memory limit per test256 megabytes
There is a grid, consisting of 2
 rows and 𝑛
 columns. Each cell of the grid is either free or blocked.

A free cell 𝑦
 is reachable from a free cell 𝑥
 if at least one of these conditions holds:

𝑥
 and 𝑦
 share a side;
there exists a free cell 𝑧
 such that 𝑧
 is reachable from 𝑥
 and 𝑦
 is reachable from 𝑧
.
A connected region is a set of free cells of the grid such that all cells in it
are reachable from one another, but adding any other free cell to the set
violates this rule.

For example, consider the following layout, where white cells are free, and dark
grey cells are blocked:


There are 3
 regions in it, denoted with red, green and blue color respectively:


The given grid contains at most 1
 connected region. Your task is to calculate the number of free cells meeting
the following constraint:

if this cell is blocked, the number of connected regions becomes exactly 3
.
Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of columns.

The 𝑖
-th of the next two lines contains a description of the 𝑖
-th row of the grid — the string 𝑠𝑖
, consisting of 𝑛
 characters. Each character is either . (denoting a free cell) or x (denoting a
blocked cell).

Additional constraint on the input:

the given grid contains at most 1
 connected region;
the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.
Output
For each test case, print a single integer — the number of cells such that the
number of connected regions becomes 3 if this cell is blocked.

Example
InputCopy
4
8
.......x
.x.xx...
2
..
..
3
xxx
xxx
9
..x.x.x.x
x.......x
OutputCopy
1
0
0
2
Note
In the first test case, if the cell (1,3)
 is blocked, the number of connected regions becomes 3
 (as shown in the picture from the statement).



*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v(2);
    cin >> v[0] >> v[1];
    int cnt = 0;
    for (long col = 1; col + 1 < v[0].size(); col++) {
      for (long row = 0; row < 2; row++) {
        if (v[row][col - 1] == 'x' || v[row][col] == 'x' ||
            v[row][col + 1] == 'x') {
          continue;
        }
        if (v[1 - row][col] == 'x') {
          continue;
        }
        if (v[1 - row][col - 1] == '.' || v[1 - row][col + 1] == '.') {
          continue;
        }
        ++cnt;
      }
    }

    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1997/324717708
