/*A. Distinct Buttons
time limit per test1 second
memory limit per test256 megabytes
Deemo - Entrance
⠀
You are located at the point (0,0)
 of an infinite Cartesian plane. You have a controller with 4
 buttons which can perform one of the following operations:

𝚄
: move from (𝑥,𝑦)
 to (𝑥,𝑦+1)
;
𝚁
: move from (𝑥,𝑦)
 to (𝑥+1,𝑦)
;
𝙳
: move from (𝑥,𝑦)
 to (𝑥,𝑦−1)
;
𝙻
: move from (𝑥,𝑦)
 to (𝑥−1,𝑦)
.
Unfortunately, the controller is broken. If you press all the 4
 buttons (in any order), the controller stops working. It means that, during the
whole trip, you can only press at most 3 distinct buttons (any number of times,
in any order).

There are 𝑛
 special points in the plane, with integer coordinates (𝑥𝑖,𝑦𝑖)
.

Can you visit all the special points (in any order) without breaking the
controller?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the number of special points.

Each of the next 𝑛
 lines contains two integers 𝑥𝑖
, 𝑦𝑖
 (−100≤𝑥𝑖,𝑦𝑖≤100
), which represent the special point (𝑥𝑖,𝑦𝑖)
.

Note that there are no constraints on the sum of 𝑛
 over all test cases.

Output
For each test case, output "YES" (without quotes), if you can reach all the
special points without breaking the controller, and "NO" (without quotes)
otherwise.

You may output each letter in any case (for example, "YES", "Yes", "yes", "yEs"
will all be recognized as positive answer).

Example
InputCopy
6
3
1 -1
0 0
1 -1
4
-3 -2
-3 -1
-3 0
-3 1
4
1 1
-1 -1
1 -1
-1 1
6
-4 14
-9 -13
-14 5
14 15
-8 -4
19 9
6
82 64
39 91
3 46
87 83
74 21
7 25
1
100 -100
OutputCopy
YES
YES
NO
NO
YES
YES
Note
In the first test case, you can move as follows:

you start from (0,0)
;
you visit the special point (𝑥2,𝑦2)=(0,0)
;
you press 𝚁
, and you move from (0,0)
 to (1,0)
;
you press 𝙳
, and you move from (1,0)
 to (1,−1)
;
you visit the special point (𝑥1,𝑦1)=(1,−1)
;
you visit the special point (𝑥3,𝑦3)=(1,−1)
.
Therefore, you can visit all the special points using only the buttons 𝚁
, 𝙳
, so the controller does not break.

Note that the special points may coincide.

In the second test case, you can show that you can visit all the special points
using only the buttons 𝚄 , 𝙳 , 𝙻
.

In the third test case, you can show that you must press all the buttons (𝚄
, 𝚁
, 𝙳
, 𝙻
) to visit all the points, so the controller would break.

*/

#include <iostream>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    // now start from (0,0), move to (x,y)
    // well you can use only 3 options(any no of times),
    // options: (x,y+1),(x+1,y),(x,y-1),(x-1,y)
    // so if you can visit all points using these options, return YES
    // else return NO
    /*For each test case:

        Track 4 flags: needR, needL, needU, needD.

        Iterate over all points, set flags accordingly.

Count how many flags are true.

If count == 4 → print "NO". Else → "YES".
    */
    int n;
    cin >> n;
    bool needR = false, needL = false, needU = false, needD = false;

    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      if (x > 0)
        needR = true;
      if (x < 0)
        needL = true;
      if (y > 0)
        needU = true;
      if (y < 0)
        needD = true;
    }

    int cnt = needR + needL + needU + needD;
    if (cnt == 4)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1909/334331212
