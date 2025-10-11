/*B. Balls of Steel
time limit per test1 second
memory limit per test256 megabytes
You have 𝑛
 distinct points (𝑥1,𝑦1),…,(𝑥𝑛,𝑦𝑛)
 on the plane and a non-negative integer parameter 𝑘
. Each point is a microscopic steel ball and 𝑘
 is the attract power of a ball when it's charged. The attract power is the same
for all balls.

In one operation, you can select a ball 𝑖
 to charge it. Once charged, all balls with Manhattan distance at most 𝑘
 from ball 𝑖
 move to the position of ball 𝑖
. Many balls may have the same coordinate after an operation.

More formally, for all balls 𝑗
 such that |𝑥𝑖−𝑥𝑗|+|𝑦𝑖−𝑦𝑗|≤𝑘
, we assign 𝑥𝑗:=𝑥𝑖
 and 𝑦𝑗:=𝑦𝑖
.

An example of an operation. After charging the ball in the center, two other
balls move to its position. On the right side, the red dot in the center is the
common position of those balls. Your task is to find the minimum number of
operations to move all balls to the same position, or report that this is
impossible.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The first line of each test case contains two integers 𝑛
, 𝑘
 (2≤𝑛≤100
, 0≤𝑘≤106
) — the number of balls and the attract power of all balls, respectively.

The following 𝑛
 lines describe the balls' coordinates. The 𝑖
-th of these lines contains two integers 𝑥𝑖
, 𝑦𝑖
 (0≤𝑥𝑖,𝑦𝑖≤105
) — the coordinates of the 𝑖
-th ball.

It is guaranteed that all points are distinct.

Output
For each test case print a single integer — the minimum number of operations to
move all balls to the same position, or −1 if it is impossible.

Example
InputCopy
3
3 2
0 0
3 3
1 1
3 3
6 7
8 8
6 9
4 1
0 0
0 1
0 2
0 3
OutputCopy
-1
1
-1
Note
In the first test case, there are three balls at (0,0)
, (3,3)
, and (1,1)
 and the attract power is 2
. It is possible to move two balls together with one operation, but not all
three balls together with any number of operations.

In the second test case, there are three balls at (6,7)
, (8,8)
, and (6,9)
 and the attract power is 3
. If we charge any ball, the other two will move to the same position, so we
only require one operation.

In the third test case, there are four balls at (0,0)
, (0,1)
, (0,2)
, and (0,3)
, and the attract power is 1
. We can show that it is impossible to move all balls to the same position with
a sequence of operations.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n, k;
    cin >> n >> k;
    vector<pair<long, long>> f(n);
    for (long i = 0; i < n; i++) {
      cin >> f[i].first >> f[i].second;
    }

    bool res = false;
    for (long p = 0; p < n; p++) {
      bool cur = true;
      for (long q = 0; q < n; q++) {
        long dx = abs(f[p].first - f[q].first);
        long dy = abs(f[p].second - f[q].second);
        if (dx + dy > k) {
          cur = false;
          break;
        }
      }
      if (cur) {
        res = true;
        break;
      }
    }

    cout << (res ? 1 : -1) << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1450/343073204
