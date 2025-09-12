/*C1. Magnitude (Easy Version)
time limit per test2 seconds
memory limit per test256 megabytes
The two versions of the problem are different. You may want to read both
versions. You can make hacks only if both versions are solved.

You are given an array 𝑎
 of length 𝑛
. Start with 𝑐=0
. Then, for each 𝑖
 from 1
 to 𝑛
 (in increasing order) do exactly one of the following:

Option 1
: set 𝑐
 to 𝑐+𝑎𝑖
.
Option 2
: set 𝑐
 to |𝑐+𝑎𝑖|
, where |𝑥|
 is the absolute value of 𝑥
.
Let the maximum final value of 𝑐
 after the procedure described above be equal to 𝑘
. Find 𝑘
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
).

The second line of each case contains 𝑛
 integers 𝑎1
, 𝑎2
, 𝑎3
, …
, 𝑎𝑛
 (−109≤𝑎𝑖≤109
).

The sum of 𝑛
 over all test cases does not exceed 3⋅105
.

Output
For each test case, output a single integer — the value of 𝑘
.

Example
InputCopy
5
4
10 -9 -3 4
8
1 4 3 4 1 4 3 4
3
-1 -2 -3
4
-1000000000 1000000000 1000000000 1000000000
4
1 9 8 4
OutputCopy
6
24
6
4000000000
22
Note
In the first test case, if we set 𝑐
 to its absolute value every time we add to it, we end up with 6
. It can be shown that this is the maximum result.

In the second test case, taking the absolute value will never change anything,
so we can just sum the array without doing anything to get 24
.

In the third test case, it is optimal to wait until the end to set 𝑐
 to its absolute value, resulting in an answer of 6
.
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
    ll n;
    cin >> n;
    ll mn = 0, mx = 0;
    for (ll p = 0; p < n; p++) {
      ll x;
      cin >> x;
      mn += x;
      mx += x;
      if (mn + mx < 0) {
        mx = -mn;
      }
    }
    cout << mx << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1984/338154862
