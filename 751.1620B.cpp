/*B. Triangles on a Rectangle
time limit per test2 seconds
memory limit per test256 megabytes
A rectangle with its opposite corners in (0,0)
 and (𝑤,ℎ)
 and sides parallel to the axes is drawn on a plane.

You are given a list of lattice points such that each point lies on a side of a
rectangle but not in its corner. Also, there are at least two points on every
side of a rectangle.

Your task is to choose three points in such a way that:

exactly two of them belong to the same side of a rectangle;
the area of a triangle formed by them is maximum possible.
Print the doubled area of this triangle. It can be shown that the doubled area
of any triangle formed by lattice points is always an integer.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

The first line of each testcase contains two integers 𝑤
 and ℎ
 (3≤𝑤,ℎ≤106
) — the coordinates of the corner of a rectangle.

The next two lines contain the description of the points on two horizontal
sides. First, an integer 𝑘 (2≤𝑘≤2⋅105 ) — the number of points. Then, 𝑘 integers
𝑥1<𝑥2<⋯<𝑥𝑘 (0<𝑥𝑖<𝑤 ) — the 𝑥 coordinates of the points in the ascending order.
The 𝑦 coordinate for the first line is 0 and for the second line is ℎ
.

The next two lines contain the description of the points on two vertical sides.
First, an integer 𝑘 (2≤𝑘≤2⋅105 ) — the number of points. Then, 𝑘 integers
𝑦1<𝑦2<⋯<𝑦𝑘 (0<𝑦𝑖<ℎ ) — the 𝑦 coordinates of the points in the ascending order.
The 𝑥 coordinate for the first line is 0 and for the second line is 𝑤
.

The total number of points on all sides in all testcases doesn't exceed 2⋅105
.

Output
For each testcase print a single integer — the doubled maximum area of a
triangle formed by such three points that exactly two of them belong to the same
side.

Example
InputCopy
3
5 8
2 1 2
3 2 3 4
3 1 4 6
2 4 5
10 7
2 3 9
2 1 7
3 1 3 4
3 4 5 6
11 5
3 1 6 8
3 3 6 8
3 1 3 4
2 2 4
OutputCopy
25
42
35
Note
The points in the first testcase of the example:

(1,0)
, (2,0)
;
(2,8)
, (3,8)
, (4,8)
;
(0,1)
, (0,4)
, (0,6)
;
(5,4)
, (5,5)
.
The largest triangle is formed by points (0,1)
, (0,6)
 and (5,4)
 — its area is 252
. Thus, the doubled area is 25
. Two points that are on the same side are: (0,1)
 and (0,6)
.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    ll w, h;
    cin >> w >> h;

    ll k, left, right, width = 0;

    // bottom edge
    cin >> k;
    cin >> left;
    for (ll i = 1; i < k; i++) {
      cin >> right;
    }
    width = right - left;

    // top edge
    cin >> k;
    cin >> left;
    for (ll i = 1; i < k; i++) {
      cin >> right;
      width = max(width, right - left);
    }

    ll res = width * h;

    ll bottom, top, height = 0;

    // left edge
    cin >> k;
    cin >> bottom;
    for (ll i = 1; i < k; i++) {
      cin >> top;
    }
    height = top - bottom;

    // right edge
    cin >> k;
    cin >> bottom;
    for (ll i = 1; i < k; i++) {
      cin >> top;
      height = max(height, top - bottom);
    }

    res = max(res, height * w);

    cout << res << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1620/342413936
