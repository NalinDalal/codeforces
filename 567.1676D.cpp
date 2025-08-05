/*D. X-Sum
time limit per test2 seconds
memory limit per test256 megabytes
Timur's grandfather gifted him a chessboard to practice his chess skills. This
chessboard is a grid 𝑎 with 𝑛 rows and 𝑚 columns with each cell having a
non-negative integer written on it.

Timur's challenge is to place a bishop on the board such that the sum of all
cells attacked by the bishop is maximal. The bishop attacks in all directions
diagonally, and there is no limit to the distance which the bishop can attack.
Note that the cell on which the bishop is placed is also considered attacked.
Help him find the maximal sum he can get.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. The description of test cases follows.

The first line of each test case contains the integers 𝑛
 and 𝑚
 (1≤𝑛≤200
, 1≤𝑚≤200
).

The following 𝑛
 lines contain 𝑚
 integers each, the 𝑗
-th element of the 𝑖
-th line 𝑎𝑖𝑗
 is the number written in the 𝑗
-th cell of the 𝑖
-th row (0≤𝑎𝑖𝑗≤106)

It is guaranteed that the sum of 𝑛⋅𝑚
 over all test cases does not exceed 4⋅104
.

Output
For each test case output a single integer, the maximum sum over all possible
placements of the bishop.

Example
InputCopy
4
4 4
1 2 2 1
2 4 2 4
2 2 3 1
2 4 2 4
2 1
1
0
3 3
1 1 1
1 1 1
1 1 1
3 3
0 1 1
1 0 1
1 1 0
OutputCopy
20
1
5
3
Note
For the first test case here the best sum is achieved by the bishop being in
this position:
*/

#include <iostream>
#include <map>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<long>> f(n, std::vector<long>(m));
    std::map<long, long> s, d;

    // Input and populate diagonals
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        std::cin >> f[row][col];
        s[row + col] += f[row][col]; // main diagonal (↘)
        d[row - col] += f[row][col]; // anti-diagonal (↙)
      }
    }

    long res = 0;
    // Try each cell as center
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        long cand = s[row + col] + d[row - col] - f[row][col];
        res = std::max(res, cand);
      }
    }

    std::cout << res << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1676/332448897
