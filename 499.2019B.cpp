/*B. All Pairs Segments
time limit per test1.5 seconds
memory limit per test256 megabytes
Shirobon - FOX
⠀
You are given 𝑛
 points on the 𝑥
 axis, at increasing positive integer coordinates 𝑥1<𝑥2<…<𝑥𝑛
.

For each pair (𝑖,𝑗)
 with 1≤𝑖<𝑗≤𝑛
, you draw the segment [𝑥𝑖,𝑥𝑗]
. The segments are closed, i.e., a segment [𝑎,𝑏]
 contains the points 𝑎,𝑎+1,…,𝑏
.

You are given 𝑞
 queries. In the 𝑖
-th query, you are given a positive integer 𝑘𝑖
, and you have to determine how many points with integer coordinates are
contained in exactly 𝑘𝑖 segments.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
, 𝑞
 (2≤𝑛≤105
, 1≤𝑞≤105
) — the number of points and the number of queries.

The second line of each test case contains 𝑛
 integers 𝑥1,𝑥2,…,𝑥𝑛
 (1≤𝑥1<𝑥2<…<𝑥𝑛≤109
) — the coordinates of the 𝑛
 points.

The third line of each test case contains 𝑞
 integers 𝑘1,𝑘2,…,𝑘𝑞
 (1≤𝑘𝑖≤1018
) — the parameters of the 𝑞
 queries.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
, and the sum of 𝑞
 over all test cases does not exceed 105
.

Output
For each test case, output a single line with 𝑞
 integers: the 𝑖
-th integer is the answer to the 𝑖
-th query.

Example
InputCopy
3
2 2
101 200
2 1
6 15
1 2 3 5 6 7
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
5 8
254618033 265675151 461318786 557391198 848083778
6 9 15 10 6 9 4 4294967300
OutputCopy
0 100
0 0 0 0 2 0 0 0 3 0 2 0 0 0 0
291716045 0 0 0 291716045 0 301749698 0
Note
In the first example, you only draw the segment [101,200]
. No point is contained in exactly 2
 segments, and the 100
 points 101,102,…,200
 are contained in exactly 1
 segment.

In the second example, you draw 15
 segments:
[1,2],[1,3],[1,5],[1,6],[1,7],[2,3],[2,5],[2,6],[2,7],[3,5],[3,6],[3,7],[5,6],[5,7],[6,7]
. Points 1,7
 are contained in exactly 5
 segments; points 2,4,6
 are contained in exactly 9
 segments; points 3,5
 are contained in exactly 11
 segments.



*/

#include <iostream>
#include <map>
typedef long long ll;

int main() {

  ll t;
  std::cin >> t;
  while (t--) {
    ll n, q;
    std::cin >> n >> q;
    std::map<ll, ll> m;
    for (ll p = 1; p <= n; p++) {
      m[n * p - p * p + p - 1] += 1;
    }
    ll prev;
    std::cin >> prev;
    for (ll p = 1; p < n; p++) {
      ll x;
      std::cin >> x;
      m[p * (n - p)] += x - prev - 1;
      prev = x;
    }

    while (q--) {
      ll k;
      std::cin >> k;
      ll res = m.count(k) ? m[k] : 0;
      std::cout << res << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2019/328808404
