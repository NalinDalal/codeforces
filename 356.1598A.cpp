/* A. Computer Game
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp is playing a computer game. Now he wants to complete the first level of
this game.

A level is a rectangular grid of 2
 rows and 𝑛
 columns. Monocarp controls a character, which starts in cell (1,1)
 — at the intersection of the 1
-st row and the 1
-st column.

Monocarp's character can move from one cell to another in one step if the cells
are adjacent by side and/or corner. Formally, it is possible to move from cell
(𝑥1,𝑦1) to cell (𝑥2,𝑦2) in one step if |𝑥1−𝑥2|≤1 and |𝑦1−𝑦2|≤1 . Obviously, it
is prohibited to go outside the grid.

There are traps in some cells. If Monocarp's character finds himself in such a
cell, he dies, and the game ends.

To complete a level, Monocarp's character should reach cell (2,𝑛)
 — at the intersection of row 2
 and column 𝑛
.

Help Monocarp determine if it is possible to complete the level.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. Then the test cases follow. Each test case
consists of three lines.

The first line contains a single integer 𝑛
 (3≤𝑛≤100
) — the number of columns.

The next two lines describe the level. The 𝑖
-th of these lines describes the 𝑖
-th line of the level — the line consists of the characters '0' and '1'. The
character '0' corresponds to a safe cell, the character '1' corresponds to a
trap cell.

Additional constraint on the input: cells (1,1)
 and (2,𝑛)
 are safe.

Output
For each test case, output YES if it is possible to complete the level, and NO
otherwise.

Example
InputCopy
4
3
000
000
4
0011
1100
4
0111
1110
6
010101
101010
OutputCopy
YES
YES
NO
YES
Note
Consider the example from the statement.

In the first test case, one of the possible paths is (1,1)→(2,2)→(2,3)
.

In the second test case, one of the possible paths is (1,1)→(1,2)→(2,3)→(2,4)
.

In the fourth test case, one of the possible paths is
(1,1)→(2,2)→(1,3)→(2,4)→(1,5)→(2,6)
.


*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool possible = true;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        possible = false;
        break;
      }
    }
    cout << (possible ? "YES" : "NO") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1598/320300254
