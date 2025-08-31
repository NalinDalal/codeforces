/*C. Not Adjacent Matrix
time limit per test4 seconds
memory limit per test256 megabytes
We will consider the numbers 𝑎
 and 𝑏
 as adjacent if they differ by exactly one, that is, |𝑎−𝑏|=1
.

We will consider cells of a square matrix 𝑛×𝑛
 as adjacent if they have a common side, that is, for cell (𝑟,𝑐)
 cells (𝑟,𝑐−1)
, (𝑟,𝑐+1)
, (𝑟−1,𝑐)
 and (𝑟+1,𝑐)
 are adjacent to it.

For a given number 𝑛
, construct a square matrix 𝑛×𝑛
 such that:

Each integer from 1
 to 𝑛2
 occurs in this matrix exactly once;
If (𝑟1,𝑐1)
 and (𝑟2,𝑐2)
 are adjacent cells, then the numbers written in them must not be adjacent.
Input
The first line contains one integer 𝑡
 (1≤𝑡≤100
). Then 𝑡
 test cases follow.

Each test case is characterized by one integer 𝑛
 (1≤𝑛≤100
).

Output
For each test case, output:

-1, if the required matrix does not exist;
the required matrix, otherwise (any such matrix if many of them exist).
The matrix should be outputted as 𝑛
 lines, where each line contains 𝑛
 integers.

Example
InputCopy
3
1
2
3
OutputCopy
1
-1
2 9 7
4 6 3
1 8 5
*/

/*Input n.

If n == 1 → just print 1.

If n == 2 → print -1 (no solution exists).

Otherwise, construct an n × n matrix filled with numbers 1 … n² in a special
order.

Split cells into two groups by parity of (row + col):
- "Even cells" → where (row + col) % 2 == 0.
- "Odd cells" → where (row + col) % 2 == 1.

*/

#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;

    if (n == 1) {
      std::cout << 1 << "\n";
      continue;
    } else if (n == 2) {
      std::cout << -1 << "\n";
      continue;
    }

    std::vector<std::vector<long>> res(n, std::vector<long>(n, 0));
    long cur = 1;

    for (long par = 0; par <= 1; par++) {
      for (long row = 0; row < n; row++) {
        for (long col = 0; col < n; col++) {
          if ((row + col) % 2 == par) {
            res[row][col] = cur++;
          }
        }
      }
    }

    for (long row = 0; row < n; row++) {
      for (long col = 0; col < n; col++) {
        std::cout << res[row][col] << " ";
      }
      std::cout << "\n";
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1520/336346559
