/*A. Distanced Coloring
time limit per test1 second
memory limit per test256 megabytes
You received an 𝑛×𝑚
 grid from a mysterious source. The source also gave you a magic positive
integer constant 𝑘
.

The source told you to color the grid with some colors, satisfying the following
condition:

If (𝑥1,𝑦1)
, (𝑥2,𝑦2)
 are two distinct cells with the same color, then max(|𝑥1−𝑥2|,|𝑦1−𝑦2|)≥𝑘
.
You don't like using too many colors. Please find the minimum number of colors
needed to color the grid.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The only line of each test case consists of three positive integers 𝑛
, 𝑚
, 𝑘
 (1≤𝑛,𝑚,𝑘≤104
) — the dimensions of the grid and the magic constant.

Output
For each test case, print a single integer — the minimum number of colors needed
to color the grid.

Example
InputCopy
6
3 3 2
5 1 10000
7 3 4
3 2 7
8 9 6
2 5 4
OutputCopy
4
5
12
6
36
8
Note
In the first test case, one of the optimal constructions is:


In the second test case, the color of all cells must be pairwise different, so
the answer is 5
.
*/
#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, m, k;
    std::cin >> n >> m >> k;

    int res = std::min(n, k) * std::min(m, k);
    std::cout << res << std::endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2002/326097153
