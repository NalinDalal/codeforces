/*D. Counting Pairs
time limit per test2 seconds
memory limit per test256 megabytes
You are given a sequence 𝑎
, consisting of 𝑛
 integers, where the 𝑖
-th element of the sequence is equal to 𝑎𝑖
. You are also given two integers 𝑥
 and 𝑦
 (𝑥≤𝑦
).

A pair of integers (𝑖,𝑗)
 is considered interesting if the following conditions are met:

1≤𝑖<𝑗≤𝑛
;
if you simultaneously remove the elements at positions 𝑖
 and 𝑗
 from the sequence 𝑎
, the sum of the remaining elements is at least 𝑥
 and at most 𝑦
.
Your task is to determine the number of interesting pairs of integers for the
given sequence 𝑎
.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of two lines:

The first line contains three integers 𝑛,𝑥,𝑦
 (3≤𝑛≤2⋅105
, 1≤𝑥≤𝑦≤2⋅1014
);
The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).
Additional constraint on the input: the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the number of interesting pairs of
integers for the given sequence 𝑎
.

Example
InputCopy
7
4 8 10
4 6 3 6
6 22 27
4 9 6 3 4 5
3 8 10
3 2 1
3 1 1
2 3 4
3 3 6
3 2 1
4 4 12
3 3 2 1
6 8 8
1 1 2 2 2 3
OutputCopy
4
7
0
0
1
5
6
Note
In the first example, there are 4
 interesting pairs of integers:

(1,2)
;
(1,4)
;
(2,3)
;
(3,4)
.

*/

/* count all pairs (i, j) with i < j such that:

𝑥≤sum of remaining elements after removing 
𝑎[𝑖] and 𝑎[]𝑗]≤𝑦

total = sum(a)

After removing a[i] + a[j], remaining sum = total - a[i] - a[j]

We want:
x≤total−a[i]−a[j]≤y⇒total−y≤a[i]+a[j]≤total−x
So for any pair (i, j):
We want: low≤a[i]+a[j]≤high where low=total−y,high=total−x

*/
/*Sort the array a

For each index i, use two pointers or binary search to count j > i such that:

low−a[i]≤a[j]≤high−a[i]
Add count to result.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll total = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      total += a[i];
    }

    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      ll low = total - y;
      ll high = total - x;

      // a[i] + a[j] should be in [low, high]
      // => a[j] in [low - a[i], high - a[i]]
      ll left = low - a[i];
      ll right = high - a[i];

      // Binary search for lower and upper bounds
      auto l = lower_bound(a.begin() + i + 1, a.end(), left);
      auto r = upper_bound(a.begin() + i + 1, a.end(), right);
      ans += (r - l);
    }

    cout << ans << '\n';
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2051/328356382
