/* https://codeforces.com/problemset/problem/1873/C
C. Target Practice
time limit per test1 second
memory limit per test256 megabytes
A 10×10 target is made out of five "rings" as shown. Each ring has a different
point value: the outermost ring — 1 point, the next ring — 2 points, ..., the
center ring — 5 points.


Vlad fired several arrows at the target. Help him determine how many points he
got.

Input
The input consists of multiple test cases. The first line of the input contains
a single integer 𝑡 (1≤𝑡≤1000) — the number of test cases.

Each test case consists of 10 lines, each containing 10 characters. Each
character in the grid is either 𝚇 (representing an arrow) or . (representing no
arrow).

Output
For each test case, output a single integer — the total number of points of the
arrows.

Example
InputCopy
4
X.........
..........
.......X..
.....X....
......X...
..........
.........X
..X.......
..........
.........X
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
....X.....
..........
..........
..........
..........
..........
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
OutputCopy
17
0
5
220
Note
In the first test case, there are three arrows on the outer ring worth 1 point
each, two arrows on the ring worth 3 points each, and two arrows on the ring
worth 4 points each. The total score is 3×1+2×3+2×4=17.

In the second test case, there aren't any arrows, so the score is 0.



*/
#include <iostream>
#include <vector>

int main() {

  const int B = 10;
  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    std::vector<std::string> m(B);
    for (long p = 0; p < B; p++) {
      std::cin >> m[p];
    }

    long total(0);
    for (long row = 0; row < B; row++) {
      for (long col = 0; col < B; col++) {
        if (m[row][col] == '.') {
          continue;
        }
        long xrow = (row < B - 1 - row) ? row : (B - 1 - row);
        long xcol = (col < B - 1 - col) ? col : (B - 1 - col);
        long score = 1 + (xrow < xcol ? xrow : xcol);
        total += score;
      }
    }

    printf("%ld\n", total);
  }
}
