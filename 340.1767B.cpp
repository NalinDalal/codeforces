/* B. Block Towers
time limit per test2 seconds
memory limit per test256 megabytes
There are 𝑛
 block towers, numbered from 1
 to 𝑛
. The 𝑖
-th tower consists of 𝑎𝑖
 blocks.

In one move, you can move one block from tower 𝑖
 to tower 𝑗
, but only if 𝑎𝑖>𝑎𝑗
. That move increases 𝑎𝑗
 by 1
 and decreases 𝑎𝑖
 by 1
. You can perform as many moves as you would like (possibly, zero).

What's the largest amount of blocks you can have on the tower 1
 after the moves?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

The first line of each testcase contains a single integer 𝑛
 (2≤𝑛≤2⋅105
) — the number of towers.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the number of blocks on each tower.

The sum of 𝑛
 over all testcases doesn't exceed 2⋅105
.

Output
For each testcase, print the largest amount of blocks you can have on the tower
1 after you make any number of moves (possibly, zero).

Example
InputCopy
4
3
1 2 3
3
1 2 2
2
1 1000000000
10
3 8 6 7 4 1 2 4 10 1
OutputCopy
3
2
500000001
9
Note
In the first testcase, you can move a block from tower 2
 to tower 1
, making the block counts [2,1,3]
. Then move a block from tower 3
 to tower 1
, making the block counts [3,1,2]
. Tower 1
 has 3
 blocks in it, and you can't obtain a larger amount.

In the second testcase, you can move a block from any of towers 2
 or 3
 to tower 1
, so that it has 2
 blocks in it.

In the third testcase, you can 500000000
 times move a block from tower 2
 to tower 1
. After that the block countes will be [500000001,500000000]
.


*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x;
    cin >> x;

    vector<int> v(n - 1);
    for (int i = 0; i + 1 < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int p = 0; p + 1 < n; p++) {
      if (v[p] <= x) {
        continue;
      }

      x = (v[p] + x + 1) / 2;
    }
    cout << x << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1767/319001665
