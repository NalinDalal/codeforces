/*B. Sasha and the Drawing
time limit per test1 second
memory limit per test256 megabytes
Even in kindergarten, Sasha liked a girl. Therefore, he wanted to give her a
drawing and attract her attention.

As a drawing, he decided to draw a square grid of size 𝑛×𝑛
, in which some cells are colored. But coloring the cells is difficult, so he
wants to color as few cells as possible. But at the same time, he wants at least
𝑘 diagonals to have at least one colored cell. Note that the square grid of size
𝑛×𝑛 has a total of 4𝑛−2 diagonals.

Help little Sasha to make the girl fall in love with him and tell him the
minimum number of cells he needs to color.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤1000 ) — the number of test cases. The description of the test
cases follows.

The only line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤108
, 1≤𝑘≤4𝑛−2
) — the size of the square grid and the minimum number of diagonals in which
there should be at least one colored cell.

Output
For each test case, output a single integer — the minimum number of cells that
need to be colored.

Example
InputCopy
7
3 4
3 3
3 10
3 9
4 7
7 11
2 3
OutputCopy
2
2
6
5
4
6
2
Note
In the pictures below, the colored cells are marked in black, and all diagonals
are marked in purple.

In the first test case, you can color 2
 cells so that 4
 diagonals contain at least one colored cell:


In the third test case, you can color 6
 cells so that all 10
 diagonals contain at least one colored cell:

*/
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long n, k;
    std::cin >> n >> k;
    long ans = 2 * n;
    if (k <= 4 * n - 4) {
      ans = (k + 1) / 2;
    } else if (k <= 4 * n - 3) {
      ans = 2 * n - 1;
    }
    std::cout << ans << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1929/333483009
