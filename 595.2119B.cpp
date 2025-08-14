/*B. Line Segments
time limit per test1.5 seconds
memory limit per test256 megabytes
PIKASONIC - Lost My Mind (feat.nakotanmaru)
You are given two points (𝑝𝑥,𝑝𝑦)
 and (𝑞𝑥,𝑞𝑦)
 on a Euclidean plane.

You start at the starting point (𝑝𝑥,𝑝𝑦)
 and will perform 𝑛
 operations. In the 𝑖
-th operation, you must choose any point such that the Euclidean distance∗
 between your current position and the point is exactly 𝑎𝑖
, and then move to that point.

Determine whether it is possible to reach the terminal point (𝑞𝑥,𝑞𝑦)
 after performing all operations.

∗
The Euclidean distance between (𝑥1,𝑦1)
 and (𝑥2,𝑦2)
 is (𝑥1−𝑥2)2+(𝑦1−𝑦2)2‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾√

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤103
) — the length of the sequence 𝑎
.

The second line of each test case contains four integers 𝑝𝑥,𝑝𝑦,𝑞𝑥,𝑞𝑦
 (1≤𝑝𝑥,𝑝𝑦,𝑞𝑥,𝑞𝑦≤107
) — the coordinates of the starting point and terminal point.

The third line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤104
) — the distance to move in each operation.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "Yes" if it is possible to reach the terminal point
(𝑞𝑥,𝑞𝑦) after all operations; otherwise, output "No".

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
5
2
1 1 5 1
3 3
3
1 1 3 3
2 3 4
2
100 100 100 100
4 5
1
5 1 1 4
5
2
10000000 10000000 10000000 10000000
10000 10000
OutputCopy
Yes
Yes
No
Yes
Yes
Note
Here is a picture that shows a possible movement of the first test case. The
coordinates of point 𝑟1 are (3,1+5‾√)
.

The first test case.
Here is a picture that shows a possible movement of the second test case. The
coordinates of point 𝑟1 are (1+3‾√,0) , and the coordinates of point 𝑟2 are
(−(3√+4)(33(149−243√)√−73√−38)104,−3(1331−7643√)√+123√−27104)
.

The second test case.
For the third test case, it can be shown that there is no set of moves that
satisfies all requirements.

Here is a picture that shows a possible movement of the fourth test case.

The fourth test case.
*/

#include <algorithm>
#include <cmath>
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
    ll n;
    cin >> n;

    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    vector<double> a(n + 1);
    for (ll p = 0; p < n; p++) {
      cin >> a[p];
    }

    a[n] = sqrt((sx - tx) * (sx - tx) + (sy - ty) * (sy - ty));

    sort(a.begin(), a.end());

    double s = a.back();
    for (ll p = 0; p < n; p++) {
      s -= a[p];
    }

    cout << (s > 0 ? "No" : "Yes") << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2119/333870524
