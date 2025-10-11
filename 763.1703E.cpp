/*E. Mirror Grid
time limit per test2 seconds
memory limit per test256 megabytes
You are given a square grid with 𝑛
 rows and 𝑛
 columns. Each cell contains either 0
 or 1
.

In an operation, you can select a cell of the grid and flip it (from 0→1
 or 1→0
). Find the minimum number of operations you need to obtain a square that
remains the same when rotated 0∘ , 90∘ , 180∘ and 270∘
.

The picture below shows an example of all rotations of a grid.


Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the size of the grid.

Then 𝑛
 lines follow, each with 𝑛
 characters 𝑎𝑖,𝑗
 (0≤𝑎𝑖,𝑗≤1
) — the number written in each cell.

Output
For each test case output a single integer  — the minimum number of operations
needed to make the square look the same rotated 0∘ , 90∘ , 180∘ and 270∘
.

Example
InputCopy
5
3
010
110
010
1
0
5
11100
11011
01011
10011
11000
5
01000
10101
01010
00010
01001
5
11001
00000
11111
10110
01111
OutputCopy
1
0
9
7
6
Note
In the first test case, we can perform one operations to make the grid 010111010
. Now, all rotations of the square are the same.

In the second test case, all rotations of the square are already the same, so we
don't need any flips.
*/

#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (long p = 0; p < n; p++) {
      std::cin >> v[p];
    }
    long total(0);
    for (long row = 0; row < n / 2; row++) {
      for (long col = row; col < n - 1 - row; col++) {
        char a = v[row][col];
        char b = v[col][n - 1 - row];
        char c = v[n - 1 - row][n - 1 - col];
        char d = v[n - 1 - col][row];
        int cntZ = (a == '1') + (b == '1') + (c == '1') + (d == '1');
        int cntA = (a == '0') + (b == '0') + (c == '0') + (d == '0');
        total += (cntZ < cntA ? cntZ : cntA);
      }
    }

    std::cout << total << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1703/343073962
