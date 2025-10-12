/*C. Build Permutation
time limit per test1 second
memory limit per test256 megabytes
A 0
-indexed array 𝑎
 of size 𝑛
 is called good if for all valid indices 𝑖
 (0≤𝑖≤𝑛−1
), 𝑎𝑖+𝑖
 is a perfect square†
.

Given an integer 𝑛
. Find a permutation‡
 𝑝
 of [0,1,2,…,𝑛−1]
 that is good or determine that no such permutation exists.

†
 An integer 𝑥
 is said to be a perfect square if there exists an integer 𝑦
 such that 𝑥=𝑦2
.

‡
 An array 𝑏
 is a permutation of an array 𝑎
 if 𝑏
 consists of the elements of 𝑎
 in arbitrary order. For example, [4,2,3,4]
 is a permutation of [3,2,4,4]
 while [1,2,2]
 is not a permutation of [1,2,3]
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The only line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the length of the permutation 𝑝
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output 𝑛
 distinct integers 𝑝0,𝑝1,…,𝑝𝑛−1
 (0≤𝑝𝑖≤𝑛−1
) — the permutation 𝑝
 — if the answer exists, and −1
 otherwise.

Example
InputCopy
3
3
4
7
OutputCopy
1 0 2
0 3 2 1
1 0 2 6 5 4 3
Note
In the first test case, we have 𝑛=3
. The array 𝑝=[1,0,2]
 is good since 1+0=12
, 0+1=12
, and 2+2=22

In the second test case, we have 𝑛=4
. The array 𝑝=[0,3,2,1]
 is good since 0+0=02
, 3+1=22
, 2+2=22
, and 1+3=22
.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// --- Fast I/O setup ---
#define FAST_IO                                                                \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);

// --- Solution ---
void solve() {
  ll n;
  cin >> n;
  vector<ll> ans(n);
  ll r = n - 1;

  while (r >= 0) {
    ll s = ceil(sqrt(r));
    ll d = s * s - r;
    for (ll i = r; i >= d; --i)
      ans[i] = s * s - i;
    r = d - 1;
  }

  for (ll x : ans)
    cout << x << ' ';
  cout << '\n';
}

// --- Main ---
int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1713/343249412
