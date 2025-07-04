/*B. Good Start
time limit per test1 second
memory limit per test256 megabytes
The roof is a rectangle of size 𝑤×ℎ
 with the bottom left corner at the point (0,0)
 on the plane. Your team needs to completely cover this roof with identical
roofing sheets of size 𝑎×𝑏 , with the following conditions:

The sheets cannot be rotated (not even by 90∘
).
The sheets must not overlap (but they can touch at the edges).
The sheets can extend beyond the boundaries of the rectangular roof.
A novice from your team has already placed two such sheets on the roof in such a
way that the sheets do not overlap and each of them partially covers the roof.

Your task is to determine whether it is possible to completely tile the roof
without removing either of the two already placed sheets.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains four integers 𝑤
, ℎ
, 𝑎
, and 𝑏
 (1≤𝑤,ℎ,𝑎,𝑏≤109
) — the dimensions of the roof and the dimensions of the roofing sheets,
respectively.

The second line of each test case contains four integers 𝑥1
, 𝑦1
, 𝑥2
, and 𝑦2
 (−𝑎+1≤𝑥1,𝑥2≤𝑤−1,−𝑏+1≤𝑦1,𝑦2≤ℎ−1
) — the coordinates of the bottom left corners of the already placed roofing
sheets. It is guaranteed that these sheets do not overlap.

Output
For each test case, output "Yes" (without quotes) if it is possible to
completely tile the roof without removing either of the two already placed
tiles, and "No" (without quotes) otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
7
6 5 2 3
-1 -2 5 4
4 4 2 2
0 0 3 1
10 9 3 2
0 0 4 3
10 9 3 2
0 0 6 3
5 5 2 2
-1 -1 4 -1
5 5 2 2
-1 -1 2 3
7 8 2 4
0 0 0 5
OutputCopy
Yes
No
No
Yes
No
Yes
No
Note
In the first test case, it is possible to add 8
 roofing sheets as follows:


In the second test case, it is impossible to completely tile the roof:
*/

#include <iostream>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long w, h, a, b;
    std::cin >> w >> h >> a >> b;
    long x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2) {
      std::cout << ((y1 - y2) % b ? "No" : "Yes") << std::endl;
    } else if (y1 == y2) {
      std::cout << ((x1 - x2) % a ? "No" : "Yes") << std::endl;
    } else {
      std::cout << (((x1 - x2) % a) && ((y1 - y2) % b) ? "No" : "Yes")
                << std::endl;
    }
  }
}
// sub: https://codeforces.com/problemset/submission/2113/327380813
