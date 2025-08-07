/*B. Points on Plane
time limit per test2 seconds
memory limit per test256 megabytes
You are given a two-dimensional plane, and you need to place 𝑛
 chips on it.

You can place a chip only at a point with integer coordinates. The cost of
placing a chip at the point (𝑥,𝑦) is equal to |𝑥|+|𝑦| (where |𝑎| is the absolute
value of 𝑎
).

The cost of placing 𝑛
 chips is equal to the maximum among the costs of each chip.

You need to place 𝑛
 chips on the plane in such a way that the Euclidean distance between each pair
of chips is strictly greater than 1 , and the cost is the minimum possible.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Next 𝑡
 cases follow.

The first and only line of each test case contains one integer 𝑛
 (1≤𝑛≤1018
) — the number of chips you need to place.

Output
For each test case, print a single integer — the minimum cost to place 𝑛
 chips if the distance between each pair of chips must be strictly greater than
1
.

Example
InputCopy
4
1
3
5
975461057789971042
OutputCopy
0
1
2
987654321
Note
In the first test case, you can place the only chip at point (0,0)
 with total cost equal to 0+0=0
.

In the second test case, you can, for example, place chips at points (−1,0)
, (0,1)
 and (1,0)
 with costs |−1|+|0|=1
, |0|+|1|=1
 and |0|+|1|=1
. Distance between each pair of chips is greater than 1
 (for example, distance between (−1,0)
 and (0,1)
 is equal to 2‾√
). The total cost is equal to max(1,1,1)=1
.

In the third test case, you can, for example, place chips at points (−1,−1)
, (−1,1)
, (1,1)
, (0,0)
 and (0,2)
. The total cost is equal to max(2,2,2,0,2)=2
.
*/
#include <iostream>
typedef long long ll;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    ll n;
    std::cin >> n;

    ll left = 0, right = 1e9, res = 0;

    while (left <= right) {
      ll mid = (left + right) / 2;
      if (mid * mid < n) {
        res = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    std::cout << res << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1809/332740273
