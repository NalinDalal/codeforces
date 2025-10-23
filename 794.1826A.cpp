/*A. Trust Nobody
time limit per test1 second
memory limit per test256 megabytes
There is a group of 𝑛
 people. Some of them might be liars, who always tell lies. Other people always
tell the truth. The 𝑖 -th person says "There are at least 𝑙𝑖 liars amongst us".
Determine if what people are saying is contradictory, or if it is possible. If
it is possible, output the number of liars in the group. If there are multiple
possible answers, output any one of them.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
).

The second line of each test case contains 𝑛
 integers 𝑙𝑖
 (0≤𝑙𝑖≤𝑛
) — the number said by the 𝑖
-th person.

It's guaranteed that the sum of all 𝑛
 does not exceed 104
.

Output
For each test case output a single integer. If what people are saying is
contradictory, output −1 . Otherwise, output the number of liars in the group.
If there are multiple possible answers, output any one of them.

Example
InputCopy
7
2
1 2
2
2 2
2
0 0
1
1
1
0
5
5 5 3 3 5
6
5 3 6 6 3 5
OutputCopy
1
-1
0
-1
0
3
4
Note
In the first example, the only possible answer is that the second person is a
liar, so the answer is 1 liar.

In the second example, it can be proven that we can't choose the liars so that
all the requirements are satisfied.

In the third example, everybody tells the truth, so the answer is 0
 liars.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = -1;

    // If the smallest element > n, all elements > n, so answer = n
    if (a[0] > n) {
      ans = n;
    }

    // Otherwise, find the maximum "k" such that a[i] <= n - i - 1
    for (int i = 0; i < n; ++i) {
      if (a[i] <= n - i - 1) {
        if (i == n - 1 || a[i + 1] > n - i - 1) {
          ans = n - i - 1;
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1826/345304316
