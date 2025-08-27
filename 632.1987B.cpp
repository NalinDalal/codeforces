/*B. K-Sort
time limit per test1 second
memory limit per test256 megabytes
You are given an array of integers 𝑎
 of length 𝑛
.

You can apply the following operation any number of times (maybe, zero):

First, choose an integer 𝑘
 such that 1≤𝑘≤𝑛
 and pay 𝑘+1
 coins.
Then, choose exactly 𝑘
 indices such that 1≤𝑖1<𝑖2<…<𝑖𝑘≤𝑛
.
Then, for each 𝑥
 from 1
 to 𝑘
, increase 𝑎𝑖𝑥
 by 1
.
Find the minimum number of coins needed to make 𝑎
 non-decreasing. That is, 𝑎1≤𝑎2≤…≤𝑎𝑛
.

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the
test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output a single integer — the minimum number of coins needed
to make 𝑎 non-decreasing.

Example
InputCopy
5
3
1 7 9
5
2 1 4 7 6
4
1 3 2 4
1
179
9
344 12 37 60 311 613 365 328 675
OutputCopy
0
3
2
0
1821
Note
In the first test case, 𝑎
 is already sorted, so you don't have to spend any coins.

In the second test case, the optimal sequence of operations is:

Choose 𝑘=2
 and the indices 2
 and 5
: [2,1,4,7,6]→[2,2,4,7,7]
. This costs 3
 coins.
It can be proven that it is not possible to make 𝑎
 non-decreasing by spending less than 3
 coins.
*/

/*Track required current_max.

Traverse left to right:
    - Maintain mx = a[0].
    - For each i:
        - If a[i] < mx: need += (mx - a[i]).
        - Else update mx = a[i].

Compute need = ∑ (prefix_max - a[i]) where prefix_max is the maximum so far.

If need == 0, answer=0.

Else, answer=need + (prefix_max_of_array - a[0]).
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    ll pref_max = 0, s = 0, mx = 0;
    for (int i = 0; i < n; i++) {
      pref_max = max(pref_max, a[i]);
      ll d = pref_max - a[i];
      s += d;
      mx = max(mx, d);
    }

    cout << (s + mx) << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1987/335753766
