/*B. Divan and a New Project
time limit per test1 second
memory limit per test256 megabytes
The company "Divan's Sofas" is planning to build 𝑛+1
 different buildings on a coordinate line so that:

the coordinate of each building is an integer number;
no two buildings stand at the same point.
Let 𝑥𝑖
 be the coordinate of the 𝑖
-th building. To get from the building 𝑖
 to the building 𝑗
, Divan spends |𝑥𝑖−𝑥𝑗|
 minutes, where |𝑦|
 is the absolute value of 𝑦
.

All buildings that Divan is going to build can be numbered from 0
 to 𝑛
. The businessman will live in the building 0
, the new headquarters of "Divan's Sofas". In the first ten years after
construction Divan will visit the 𝑖 -th building 𝑎𝑖 times, each time spending
2⋅|𝑥0−𝑥𝑖| minutes for walking.

Divan asks you to choose the coordinates for all 𝑛+1
 buildings so that over the next ten years the businessman will spend as little
time for walking as possible.

Input
Each test contains several test cases. The first line contains one integer
number 𝑡 (1≤𝑡≤103 ) — the number of test cases.

The first line of each case contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of buildings that "Divan's Sofas" is going to build, apart from
the headquarters.

The second line contains the sequence 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤106
), where 𝑎𝑖
 is the number of visits to the 𝑖
-th building.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, on the first line print the number 𝑇
 — the minimum time Divan will spend walking.

On the second line print the sequence 𝑥0,𝑥1,…,𝑥𝑛
 of 𝑛+1
 integers, where 𝑥𝑖
 (−106≤𝑥𝑖≤106
) is the selected coordinate of the 𝑖
-th building. It can be shown that an optimal answer exists with coordinates not
exceeding 106
.

If there are multiple answers, print any of them.

Example
InputCopy
4
3
1 2 3
5
3 8 10 6 1
5
1 1 1 1 1
1
0
OutputCopy
14
2 4 1 3
78
1 -1 0 2 3 4
18
3 6 1 5 2 4
0
1 2
Note
Let's look at the first example.

Divan will visit the first building 𝑎1=1
 times, the second 𝑎2=2
 times and the third 𝑎3=3
 times. Then one of the optimal solution will be as follows:

the headquarters is located in 𝑥0=2
;
𝑥1=4
: Divan will spend 2⋅|𝑥0−𝑥1|⋅𝑎1=2⋅|2−4|⋅1=4
 minutes walking to the first building;
𝑥2=1
: Divan will spend 2⋅|𝑥0−𝑥2|⋅𝑎2=2⋅|2−1|⋅2=4
 minutes walking to the second building;
𝑥3=3
: Divan will spend 2⋅|𝑥0−𝑥3|⋅𝑎3=2⋅|2−3|⋅3=6
 minutes walking to the third building.
In total, Divan will spend 4+4+6=14
 minutes. It can be shown that it is impossible to arrange buildings so that the
businessman spends less time.

Among others, 𝑥=[1,3,2,0]
, 𝑥=[−5,−3,−6,−4]
 are also correct answers for the first example.
*/

/*testcase:
    An integer n
    Then n integers, stored in v[i].first
    Each paired with its original 1-based index in v[i].second = i + 1

sort by value in descending order

looks like:
v[0] = (largest_value, original_index)
v[1] = (2nd_largest_value, original_index)
v[2] = (3rd_largest_value, original_index)
...

a. dist = i / 2 + 1
If i starts from 0:
dist alternates: two elements per “radius level”.

b. pos = (i % 2) ? dist : -dist
This alternates sign:

So the placement pattern is symmetrical around 0, alternating left-right,
outward.


total += 2 * num * dist;

cout << total << "\n";
for (ll i = 0; i <= n; i++)
    cout << res[i] << " ";
cout << "\n";

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
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++) {
      cin >> v[i].first;
      v[i].second = i + 1;
    }

    sort(v.rbegin(), v.rend());

    ll total = 0;
    vector<ll> res(n + 1, 0);
    for (ll i = 0; i < n; i++) {
      ll num = v[i].first;
      ll idx = v[i].second;
      ll dist = i / 2 + 1;
      total += 2 * num * dist;
      ll pos = (i % 2) ? dist : -dist;
      res[idx] = pos;
    }

    cout << total << "\n";
    for (ll i = 0; i <= n; i++) {
      cout << res[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1614/341993630
