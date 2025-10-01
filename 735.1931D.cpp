/*D. Divisible Pairs
time limit per test2 seconds
memory limit per test256 megabytes
Polycarp has two favorite integers 𝑥
 and 𝑦
 (they can be equal), and he has found an array 𝑎
 of length 𝑛
.

Polycarp considers a pair of indices ⟨𝑖,𝑗⟩
 (1≤𝑖<𝑗≤𝑛
) beautiful if:

𝑎𝑖+𝑎𝑗
 is divisible by 𝑥
;
𝑎𝑖−𝑎𝑗
 is divisible by 𝑦
.
For example, if 𝑥=5
, 𝑦=2
, 𝑛=6
, 𝑎=
[1,2,7,4,9,6
], then the only beautiful pairs are:

⟨1,5⟩
: 𝑎1+𝑎5=1+9=10
 (10
 is divisible by 5
) and 𝑎1−𝑎5=1−9=−8
 (−8
 is divisible by 2
);
⟨4,6⟩
: 𝑎4+𝑎6=4+6=10
 (10
 is divisible by 5
) and 𝑎4−𝑎6=4−6=−2
 (−2
 is divisible by 2
).
Find the number of beautiful pairs in the array 𝑎
.
Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains three integers 𝑛
, 𝑥
, and 𝑦
 (2≤𝑛≤2⋅105
, 1≤𝑥,𝑦≤109
) — the size of the array and Polycarp's favorite integers.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the number of beautiful pairs in
the array 𝑎
.

Example
InputCopy
7
6 5 2
1 2 7 4 9 6
7 9 5
1 10 15 3 8 12 15
9 4 10
14 10 2 2 11 11 13 5 6
9 5 6
10 7 6 7 9 7 7 10 10
9 6 2
4 9 7 1 2 2 13 3 15
9 2 3
14 6 1 15 12 15 8 2 15
10 5 7
13 3 3 2 12 11 3 7 13 14
OutputCopy
2
0
1
3
5
7
0
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n, x, y;
    cin >> n >> x >> y;

    map<pair<ll, ll>, set<ll>> mods;
    ll cnt = 0;

    for (ll p = 0; p < n; p++) {
      ll a;
      cin >> a;

      pair<ll, ll> key = {(x - (a % x)) % x, a % y};

      cnt += mods[key].size();
      mods[{a % x, a % y}].insert(p);
    }

    cout << cnt << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1931/341295645
