/* A. Sliding
time limit per test1 second
memory limit per test256 megabytes
Red was ejected. They were not the imposter.
There are 𝑛
 rows of 𝑚
 people. Let the position in the 𝑟
-th row and the 𝑐
-th column be denoted by (𝑟,𝑐)
. Number each person starting from 1
 in row-major order, i.e., the person numbered (𝑟−1)⋅𝑚+𝑐
 is initially at (𝑟,𝑐)
.

The person at (𝑟,𝑐)
 decides to leave. To fill the gap, let the person who left be numbered 𝑖
. Each person numbered 𝑗>𝑖
 will move to the position where the person numbered 𝑗−1
 is initially at. The following diagram illustrates the case where 𝑛=2
, 𝑚=3
, 𝑟=1
, and 𝑐=2
.


Calculate the sum of the Manhattan distances of each person's movement. If a
person was initially at (𝑟0,𝑐0) and then moved to (𝑟1,𝑐1) , the Manhattan
distance is |𝑟0−𝑟1|+|𝑐0−𝑐1|
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The only line of each testcase contains 4
 integers 𝑛
, 𝑚
, 𝑟
, and 𝑐
 (1≤𝑟≤𝑛≤106
, 1≤𝑐≤𝑚≤106
), where 𝑛
 is the number of rows, 𝑚
 is the number of columns, and (𝑟,𝑐)
 is the position where the person who left is initially at.

Output
For each test case, output a single integer denoting the sum of the Manhattan
distances.

Example
InputCopy
4
2 3 1 2
2 2 2 1
1 1 1 1
1000000 1000000 1 1
OutputCopy
6
1
0
1999998000000
Note
For the first test case, the person numbered 2
 leaves, and the distances of the movements of the person numbered 3
, 4
, 5
, and 6
 are 1
, 3
, 1
, and 1
, respectively. So the answer is 1+3+1+1=6
.

For the second test case, the person numbered 3
 leaves, and the person numbered 4
 moves. The answer is 1
.



*/

#include <iostream>
typedef long long ll;
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, m, r, c;
    cin >> n >> m >> r >> c;
    ll res = (n - r) * m + (m - c) * 1 + (n - r) * (m - 1) * 1;
    cout << res << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2035/323078973
