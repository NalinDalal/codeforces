/*B. Corner Twist
time limit per test1 second
memory limit per test256 megabytes
You are given two grids of numbers 𝑎
 and 𝑏
, with 𝑛
 rows and 𝑚
 columns. All the values in the grid are 0
, 1
 or 2
.

You can perform the following operation on 𝑎
 any number of times:

Pick any subrectangle in the grid with length and width ≥2
. You are allowed to choose the entire grid as a subrectangle.
The subrectangle has four corners. Take any pair of diagonally opposite corners
of the chosen subrectangle and add 1 to their values modulo 3
.
For the pair of corners not picked, add 2
 to their values modulo 3
.
Note that the operation only changes the values of the corners of the picked
subrectangle.

Is it possible to convert the grid 𝑎
 into grid 𝑏
 by applying the above operation any number of times (possibly zero)?

Input
The first line contains an integer 𝑡
, the number of testcases (1≤𝑡≤250
).

For each testcase:

The first line contains two integers 𝑛
 and 𝑚
, the number of rows and columns in the grid (2≤𝑛,𝑚≤500
).

Each of the next n lines contain m characters — the 𝑗
-th character of the 𝑖
-th line represents 𝑎𝑖,𝑗
.

Each of the next n lines contain m characters — the 𝑗
-th character of the 𝑖
-th line represents 𝑏𝑖,𝑗
 (0≤𝑎𝑖,𝑗,𝑏𝑖,𝑗≤2
).

It is guaranteed that the sum of 𝑛
 over all test cases and the sum of 𝑚
 over all test cases do not exceed 500
.

Output
For each test case print "YES" (without quotes) if it is possible to convert
grid 𝑎 into grid 𝑏 and "NO" (without quotes) otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
7
3 3
000
000
000
111
111
111
4 4
0000
0000
0000
0000
2100
1200
0012
0021
4 4
1020
1200
1210
0000
0000
1200
2200
0000
3 3
012
012
012
010
111
011
8 8
00000000
00000000
00000000
00000000
00000000
00000000
00000000
10000000
00000000
01200000
02010000
00102000
00020100
00001020
00000210
10000000
2 7
0000000
0000000
2220111
0111222
2 7
0000000
0100010
2220111
1210202
OutputCopy
YES
YES
YES
NO
YES
NO
YES
Note
In the first testcase, grid 𝑎
 can be converted into 𝑏
 in the following manner:

000000000⇒102000201⇒102012222⇒111000222⇒111102120⇒111111111

Here, in each operation, the top-right and bottom-left corners highlighted by a
box are incremented by 2 modulo 3 , while the top-left and bottom-right corners
are incremented by 1 modulo 3
.

In the fourth testcase, it can be proven that it is not possible to convert grid
𝑎 into grid 𝑏 using the above-mentioned operations any number of times.
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
const ll inf = 1e9;
const ll linf = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> bad(n, vector<int>(m)), good(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char x;
        cin >> x;
        bad[i][j] = x - '0';
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char x;
        cin >> x;
        good[i][j] = x - '0';
      }
    }
    for (int i = 0; i + 1 < n; i++) {
      for (int j = 0; j + 1 < m; j++) {
        int cnt = 0;
        while (bad[i][j] != good[i][j]) {
          bad[i][j] += 1;
          bad[i][j] %= 3;
          bad[i + 1][j + 1] += 1;
          bad[i + 1][j + 1] %= 3;
          cnt++;
        }
        bad[i][j + 1] += cnt * 2;
        bad[i][j + 1] %= 3;
        bad[i + 1][j] += cnt * 2;
        bad[i + 1][j] %= 3;
      }
    }
    // debug(bad);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      bad[i][m - 1] %= 3;
      ok &= (good[i][m - 1] == bad[i][m - 1]);
    }
    for (int j = 0; j < m; j++) {
      bad[n - 1][j] %= 3;
      ok &= (good[n - 1][j] == bad[n - 1][j]);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1983/344183965
