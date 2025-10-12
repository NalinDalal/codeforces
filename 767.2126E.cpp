/*E. G-C-D, Unlucky!
time limit per test2 seconds
memory limit per test256 megabytes
Two arrays 𝑝
 and 𝑠
 of length 𝑛
 are given, where 𝑝
 is the prefix GCD∗
 of some array 𝑎
, and 𝑠
 is the suffix GCD of the same array 𝑎
. In other words, if the array 𝑎
 existed, then for each 1≤𝑖≤𝑛
, the following equalities would hold both:

𝑝𝑖=gcd(𝑎1,𝑎2,…,𝑎𝑖)
𝑠𝑖=gcd(𝑎𝑖,𝑎𝑖+1,…,𝑎𝑛)
.
Determine whether there exists such an array 𝑎
 for which the given arrays 𝑝
 and 𝑠
 can be obtained.
∗
gcd(𝑥,𝑦)
 denotes the greatest common divisor (GCD) of integers 𝑥
 and 𝑦
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of three lines:

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 (1≤𝑝𝑖≤109
) — the elements of the array.

The third line of each test case contains 𝑛
 integers 𝑠1,𝑠2,…,𝑠𝑛
 (1≤𝑠𝑖≤109
) — the elements of the array.

It is guaranteed that the sum of all 𝑛
 across all test cases does not exceed 105
.

Output
For each test case, output "Yes" (without quotes) if there exists an array 𝑎
 for which the given arrays 𝑝
 and 𝑠
 can be obtained, and "No" (without quotes) otherwise.

You may output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
5
6
72 24 3 3 3 3
3 3 3 6 12 144
3
1 2 3
4 5 6
5
125 125 125 25 25
25 25 25 25 75
4
123 421 282 251
125 1981 239 223
3
124 521 125
125 121 121
OutputCopy
YES
NO
YES
NO
NO
Note
For the first test case, a possible array is: [72, 24, 3, 6, 12, 144
].

For the second test case, it can be shown that such arrays do not exist.

For the third test case, there exists an array: [125, 125, 125, 25, 75].
*/

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    vector<ll> v(n), w(n), a(n);
    for (ll &x : v)
      cin >> x;
    for (ll &x : w)
      cin >> x;

    for (ll i = 0; i < n; i++)
      a[i] = v[i] * w[i] / gcd(v[i], w[i]);

    bool possible = true;
    ll g = 0;

    for (ll i = 0; i < n && possible; i++) {
      g = gcd(g, a[i]);
      if (g != v[i])
        possible = false;
    }

    g = 0;
    for (ll i = n - 1; i >= 0 && possible; i--) {
      g = gcd(g, a[i]);
      if (g != w[i])
        possible = false;
    }

    cout << (possible ? "YES\n" : "NO\n");
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2126/343249854
