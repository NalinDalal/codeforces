/*B. Deadly Laser
time limit per test2 seconds
memory limit per test256 megabytes
The robot is placed in the top left corner of a grid, consisting of 𝑛
 rows and 𝑚
 columns, in a cell (1,1)
.

In one step, it can move into a cell, adjacent by a side to the current one:

(𝑥,𝑦)→(𝑥,𝑦+1)
;
(𝑥,𝑦)→(𝑥+1,𝑦)
;
(𝑥,𝑦)→(𝑥,𝑦−1)
;
(𝑥,𝑦)→(𝑥−1,𝑦)
.
The robot can't move outside the grid.

The cell (𝑠𝑥,𝑠𝑦)
 contains a deadly laser. If the robot comes into some cell that has distance
less than or equal to 𝑑 to the laser, it gets evaporated. The distance between
two cells (𝑥1,𝑦1) and (𝑥2,𝑦2) is |𝑥1−𝑥2|+|𝑦1−𝑦2|
.

Print the smallest number of steps that the robot can take to reach the cell
(𝑛,𝑚) without getting evaporated or moving outside the grid. If it's not
possible to reach the cell (𝑛,𝑚) , print -1.

The laser is neither in the starting cell, nor in the ending cell. The starting
cell always has distance greater than 𝑑 to the laser.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

The only line of each testcase contains five integers 𝑛,𝑚,𝑠𝑥,𝑠𝑦,𝑑
 (2≤𝑛,𝑚≤1000
; 1≤𝑠𝑥≤𝑛
; 1≤𝑠𝑦≤𝑚
; 0≤𝑑≤𝑛+𝑚
) — the size of the grid, the cell that contains the laser and the evaporating
distance of the laser.

The laser is neither in the starting cell, nor in the ending cell ((𝑠𝑥,𝑠𝑦)≠(1,1)
 and (𝑠𝑥,𝑠𝑦)≠(𝑛,𝑚)
). The starting cell (1,1)
 always has distance greater than 𝑑
 to the laser (|𝑠𝑥−1|+|𝑠𝑦−1|>𝑑
).

Output
For each testcase, print a single integer. If it's possible to reach the cell
(𝑛,𝑚) from (1,1) without getting evaporated or moving outside the grid, then
print the smallest amount of steps it can take the robot to reach it. Otherwise,
print -1.

Example
InputCopy
3
2 3 1 3 0
2 3 1 3 1
5 5 3 4 1
OutputCopy
3
-1
8


*/

/*Grid of size n × m. Start at (1,1), goal (n,m).

There’s a laser at (sx, sy) that kills any cell within Manhattan distance ≤ d.

You want the shortest path length from (1,1) → (n,m).

If impossible (laser blocks all routes), output -1.

2 routes: right+down{(1,1) to (1,n) to (n,n)}, down+right{(1,1) to (n,1) to
(n,n)}


If the laser blocks both routes, there’s no way to reach (n,m).
If at least one route survives, the answer is the natural shortest distance: n +
m - 2.

route blocking:
    - If laser blocks row 1 or column 1 completely, you can’t start.
        - (sx - 1) <= d → column 1 blocked from top
        - (sy - 1) <= d → row 1 blocked from left

    - If laser blocks row n or column m completely, you can’t finish.
        - (n - sx) <= d → column m blocked from bottom
        - (m - sy) <= d → row n blocked from right

corridor clearance: bool res = (u > d) || (v > d);

If both routes are blocked, output -1.

Otherwise, output n + m - 2.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;

    long bl = sx - 1, br = m - sy;
    long u = min(bl, br);

    bl = n - sx;
    br = sy - 1;
    long v = min(bl, br);

    bool ok = (u > d) || (v > d);
    cout << (ok ? (n + m - 2) : -1) << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1721/335235466
