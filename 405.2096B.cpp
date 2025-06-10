/*B. Wonderful Gloves
time limit per test1 second
memory limit per test256 megabytes
You are the proud owner of many colorful gloves, and you keep them in a drawer.
Each glove is in one of 𝑛 colors numbered 1 to 𝑛 . Specifically, for each 𝑖 from
1 to 𝑛 , you have 𝑙𝑖 left gloves and 𝑟𝑖 right gloves with color 𝑖
.

Unfortunately, it's late at night, so you can't see any of your gloves. In other
words, you will only know the color and the type (left or right) of a glove
after you take it out of the drawer.

A matching pair of gloves with color 𝑖
 consists of exactly one left glove and one right glove with color 𝑖
. Find the minimum number of gloves you need to take out of the drawer to
guarantee that you have at least 𝑘 matching pairs of gloves with different
colors.

Formally, find the smallest positive integer 𝑥
 such that:

For any set of 𝑥
 gloves you take out of the drawer, there will always be at least 𝑘
 matching pairs of gloves with different colors.
Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
, 𝑘
 (1≤𝑘≤𝑛≤2⋅105
) — the number of different colors, and the minimum number of required matching
pairs of gloves.

The second line of each test case contains 𝑛
 integers 𝑙1,𝑙2,…,𝑙𝑛
 (1≤𝑙𝑖≤109
) — the number of left gloves with color 𝑖
 for each 𝑖
 from 1
 to 𝑛
.

The third line of each test case contains 𝑛
 integers 𝑟1,𝑟2,…,𝑟𝑛
 (1≤𝑟𝑖≤109
) — the number of right gloves with color 𝑖
 for each 𝑖
 from 1
 to 𝑛
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum number of gloves you
need to take out of the drawer.

Example
InputCopy
5
3 3
1 1 1
1 1 1
1 1
100
1
3 2
100 1 1
200 1 1
5 2
97 59 50 87 36
95 77 33 13 74
10 6
97 59 50 87 36 95 77 33 13 74
91 14 84 33 54 89 68 34 14 15
OutputCopy
6
101
303
481
1010
Note
In the first test case, you must take out all of the gloves, so the answer is 6
.

In the second test case, the answer is 101
. If you take out 100
 gloves or fewer, then it is possible that all of them are left gloves, which
means you won't have a matching pair of gloves.

In the third test case, the answer is 303
. If you only take out 302
 gloves, then one possible scenario is as follows:

Color 1
: 100
 left gloves, 200
 right gloves
Color 2
: 1
 left glove, 0
 right gloves
Color 3
: 0
 left gloves, 1
 right glove
You only have multiple matching pairs of gloves with color 1
. So you won't have at least 2
 matching pairs of gloves with different colors.



*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> vl(n), vr(n), v(n);
    ll total = 0;

    for (ll p = 0; p < n; p++)
      cin >> vl[p];
    for (ll p = 0; p < n; p++)
      cin >> vr[p];

    for (ll p = 0; p < n; p++) {
      v[p] = min(vl[p], vr[p]);
      total += vl[p] + vr[p];
    }

    sort(v.begin(), v.end());
    for (ll p = 0; p < n - k; p++)
      total -= v[p];
    total -= (v[n - k] - 1);

    cout << total << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2096/323712108
