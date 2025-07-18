/*B. Scale
time limit per test2 seconds
memory limit per test256 megabytes
Tina has a square grid with 𝑛
 rows and 𝑛
 columns. Each cell in the grid is either 0
 or 1
.

Tina wants to reduce the grid by a factor of 𝑘
 (𝑘
 is a divisor of 𝑛
). To do this, Tina splits the grid into 𝑘×𝑘
 nonoverlapping blocks of cells such that every cell belongs to exactly one
block.

Tina then replaces each block of cells with a single cell equal to the value of
the cells in the block. It is guaranteed that every cell in the same block has
the same value.

For example, the following demonstration shows a grid being reduced by factor of
3
.

Original grid
0
0
0
1
1
1
0
0
0
1
1
1
0
0
0
1
1
1
1
1
1
0
0
0
1
1
1
0
0
0
1
1
1
0
0
0
Reduced grid
0
1
1
0
Help Tina reduce the grid by a factor of 𝑘
.

Input
The first line contains 𝑡
 (1≤𝑡≤100
) – the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤1000
, 1≤𝑘≤𝑛
, 𝑘
 is a divisor of 𝑛
) — the number of rows and columns of the grid, and the factor that Tina wants
to reduce the grid by.

Each of the following 𝑛
 lines contain 𝑛
 characters describing the cells of the grid. Each character is either 0
 or 1
. It is guaranteed every 𝑘
 by 𝑘
 block has the same value.

It is guaranteed the sum of 𝑛
 over all test cases does not exceed 1000
.

Output
For each test case, output the grid reduced by a factor of 𝑘
 on a new line.

Example
InputCopy
4
4 4
0000
0000
0000
0000
6 3
000111
000111
000111
111000
111000
111000
6 2
001100
001100
111111
111111
110000
110000
8 1
11111111
11111111
11111111
11111111
11111111
11111111
11111111
11111111
OutputCopy
0
01
10
010
111
100
11111111
11111111
11111111
11111111
11111111
11111111
11111111
11111111
*/

#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n, k;
    std::cin >> n >> k;
    std::vector<std::string> v(n);
    for (long p = 0; p < n; p++) {
      std::cin >> v[p];
    }
    std::vector<std::string> w(n / k, std::string(n / k, '0'));
    for (long row = 0; row < n; row += k) {
      for (long col = 0; col < n; col += k) {
        w[row / k][col / k] = v[row][col];
      }
    }

    for (long p = 0; p < w.size(); p++) {
      std::cout << w[p] << std::endl;
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1996/329584752
