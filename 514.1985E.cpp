/*E. Secret Box
time limit per test1 second
memory limit per test256 megabytes
Ntarsis has a box 𝐵
 with side lengths 𝑥
, 𝑦
, and 𝑧
. It lies in the 3D coordinate plane, extending from (0,0,0)
 to (𝑥,𝑦,𝑧)
.

Ntarsis has a secret box 𝑆
. He wants to choose its dimensions such that all side lengths are positive
integers, and the volume of 𝑆 is 𝑘 . He can place 𝑆 somewhere within 𝐵 such
that:

𝑆
 is parallel to all axes.
every corner of 𝑆
 lies on an integer coordinate.
𝑆
 is magical, so when placed at an integer location inside 𝐵
, it will not fall to the ground.

Among all possible ways to choose the dimensions of 𝑆
, determine the maximum number of distinct locations he can choose to place his
secret box 𝑆 inside 𝐵 . Ntarsis does not rotate 𝑆 once its side lengths are
selected.

Input
The first line consists of an integer 𝑡
, the number of test cases (1≤𝑡≤2000
). The description of the test cases follows.

The first and only line of each test case contains four integers 𝑥,𝑦,𝑧
 and 𝑘
 (1≤𝑥,𝑦,𝑧≤2000
, 1≤𝑘≤𝑥⋅𝑦⋅𝑧
).

It is guaranteed the sum of all 𝑥
, sum of all 𝑦
, and sum of all 𝑧
 do not exceed 2000
 over all test cases.

Note that 𝑘
 may not fit in a standard 32-bit integer data type.

Output
For each test case, output the answer as an integer on a new line. If there is
no way to select the dimensions of 𝑆 so it fits in 𝐵 , output 0
.

Example
InputCopy
7
3 3 3 8
3 3 3 18
5 1 1 1
2 2 2 7
3 4 2 12
4 3 1 6
1800 1800 1800 4913000000
OutputCopy
8
2
5
0
4
4
1030301
Note
For the first test case, it is optimal to choose 𝑆
 with side lengths 2
, 2
, and 2
, which has a volume of 2⋅2⋅2=8
. It can be shown there are 8
 ways to put 𝑆
 inside 𝐵
.

The coordinate with the least 𝑥
, 𝑦
, and 𝑧
 values for each possible arrangement of 𝑆
 are:

(0,0,0)
(1,0,0)
(0,1,0)
(0,0,1)
(1,0,1)
(1,1,0)
(0,1,1)
(1,1,1)
The arrangement of 𝑆
 with a coordinate of (0,0,0)
 is depicted below:


For the second test case, 𝑆
 with side lengths 2
, 3
, and 3
 are optimal.
*/

#include <iostream>
typedef long long ll;

int main() {

  ll t;
  std::cin >> t;
  while (t--) {
    ll x, y, z, k;
    std::cin >> x >> y >> z >> k;
    ll ans = 0;
    for (ll a = 1; a <= x; a++) {
      for (ll b = 1; b <= y; b++) {
        if (k % (a * b))
          continue;
        ll c = k / (a * b);
        if (c > z)
          continue;
        ll ways = (x - a + 1) * (y - b + 1) * (z - c + 1);
        ans = (ans > ways ? ans : ways);
      }
    }

    std::cout << ans << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1985/329585231
