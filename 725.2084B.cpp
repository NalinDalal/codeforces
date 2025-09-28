/*B. MIN = GCD
time limit per test1 second
memory limit per test256 megabytes

You are given a positive integer sequence 𝑎
 of length 𝑛
. Determine if it is possible to rearrange 𝑎
 such that there exists an integer 𝑖
 (1≤𝑖<𝑛
) satisfying
min([𝑎1,𝑎2,…,𝑎𝑖])=gcd([𝑎𝑖+1,𝑎𝑖+2,…,𝑎𝑛]).

Here gcd(𝑐)
 denotes the greatest common divisor of 𝑐
, which is the maximum positive integer that divides all integers in 𝑐
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤105
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤1018
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output "Yes" if it is possible, and "No" otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
7
2
1 1
2
1 2
3
2 2 3
3
2 3 4
5
4 5 6 9 3
3
998244359987710471 99824435698771045 1000000007
6
1 1 4 5 1 4
OutputCopy
Yes
No
Yes
No
Yes
Yes
Yes
Note
In the first test case, rearrange 𝑎
 to [1,1]
 and let 𝑖=1
, then min([1])=gcd([1])
.

In the second test case, it can be shown that it is impossible.

In the third test case, rearrange 𝑎
 to [3,2,2]
 and let 𝑖=2
, then min([3,2])=gcd([2])
.

In the fifth test case, rearrange 𝑎
 to [3,4,5,6,9]
 and let 𝑖=3
, then min([3,4,5])=gcd([6,9])
.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll idx = 0, mn = LLONG_MAX;

    for (ll p = 0; p < n; p++) {
      cin >> v[p];
      if (v[p] < mn) {
        mn = v[p];
        idx = p;
      }
    }

    ll g = 0;
    for (ll p = 0; p < n; p++) {
      if (p == idx || (v[p] % mn))
        continue;
      g = gcd(g, v[p] / mn);
    }

    cout << (g == 1 ? "Yes\n" : "No\n");
  }
}

// sub: https://codeforces.com/problemset/submission/2084/340912975
