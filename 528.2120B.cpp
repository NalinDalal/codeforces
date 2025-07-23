/*B. Square Pool
time limit per test1 second
memory limit per test256 megabytes
Aryan and Harshith are playing pool in universe AX120 on a fixed square pool
table of side 𝑠 with pockets at its 4 corners. The corners are situated at (0,0)
, (0,𝑠)
, (𝑠,0)
, and (𝑠,𝑠)
. In this game variation, 𝑛
 identical balls are placed on the table with integral coordinates such that no
ball lies on the edge or corner of the table. Then, they are all simultaneously
shot at 10100 units/sec speed (only at 45 degrees with the axes).

In universe AX120, balls and pockets are almost point-sized, and the collisions
are elastic, i.e., the ball, on hitting any surface, bounces off at the same
angle and with the same speed.


Harshith shot the balls, and he provided Aryan with the balls' positions and the
angles at which he shot them. Help Aryan determine the number of balls potted
into the pockets by Harshith.

It is guaranteed that multiple collisions do not occur at the same moment and
position.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑠
 (1≤𝑛≤103
, 2≤𝑠≤109
) — the number of balls placed on the table and the side length of the square
pool table.

The 𝑖
-th of the next 𝑛
 lines contains four integers 𝑑𝑥
, 𝑑𝑦
, 𝑥𝑖
, and 𝑦𝑖
 (𝑑𝑥,𝑑𝑦∈{−1,1}
, 0<𝑥𝑖,𝑦𝑖<𝑠
) — the direction vectors of the launch on the 𝑋
-axis and 𝑌
-axis respectively, and the coordinates of the location where the 𝑖
-th ball was placed. It is guaranteed that no two balls coincide at the initial
moment.

It is also guaranteed that the sum of 𝑛
 over all test cases does not exceed 103
.

Output
For each test case, print a single integer — the number of balls potted in that
game.

Example
InputCopy
2
1 2
1 1 1 1
5 4
1 -1 1 1
1 -1 2 2
-1 1 2 3
1 -1 1 3
-1 1 3 1
OutputCopy
1
3
Note
In the first test case, there is a single ball and it's shot directly towards
the pocket at (2,2) , thus potted.

*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, s;
    std::cin >> n >> s;

    int total = 0;
    for (int p = 0; p < n; p++) {
      int dx, dy, x, y;
      std::cin >> dx >> dy >> x >> y;
      if (dx == dy) {
        total += (x == y);
      } else {
        total += (x + y == s);
      }
    }

    std::cout << total << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1944/330491951
