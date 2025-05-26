/*A. Phone Desktop
time limit per test1 second
memory limit per test256 megabytes
Little Rosie has a phone with a desktop (or launcher, as it is also called). The
desktop can consist of several screens. Each screen is represented as a grid of
size 5×3 , i.e., five rows and three columns.

There are 𝑥
 applications with an icon size of 1×1
 cells; such an icon occupies only one cell of the screen. There are also 𝑦
 applications with an icon size of 2×2
 cells; such an icon occupies a square of 4
 cells on the screen. Each cell of each screen can be occupied by no more than
one icon.

Rosie wants to place the application icons on the minimum number of screens.
Help her find the minimum number of screens needed.

Input
The first line of the input contains 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first and only line of each test case contains two integers 𝑥
 and 𝑦
 (0≤𝑥,𝑦≤99
) — the number of applications with a 1×1
 icon and the number of applications with a 2×2
 icon, respectively.

Output
For each test case, output the minimal number of required screens on a separate
line.

Example
InputCopy
11
1 1
7 2
12 4
0 3
1 0
8 1
0 0
2 0
15 0
8 2
0 9
OutputCopy
1
1
2
2
1
1
0
1
1
2
5
Note
The solution for the first test case can look as follows:

Blue squares represent empty spaces for icons, green squares represent 1×1
 icons, red squares represent 2×2
 icons
The solution for the third test case can look as follows:
*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int x, y;
    std::cin >> x >> y;
    int z = (y + 1) / 2;
    x -= (15 * z - 4 * y);
    x = (x > 0 ? x : 0);
    z += (x + 14) / 15;
    std::cout << z << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1974/321323935
