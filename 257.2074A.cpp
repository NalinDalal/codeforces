/*A. Draw a Square
time limit per test1 second
memory limit per test256 megabytes
The pink soldiers have given you 4
 distinct points on the plane. The 4
 points' coordinates are (−𝑙,0)
, (𝑟,0)
, (0,−𝑑)
, (0,𝑢)
 correspondingly, where 𝑙
, 𝑟
, 𝑑
, 𝑢
 are positive integers.

In the diagram, a square is drawn by connecting the four points 𝐿
, 𝑅
, 𝐷
, 𝑈
.
Please determine if it is possible to draw a square∗
 with the given points as its vertices.

∗
A square is defined as a polygon consisting of 4
 vertices, of which all sides have equal length and all inner angles are equal.
No two edges of the polygon may intersect each other.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains four integers 𝑙
, 𝑟
, 𝑑
, 𝑢
 (1≤𝑙,𝑟,𝑑,𝑢≤10
).

Output
For each test case, if you can draw a square using the four points, output
"Yes". Otherwise, output "No".

You can output the answer in any case. For example, the strings "yEs", "yes",
and "YES" will also be recognized as positive responses.

Example
InputCopy
2
2 2 2 2
1 2 3 4
OutputCopy
Yes
No
Note
On the first test case, the four given points form a square, so the answer is
"Yes".

On the second test case, the four given points do not form a square, so the
answer is "No".
*/
#include <iostream>

bool square(int l, int r, int d, int u) {
  if (l == r && l == d && d == u)
    return true;
  else
    return false;
}
// if l==r,l==d and d==u then it is a square
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int l, r, d, u;
    std::cin >> l >> r >> d >> u;
    if (square(l, r, d, u))
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2074/312066148
