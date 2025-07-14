/*B. Forming Triangles
time limit per test2 seconds
memory limit per test256 megabytes
You have 𝑛
 sticks, numbered from 1
 to 𝑛
. The length of the 𝑖
-th stick is 2𝑎𝑖
.

You want to choose exactly 3
 sticks out of the given 𝑛
 sticks, and form a non-degenerate triangle out of them, using the sticks as the
sides of the triangle. A triangle is called non-degenerate if its area is
strictly greater than 0
.

You have to calculate the number of ways to choose exactly 3
 sticks so that a triangle can be formed out of them. Note that the order of
choosing sticks does not matter (for example, choosing the 1 -st, 2 -nd and 4
-th stick is the same as choosing the 2
-nd, 4
-th and 1
-st stick).

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer 𝑛
 (1≤𝑛≤3⋅105
);
the second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤𝑛
).
Additional constraint on the input: the sum of 𝑛
 over all test cases does not exceed 3⋅105
.

Output
For each test case, print one integer — the number of ways to choose exactly 3
 sticks so that a triangle can be formed out of them.

Example
InputCopy
4
7
1 1 1 1 1 1 1
4
3 2 1 3
3
1 2 3
1
1
OutputCopy
35
2
0
0
Note
In the first test case of the example, any three sticks out of the given 7
 can be chosen.

In the second test case of the example, you can choose the 1
-st, 2
-nd and 4
-th stick, or the 1
-st, 3
-rd and 4
-th stick.

In the third test case of the example, you cannot form a triangle out of the
given sticks with lengths 2 , 4 and 8.
*/

#include <iostream>
#include <map>
typedef long long ll;

int main() {

  ll t;
  std::cin >> t;
  while (t--) {
    ll n;
    std::cin >> n;
    std::map<ll, ll> m;
    for (ll p = 0; p < n; p++) {
      ll x;
      std::cin >> x;
      ++m[x];
    }
    ll prev(0);
    ll cnt(0);
    for (auto it = m.begin(); it != m.end(); it++) {
      ll val = it->second;
      cnt += (val >= 2) * val * (val - 1) * prev / 2;
      cnt += (val >= 3) * val * (val - 1) * (val - 2) / 6;
      prev += val;
    }

    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1922/328939559
