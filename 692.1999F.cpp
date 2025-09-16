/*F. Greetings
time limit per test5 seconds
memory limit per test256 megabytes
There are 𝑛
 people on the number line; the 𝑖
-th person is at point 𝑎𝑖
 and wants to go to point 𝑏𝑖
. For each person, 𝑎𝑖<𝑏𝑖
, and the starting and ending points of all people are distinct. (That is, all
of the 2𝑛 numbers 𝑎1,𝑎2,…,𝑎𝑛,𝑏1,𝑏2,…,𝑏𝑛 are distinct.)

All the people will start moving simultaneously at a speed of 1
 unit per second until they reach their final point 𝑏𝑖
. When two people meet at the same point, they will greet each other once. How
many greetings will there be?

Note that a person can still greet other people even if they have reached their
final point.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of people.

Then 𝑛
 lines follow, the 𝑖
-th of which contains two integers 𝑎𝑖
 and 𝑏𝑖
 (−109≤𝑎𝑖<𝑏𝑖≤109
) — the starting and ending positions of each person.

For each test case, all of the 2𝑛
 numbers 𝑎1,𝑎2,…,𝑎𝑛,𝑏1,𝑏2,…,𝑏𝑛
 are distinct.

The sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer denoting the number of greetings
that will happen.

Example
InputCopy
5
2
2 3
1 4
6
2 6
3 9
4 5
1 8
7 10
-2 100
4
-10 10
-5 5
-12 12
-13 13
5
-4 9
-2 5
3 4
6 7
8 10
4
1 2
3 4
5 6
7 8
OutputCopy
1
9
6
4
0
Note
In the first test case, the two people will meet at point 3
 and greet each other.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<vector<ll>, ll> mergesort(vector<ll> w) {
  const ll n = w.size();
  if (n <= 1)
    return {w, 0};

  ll xsz = n / 2, ysz = n - n / 2;
  vector<ll> x(xsz), y(ysz);
  for (ll p = 0; p < xsz; p++)
    x[p] = w[p];
  for (ll p = 0; p < ysz; p++)
    y[p] = w[xsz + p];

  auto rmx = mergesort(x);
  x = rmx.first;
  auto rmy = mergesort(y);
  y = rmy.first;

  ll a = 0, b = 0, cnt = 0;
  vector<ll> out(n);
  for (ll p = 0; p < n; p++) {
    if (a < xsz && b < ysz) {
      if (y[b] < x[a]) {
        out[p] = y[b++];
        cnt += (xsz - a);
      } else {
        out[p] = x[a++];
      }
    } else if (a == xsz) {
      out[p] = y[b++];
      cnt += (xsz - a);
    } else if (b == ysz) {
      out[p] = x[a++];
    }
  }

  return {out, rmx.second + rmy.second + cnt};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (ll p = 0; p < n; p++) {
      cin >> v[p].first >> v[p].second;
    }
    sort(v.begin(), v.end());

    vector<ll> w(n);
    for (ll p = 0; p < n; p++)
      w[p] = v[p].second;

    cout << mergesort(w).second << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1915/338852511
